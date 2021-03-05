/* file_ts.c - 現在の日時をファイルに書き込む
 *   使い方：file_ts <ファイル名>
 *     動作：現在の日時を <ファイル名> に書き込む
 *     注意：fcntl() ベースのロックを使う
 */

#include <stdio.h>
#include <sys/file.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <string.h> // strlen関数を利用するのに必要
#include <unistd.h> // sleep関数を利用するのに必要

#define oops( m, x ) { perror( m ); exit( x ); }

// 関数設定
void lock_operation( int, int );

int main( int ac, char* av[] )
{
    int    fd;
    time_t now;
    char*  message;

    if( ac != 2 ) {
        fprintf( stderr, "usage: file_ts filename\n" );
        exit( 1 );
    }

    if( ( fd = open( av[1], O_CREAT|O_TRUNC|O_WRONLY, 0644 ) ) == -1 ) oops( av[1], 2 );

    while( 1 ) {
        time( &now );
        message = ctime( &now );

        lock_operation( fd, F_WRLCK );

        if( lseek( fd, 0L, SEEK_SET ) == -1 )               oops( "lseek", 3 );
        if( write( fd, message, strlen( message ) ) == -1 ) oops( "write", 4 );

        lock_operation( fd, F_UNLCK ); // ファイルのロックを解除する
        sleep( 1 );                    // 新しい時刻を待つ
    }

    return 0;
}

void lock_operation( int fd, int op )
{
    struct flock lock;

    lock.l_whence = SEEK_SET;
    lock.l_start  = lock.l_len = 0;
    lock.l_pid    = getpid();
    lock.l_type   = op;

    if( fcntl( fd, F_SETLKW, &lock ) == -1 ) oops( "lock operation", 6 );
}
