/* timeclnt.c - timeserv.c のクライアント
 *     使い方：timeclnt <ホスト名> <ポート番号>
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>  // exit関数を利用する際に必要
#include <unistd.h>  // read, write, close関数を利用する際に必要
#include <strings.h> // bcopy, bzero関数を利用する際に必要

#define oops( msg ) { perror( msg ); exit( 1 ); }

int main( int ac, char* av[] )
{
    struct sockaddr_in servadd;         // 呼び出す番号
    struct hostent*    hp;              // 番号の取得に使用
           int         sock_id;         // 回線ID
           int         sock_fd;         // ファイルディスク
           char        message[BUFSIZ]; // 受信メッセージ
           int         messlen;         // メッセージの長さ

    // ステップ1：ソケットを作成する
    sock_id = socket( AF_INET, SOCK_STREAM, 0 ); // 回線を取得する
    if( sock_id == -1 ) oops( "Socket" );        // 回線取得に失敗した場合

    // ステップ2：サーバに接続する
    //            先にサーバのアドレス（ホスト名、ポート番号）を組み立てる必要がある
    bzero( &servadd, sizeof( servadd ) ); // 構造体をクリアする
    hp = gethostbyname( av[1] );          // ホストのIPアドレスを照合する
    if( hp == NULL ) oops( av[1] );

    bcopy( hp->h_addr, (struct sockaddr* )&servadd.sin_addr, hp->h_length ); // ホスト情報を設定
    servadd.sin_port = htons( atoi( av[2] ) );                                 // ソケットポートを設定
    servadd.sin_family = AF_INET;                                              // アドレスファミリを設定

    // 接続＋失敗時の処理
    if( connect( sock_id, ( struct sockaddr* )&servadd, sizeof( servadd ) ) != 0 ) oops( "connect" );

    // ステップ3：サーバからデータを受け取って電話を切る
    messlen = read( sock_id, message, BUFSIZ );                    // 情報を読み出す
    if( messlen == -1 ) oops( "read" );
    if( write( 1, message, messlen ) != messlen ) oops( "write" ); // 標準出力への書き込み
    close( sock_id );

    return 0;
}
