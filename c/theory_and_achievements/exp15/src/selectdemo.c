/* selectdemo.c - 2つのデバイスへの入力とタイムアウトを監視する
 *  使い方：selectdemo <デバイス1> <デバイス2> <タイムアウト値>
 *    動作：各ファイルからの入力を報告する。タイムアウトも報告する
 */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h> // exit関数を利用するのに必要

#define oops( m, x ) { perror( m ); exit( x ); }

// 関数設定
void showdata( char*, int );

int main( int ac, char* av[] )
{
           int     fd1;     // 監視するファイルディスクリプタ1
           int     fd2;     // 監視するファイルディスクリプタ1
    struct timeval timeout; // 待ち時間
           fd_set  readfds; // これらに対する入力を監視する
           int     maxfd;   // 最も大きいファイルディスクリプタ + 1
           int     retval;  // select の戻り値

    if( ac != 4 ) {
        fprintf( stderr, "usage: %s file file timeout", *av );
        exit( 1 );
    }

    // ファイルをオープンする
    if( ( fd1 = open( av[1], O_RDONLY) ) == -1 ) oops( av[1], 2 );
    if( ( fd2 = open( av[2], O_RDONLY ) ) == -1 ) oops( av[2], 3 );
    maxfd = 1 + ( fd1 > fd2 ? fd1 : fd2 );

    while( 1 ) {
        // 監視するファイルディスクリプタのリストを作る
        FD_ZERO( &readfds );     // すべてのビットをクリア
        FD_SET( fd1, &readfds ); // fd1のためのビットをセット
        FD_SET( fd2, &readfds ); // fd1のためのビットをセット

        // タイムアウト値を設定
        timeout.tv_sec  = atoi( av[3] ); // 秒を設定
        timeout.tv_usec = 0;             // μ値は設定せず

        // 入力を待つ
        retval = select( maxfd, &readfds, NULL, NULL, &timeout );
        if( retval == -1 ) oops( "select", 4 );
        if( retval > 0 ) {
            // 各ファイルディスクリプタのビットをチェック
            if( FD_ISSET( fd1, &readfds ) ) showdata( av[1], fd1 );
            if( FD_ISSET( fd2, &readfds ) ) showdata( av[2], fd2 );
        }
        else printf( "no input after %d seconds\n", atoi( av[3] ) );
    }

    return 0;
}

void showdata( char* fname, int fd )
{
    char buf[BUFSIZ];
    int  n;

    printf( "%s: ", fname, n );
    fflush( stdout );
    n = read( fd, buf, BUFSIZ );
    if( n == -1 ) oops( fname, 5 );
    write( 1, buf, n );
    write( 1, "\n", 1 );
}
