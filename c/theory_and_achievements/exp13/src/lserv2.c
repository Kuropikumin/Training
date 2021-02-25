/* lsrv2.c - ライセンスサーバ サーバプログラムバージョン2 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h> // alarm関数を利用するのに必要

#define MSGLEN 128 // データグラムのサイズ

// lserv1.cからの追加点
#define RECLAIM_INTERVAL 60

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
    // lserv1.cからの追加点
           void        ticket_reclaim(); // バージョン2で追加
           unsigned    time_left;

    sock = setup();

    // lserv1.cからの追加点
    signal( SIGALRM, ticket_reclaim ); // チケット回収関数をスケジューリング
    alarm( RECLAIM_INTERVAL );         // この時間が経過した後

    while( 1 ) {
        addrlen = sizeof( client_addr );
        ret     = recvfrom( sock, buf, MSGLEN, 0, ( struct sockaddr* )&client_addr, & addrlen );

        if( ret != -1 ) {
            buf[ret] = '\0';
            narrate( "GOT:", buf, &client_addr );
            time_left = alarm( 0 );
            handle_request( buf, &client_addr, addrlen );
            alarm( time_left );
        }
        else if( errno != EINTR ) perror( "recvfrom" );
    }

    return 0;
}
