/* lsrv_funcs2.c - ライセンスサーバ用関数 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <stdlib.h>    // atoi関数を利用するために必要
#include <string.h>    // strlen関数を利用するために必要
#include <arpa/inet.h> // inet_atoi関数を利用するために必要
#include <unistd.h>    // close関数を利用するために必要

#define SERVER_PORTNUM 2020 // サーバのポート番号
#define MSGLEN         128  // データグラムのサイズ
#define TICKET_AVAIL   0    // スロットは使用可能
#define MAXUSERS       3    // 同時実行できるユーザは3人まで
#define oops( x ) { perror( x ); exit( -1 ); }

// lserv_func1からの追加点
#define RECLAIM_INTERVAL 60

// 重要な変数
int ticket_array[MAXUSERS]; // チケット配列
int sd              = -1;   // ソケット
int num_tickets_out = 0;    // 発行済みチケットの数

// 別ファイルの関数
int make_dgram_server_socket( int );

void narrate( char* msg1, char* msg2, struct sockaddr_in* clientp )
/* narrate()
 *   機能：デバッグ、ロギングのためのメッセージ生成
 */
{
    fprintf( stderr, "\t\tSERVER: %s %s ", msg1, msg2 );
    if( clientp ) fprintf( stderr, "(%s:%d)", inet_ntoa( clientp->sin_addr ), ntohs( clientp->sin_port ) );
    putc( '\n', stderr );
}

char* do_hello( char* msg_p )
/* do_hello()
 *   機能：使えるチケットがあるときにチケットを渡す
 *   入力：msg_p クライアントから受け取ったメッセージ
 * 戻り値：返事を指すポインタ
 *         注意：返されたポインタは性的メモリ領域を指しており、その後の呼び出しで上書きされる
 */
{
           int  x;
    static char replybuf[MSGLEN];

    // 私用されているチケットがいっぱいなら チケットが使えないメッセージを返す
    if( num_tickets_out >= MAXUSERS ) return "FAIL no tickets available";

    // そうでなければ、フリーチケットを探してクライアントに渡す
    for( x = 0; x < MAXUSERS && ticket_array[x] != TICKET_AVAIL; x++ ) ;

    // 正当性チェック - 決して起きてはならないこと
    if( x == MAXUSERS ) {
        narrate( "database corrupt", "", NULL );
        return( "FAIL database corrupt" );
    }

    // フリーチケットが見つかった場合、ユーザの"名前" ( pid )を配列に書き込む
    // pid.slot という形式のチケットを生成する
    ticket_array[x] = atoi( msg_p + 5 ); // get pid in msg
    sprintf( replybuf, "TICK %d.%d", ticket_array[x], x );
    num_tickets_out++;
    return replybuf;
}

char* do_goodbye( char* msg_p )
/* do_goodbye( char* msg_p )
 *   機能：クライアントが返してきたチケットを受け取る
 *   入力：msg_p クライアントから受け取ったメッセージ
 * 戻り値：返事を指すポインタ
 *         注意：返されたポインタは性的メモリ領域を指しており、その後の呼び出しで上書きされる
 */
{
    int pid;  // チケットのコンポーネント
    int slot; // 同上

    // ユーザはチケットを返却しようとしている
    // まず、メッセージからチケットを抜き出さなければならない。
    // メッセージは次の形式になっている
    // GBYE pid.slot
    if( ( sscanf( ( msg_p + 5 ), "%d.%d", & pid, &slot ) != 2 ) ||
        ( ticket_array[slot] != pid ) ) {
        narrate( "Bogus ticket", msg_p + 5, NULL );
        return "FAIL invalid ticket";
    }

    // チケットは有効、開放する
    ticket_array[slot] = TICKET_AVAIL;
    num_tickets_out--;

    // 返事を送る
    return "THNX See ya!";
}

static char* do_validate( char* msg )
/* do_validate
 *   機能：クライアントのチケットの正当性をチェックする
 *   入力：msg_p クライアントから受信したメッセージ
 * 戻り値：返事を指すポインタ
 *   注意：返されたポインタは性的メモリ領域を指しており、その後の呼び出しで上書きされる
 */
{
    int pid;  // チケットのコンポーネント
    int slot;

    // メッセージは VALD pid.slot という形式になっている
    // 走査してチェックする
    if( sscanf( msg + 5, "%d.%d", &pid, &slot ) == 2 &&
        ticket_array[slot] == pid
      ) return ( "GOOD Valid ticket" );

    // 無効なチケット
    narrate( "Bogus ticket", msg + 5, NULL );
    return( "FAIL invalid ticket" );
}

void free_all_tickets()
{
    int i;
    for( i = 0; i < MAXUSERS; i++ ) ticket_array[i] = TICKET_AVAIL;
}

int setup()
/* setup()
 *   機能：ライセンスサーバを初期化する
 */
{
    sd = make_dgram_server_socket( SERVER_PORTNUM );
    if( sd == -1 ) oops( "make socket" );

    free_all_tickets();
    return sd;
}

void shut_down()
/* shut_down()
 *   機能：ライセンスサーバをクローズする
 */
{
    close( sd );
}

void handle_request( char* req, struct sockaddr_in* client, socklen_t addrlen )
/* handle_request( request, clientaddr, addrlen )
 *  リクエストが届いたときに、ここに分岐する
 */
{
    char* response;
    int   ret;

    // リクエストを処理して返事を組み立てる
    if     ( strncmp( req, "HELO", 4 ) == 0 ) response = do_hello( req );
    else if( strncmp( req, "GBYE", 4 ) == 0 ) response = do_goodbye( req );
    else if( strncmp( req, "VALD", 4 ) == 0 ) response = do_validate( req );
    else                                      response = "FAIL invalid request";

    // クライアントに返事を送る
    narrate( "SAID:", response, client );
    ret = sendto( sd, response, strlen( response )  , 0, ( struct sockaddr* )client, addrlen );
    if( ret == -1 ) perror( "SERVER send to failed" );
}

void ticket_reclaim()
/* ticket_reclaim
 *   機能：すべてのチケットをチェックし、死んだプロセスが抱えているチケットを回収する
 * 戻り値：なし
 */
{
    int  i;
    char tick[BUFSIZ];

    for( i = 0; i < MAXUSERS; i++ ){
        if( ( ticket_array[i] != TICKET_AVAIL )  &&
            ( kill( ticket_array[i], 0 ) == -1 ) &&
            ( errno == ESRCH )
          ) {
            // プロセスは死んでいるのでスロットを開放する
            sprintf( tick, "%d.%d", ticket_array[i], i );
            narrate( "freeing", tick, NULL );
            ticket_array[i] = TICKET_AVAIL;
            num_tickets_out--;
        }
    }
    alarm( RECLAIM_INTERVAL ); // アラームをリセットする
}
