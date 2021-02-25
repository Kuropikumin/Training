/* lclnt_funcs1.c - ライセンスサーバのクライアント用関数 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h> // exit関数を利用する際に必要
#include <string.h> // strlen関数を利用するのに必要
#include <unistd.h> // getpid, gethostname, close関数を利用するのに必要

// 別ファイル(dgram.c)で定義されている関数
int make_dgram_client_socket();
int make_internet_address( char*, int, struct sockaddr_in* );

// ファイル全体を通して使われる重要関数
static        int       pid         = -1; // このプログラムのPID
static        int       sd          = -1; // 通信ソケット
static        int       have_ticket = 0;  // チケットを持っているときにセット
static struct sockaddr  serv_addr;        // サーバアドレス
static        socklen_t serv_alen;        // アドレスのサイズ
static        char      ticket_buf[128];  // チケットを保持するバッファ

#define MSGLEN         128
#define SERVER_PORTNUM 2020
#define HOSTLEN        512
#define oops( p ) { perror( p ); exit( 1 ); }

void syserr( char* msg1 )
{
    char buf[MSGLEN];

    sprintf( buf, "CLIENT [%d]: %s", pid, msg1 );
    perror( buf );
}

char* do_transaction( char* msg )
/* do_transaction()
 *   機能：サーバにリクエストを送り、応答を受け取る
 *   入力：msg_p 送信するメッセージ
 * 戻り値：メッセージ文字列を指すポインタか、エラーの場合は NULL
 *         注意：返されたポインタは性的メモリ領域を指しており、そのあとの呼び出しで上書きされる
 *   注意：セキュリティのために、retaddr と serv_addr を比較せよ
 */
{
    static        char      buf[MSGLEN];
           struct sockaddr  retaddr;
                  socklen_t addrlen;
                  int       ret;

    ret = sendto( sd, msg, strlen( msg ), 0, &serv_addr, serv_alen );
    if( ret == -1 ) {
        syserr( "sendto" );
        return NULL;
    }

    // 応答を取得する
    ret = recvfrom( sd, buf, MSGLEN, 0, &retaddr, &addrlen );
    if( ret == -1 ) {
        syserr( "recvfrom" );
        return NULL;
    }

    // メッセージ自体を返す
    return buf;
}

void setup()
/* setup()
 *   機能：PIDを取得し、ソケットを作って、ライセンスサーバのアドレスを取得する
 *   入力：引数無し
 * 戻り値：なし、エラーを起こすと強制終了
 *   注意：サーバがクライアントと同じホストにあることを前提としている
 */
{
    char hostname[BUFSIZ];

    pid = getpid();                   // チケット、メッセージ用
    sd  = make_dgram_client_socket(); // サーバとの通信用
    if( sd == -1 ) oops( "Cannot create socket" );

    gethostname( hostname, HOSTLEN );                               // 同じホストのサーバ
    make_internet_address( hostname, SERVER_PORTNUM, &serv_addr );
    serv_alen = sizeof( serv_addr );
}

void shut_down()
{
    close( sd );
}

void narrate( char* msg1, char* msg2 )
/* narrate()
 *   機能：デバック、デモ用に標準エラーにメッセージを書く
 *   入力：msg1, msg2 タイトル、PIDとともに出力される文字列
 * 戻り値：なし。エラーを起こすと強制終了
 */
{
    fprintf( stderr, "CLIENT [%d]: %s %s\n", pid, msg1, msg2 );
}

int get_ticket()
/* get_ticket()
 *   機能：ライセンスサーバからチケットを取得する
 * 戻り値：成功したときは 0、失敗したときは -1
 */
{
    char* response;
    char  buf[MSGLEN];

    if( have_ticket ) return( 0 ); // ほかにチケット使用者がいる場合の処理

    sprintf( buf, "HELO %d", pid ); // リクエストを組み立てる

    if( ( response = do_transaction( buf ) ) == NULL ) return ( -1 );

    // 応答を走査し、チケットが手に入ったかどうかを調べる
    //   成功時のメッセージは、TICK <チケット文字列>
    //   失敗時のメッセージは、FAIL <エラーメッセージ>
    if( strncmp( response, "TICK", 4 ) == 0 ) {
        strcpy( ticket_buf, response + 5 );  // チケットIDを取得する
        have_ticket = 1;                     // フラグをセットする
        narrate( "got ticket", ticket_buf );
        return( 0 );
    }

    if   ( strncmp( response, "FAIL", 4 ) == 0 ) narrate( "Could not get ticket", response );
    else                                         narrate( "Unknown message:", response );

    return ( -1 );
}

int release_ticket()
/* release_ticket()
 *   機能：チケットをサーバに返却する
 * 戻り値：成功したときは 0、失敗したら -1
 */
{
    char  buf[MSGLEN];
    char* response;

    if( !have_ticket ) return( 0 );  // チケットの使用者がいない場合はそのまま正常終了

    sprintf( buf, "GBYE %s", ticket_buf ); // メッセージを組み立てる
    if( ( response = do_transaction( buf ) ) == NULL ) return -1;

    // 応答を走査する
    //   成功時のメッセージは、THNX <情報文字列>
    //   失敗時のメッセージは、FAIL <エラーメッセージ>
    if( strncmp( response, "THNX", 4 ) == 0 ) {
        narrate( "released ticket OK", "" );
        return 0;
    }

    if( strncmp( response, "FAIL", 4 ) == 0 ) narrate( "release failed",   response + 5 );
    else                                      narrate( "Unknown message:", response );

    return -1;
}

