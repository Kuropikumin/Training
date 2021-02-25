/* logfilec.c - ログファイルクライアント - ログファイルサーバにメッセージを送る
 *     使い方：logfilec "メッセージ"
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h> // exit関数を利用するのに必要

#define SOCKET "/tmp/lofilesock"
#define oops( m, x ) { perror( m ); exit( x ); }

int main( int ac, char* av[] )
{
           int         sock;        // このメッセージを読む
    struct sockaddr_un addr;        // ソケットのアドレス
           socklen_t   addrlen;
           char        sockname[] = SOCKET;
           char*       msg        = av[1];

    if( ac != 2 ) {
        fprintf( stderr, "usage: logfilec 'message'\n" );
        exit( 1 );
    }

    sock = socket( PF_UNIX, SOCK_DGRAM, 0 );
    if( sock == -1 ) oops( "socket", 2 );

    addr.sun_family = AF_UNIX;
    strcpy( addr.sun_path, sockname );
    addrlen = strlen( sockname ) + sizeof( addr.sun_family );

    if( sendto( sock, msg, strlen( msg ), 0, ( struct sockaddr* )&addr, addrlen )  == -1 ) oops( "sendto", 3 );
    
    return 0;
}
