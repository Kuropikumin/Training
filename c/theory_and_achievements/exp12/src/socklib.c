/* socklib.c
 *     目的：インターネットクライアント/サーバプログラムを作成する際に
 *           よく使用される関数を定義しておき、利便性を向上させる
 * 作成関数：
 *     int make_server_socket( portnum ) サーバソケットを返す。エラーの場合は -1 を返す
 *     int make_server_socket_q( portnum, backlog )
 *     int connect_to_server( char* hostname, int portnum ) 接続されたソケットを返す。エラーの場合は -1 を返す
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <strings.h>

#define HOSTLEN 256
#define BACKLOG 1

int make_server_socket_q( int portnum, int backlog )
{
    struct sockaddr_in saddr;             // アドレスを構築
    struct hostent*    hp;                // アドレスの一部
           char        hostname[HOSTLEN]; // ホスト名
           int         sock_id;           // ソケットID

    sock_id = socket( PF_INET, SOCK_STREAM, 0 ); // ソケットの取得
    if( sock_id == -1 ) return -1;               // エラー処理

    // アドレスを構築して、ソケットにバインドする
    bzero( ( void* )&saddr, sizeof( saddr ) ); // 構造体をクリアする
    gethostname( hostname, HOSTLEN );          // 実行するホスト名の取得
    hp = gethostbyname( hostname );            // ホスト情報を取得する

    bcopy( ( void* )hp->h_addr, ( void* )&saddr.sin_addr, hp->h_length ); // ホスト情報を設定
    saddr.sin_port = htons( portnum );                                    // ソケットポートを設定
    saddr.sin_family = AF_INET;                                           // アドレスファミリを設定
    // エラー処理
    if( bind( sock_id, (struct sockaddr* )&saddr, sizeof( saddr ) ) != 0 ) return -1;

    // ソケットを着信できる状態にする
    if( listen( sock_id, backlog ) != 0 ) return -1;

    return sock_id;  // ソケットIDを返す
}

int make_server_socket( int portnum )
{
    return make_server_socket_q( portnum, BACKLOG );
}

int connect_to_server( char* hostname, int portnum )
{
    struct sockaddr_in servadd; // 呼び出す番号
    struct hostent*    hp;      // 番号の取得に使用
           int         sock;

    // ステップ1：ソケットを作成する
    sock = socket( AF_INET, SOCK_STREAM, 0 ); // 回線の取得
    if( sock == -1 ) return -1;               // エラー処理

    // ステップ2：サーバに接続する
    bzero( &servadd, sizeof( servadd ) );                                     // アドレスを 0 クリアする
    hp = gethostbyname( hostname);                                            // ホストのIPアドレスを照合する
    if( hp == NULL ) return -1;                                               // エラー処理
    bcopy( hp->h_addr, ( struct sockaddr* )&servadd.sin_addr, hp->h_length ); // 取得した情報をコピーする
    servadd.sin_port   = htons( portnum );                                    // ポート番号の設定
    servadd.sin_family = AF_INET;                                             // ソケットタイプの設定

    // サーバへの接続および例外処理
    if( connect( sock, ( struct sockaddr* )&servadd, sizeof( servadd ) ) != 0 ) return -1;

    return sock; // ソケットIDを返す
}
