/* dgsend.c - データグラムセンダー
 *  使い方：dgsend <ホスト名> <ポート番号> "メッセージ"
 *    動作：ホスト名:ポート番号 にメッセージを送付する
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h> // strlen関数を利用するために必要

#define oops( m, x ) { perror( m ); exit( x ); }

int make_dgram_client_socket();
int make_internet_address( char*, int, struct sockaddr_in* );

int main( int ac, char* av[] )
{
           int         sock;  // 送信するソケットID
           char*       msg;   // 送信するメッセージ
    struct sockaddr_in saddr; // 送信側アドレス情報

    if( ac != 4 ) {
        fprintf( stderr, "usage: dgsend host port 'message'\n" );
        exit( 1 );
    }

    msg = av[3];

    // データグラムソケットを作成する
    if( ( sock = make_dgram_client_socket() ) == -1 ) oops( "cannot make socket", 2 );

    // 宛先のホスト名とポート番号を組み合わせてアドレスを作る
    if( make_internet_address( av[1], atoi( av[2] ), &saddr ) == -1 ) oops( "make addr", 4 );

    // 作ったアドレスにソケットを返して文字列を送る
    if( sendto( sock, msg, strlen( msg ), 0, ( struct sockaddr* )&saddr, sizeof( saddr ) ) == -1 ) oops( "sendto failed", 3 );
    return 0;
}
