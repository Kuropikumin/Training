/* dgrecv.c - データグラムレシーバ
 *  使い方：dgrecv <ポート番号>
 *    動作：指定されたポートでデータグラムを待ち、メッセージを報告する
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h> // exit関数を利用するのに必要

#define oops( m, x ) { perror( m ); exit( x ); }

int  make_dgram_server_socket( int );
int  get_internet_address( char*, int, int*, struct sockaddr_in* );
void say_who_called( struct sockaddr_in* );

int main( int ac, char* av[] )
{
           int         port;        // このポートを利用する
           int         sock;        // ソケットID
           char        buf[BUFSIZ]; // ここにデータを受信する
           size_t      msglen;      // データサイズをここに格納
    struct sockaddr_in saddr;       // ここに受信側アドレスを書き込む
           socklen_t   saddrlen;    // アドレスの長さをここに書き込む

    if( ac == 1 || ( port = atoi( av[1] ) ) <= 0 ) {
        fprintf( stderr, "usage: dgrecv portnumber\n" );
        exit( 1 );
    }

    // ソケットを作成し、ポート番号を割り当てる
    if( ( sock = make_dgram_server_socket( port ) ) == -1 ) oops( "cannot make socket", 2 );

    // ソケットに届いたメッセージを受信する
    saddrlen = sizeof( saddr );
    while( ( msglen = recvfrom( sock, buf, BUFSIZ, 0, ( struct sockaddr* )&saddr, &saddrlen ) ) > 0 ) {
        buf[msglen] = '\0';
        printf( "dgrecv: got a message: %s\n", buf );
        say_who_called( &saddr );
    }

    return 0;
}

void say_who_called( struct sockaddr_in* addrp )
{
    char host[BUFSIZ];
    int  port;

    get_internet_address( host, BUFSIZ, &port, addrp );
    printf( "  from: %s:%d\n", host, port );
}
