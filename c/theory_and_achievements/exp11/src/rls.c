/* rls.c - リモートディレクトリリスト表示サービスのクライアント
 *     使い方：rls <ホスト名> <ディレクトリ>
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>  // exit関数を利用するために必要
#include <unistd.h>  // read, write, close関数を利用する際に必要
#include <strings.h> // bcopy, bzero関数を利用する際に必要
#include <string.h>  // strlen関数を利用する際に必要

#define oops( msg ) { perror( msg ); exit( 1 ); }
#define PORTNUM 15000

int main( int ac, char* av[] )
{
    struct sockaddr_in servadd;        // 呼び出す番号
    struct hostent*    hp;             // 番号の取得に使用
           int         sock_id;        // ソケットID
           int         sock_fd;        // ファイルディスク番号
           char        buffer[BUFSIZ]; // 受信メッセージ
           int         n_read;         // メッセージサイズ

    if( ac != 3 ) oops( "Usage: rls <hostname> <port number>" );

    // ステップ1：ソケットを作成する
    sock_id = socket( AF_INET, SOCK_STREAM, 0 ); // 回線の取得
    if( sock_id == -1 ) oops( "socket" );        // socket失敗時の処理

    // ステップ2：サーバに接続する
    bzero( &servadd, sizeof( servadd ) );                                     // アドレスを 0 クリアする
    hp = gethostbyname( av[1] );                                              // ホストのIPアドレスを照合する
    if( hp == NULL ) oops( av[1] );                                           // アドレス照合失敗時の処理
    bcopy( hp->h_addr, ( struct sockaddr* )&servadd.sin_addr, hp->h_length ); // 取得した情報をコピーする
    servadd.sin_port   = htons( PORTNUM );                                    // ポート番号の設定
    servadd.sin_family = AF_INET;                                             // ソケットタイプの設定

    // サーバへの接続および例外処理
    if( connect( sock_id, ( struct sockaddr* )&servadd, sizeof( servadd ) ) != 0 ) oops( "connect" );

    // ステップ3：ディレクトリ名を送り、結果を読み出す
    // ディレクトリ名を書き込みおよび例外処理
    if( write( sock_id, av[2], strlen( av[2] ) ) == -1 ) oops( "write" );
    // 1行のリクエストを投げることを想定しているので、最後に改行（\n）を追加する
    if( write( sock_id, "\n", 1 ) == -1 ) oops( "write" );

    // サーバからデータが送付される限りループする
    while( ( n_read = read( sock_id, buffer, BUFSIZ ) ) > 0 ) {
        // 取得したデータを標準出力に書き込む
        if( write( 1, buffer, n_read ) == -1 ) oops( "write" );
    }
    close( sock_id );

    return 0;
}
