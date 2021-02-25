/* new_timeclnt.c - timeserv.c のクライアント
 *                  socklib.c を使って書き直す
 *     使い方：new_timeclnt <ホスト名> <ポート番号>
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

int connect_to_server( char*, int );

int main( int ac, char* av[] )
{
    int  sock_id;         // 回線ID
    char message[BUFSIZ]; // 受信メッセージ
    int  messlen;         // メッセージの長さ

    sock_id = connect_to_server( av[1], atoi( av[2] ) );
    // ステップ3：サーバからデータを受け取って電話を切る
    messlen = read( sock_id, message, BUFSIZ );                    // 情報を読み出す
    if( messlen == -1 ) oops( "read" );
    if( write( 1, message, messlen ) != messlen ) oops( "write" ); // 標準出力への書き込み
    close( sock_id );

    return 0;
}
