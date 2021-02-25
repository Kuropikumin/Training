/* lsrv1.c - ライセンスサーバ サーバプログラムバージョン1 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <signal.h>

#define MSGLEN 128 // データグラムのサイズ

// 別ファイル（lserv_funcs1.c）の関数
int  setup();
void handle_request( char*, struct sockaddr_in*, socklen_t );
void narrate( char*, char*, struct sockaddr_in* );

int main( int ac, char* av[] )
{
    struct sockaddr_in client_addr;
           socklen_t   addrlen;
           char        buf[MSGLEN];
           int         ret;
           int         sock;

    sock = setup();

    while( 1 ) {
        addrlen = sizeof( client_addr );
        ret     = recvfrom( sock, buf, MSGLEN, 0, ( struct sockaddr* )&client_addr, & addrlen );

        if( ret != -1 ) {
            buf[ret] = '\0';
            narrate( "GOT:", buf, &client_addr );
            handle_request( buf, &client_addr, addrlen );
        }
        else if( errno != EINTR ) perror( "recvfrom" );
    }

    return 0;
}
