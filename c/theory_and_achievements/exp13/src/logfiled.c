/* logfiled.c - Unix ドメインデータグラムソケットを使う簡単なログファイルサーバ
 *     使い方：logfiled >> logfilename
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <time.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <unistd.h> // read関数を利用するのに必要

#define MSGLEN 512
#define oops( m, x ) { perror( m ); exit( x ); }
#define SOCKNAME "/tmp/lofilesock"

int main( int ac, char* av[] )
{
           int         sock;        // このメッセージを読む
    struct sockaddr_un addr;        // ソケットのアドレス
           socklen_t   addrlen;
           char        msg[MSGLEN];
           int         l;
           char        sockname[] = SOCKNAME;
           time_t      now;
           int         msgnum     = 0;
           char*       timestr;

    // アドレスを組み立てる
    addr.sun_family = AF_UNIX;                                // AF_UNIXに注意
    strcpy( addr.sun_path, sockname );                        // ファイル名がアドレス
    addrlen = strlen( sockname ) + sizeof( addr.sun_family );

    sock = socket( PF_UNIX, SOCK_DGRAM, 0 ); // PF_UNIX に注意
    if( sock == -1 ) oops( "socket", 2 );

    // ソケットにアドレスを割り当てる
    if( bind( sock, (struct sockaddr* )&addr, addrlen ) == -1 ) oops( "bind", 3 );

    // 読み書き
    while( 1 ) {
        l = read( sock, msg, MSGLEN );          // DGRAMを読み出す
        msg[l] = '\0';                          // 文字列化する
        time( &now );
        timestr = ctime( &now );
        timestr[strlen( timestr ) - 1] = '\0'; // 改行を切り捨てる

        printf( "[%5d] %s %s\n", msgnum++, timestr, msg );
        fflush( stdout );
    }

    return 0;
}
