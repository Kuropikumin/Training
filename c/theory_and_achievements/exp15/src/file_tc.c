/* file_tc.c - 現在の日時をファイルから読み出す
 *   使い方：file_ts <ファイル名>
 *     注意：fcntl() ベースのロックを使う
 */

#include <stdio.h>
#include <sys/file.h>
#include <fcntl.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <unistd.h> // write, read, close関数を利用するのに必要

#define oops( m, x ) { perror( m ); exit( x ); }
#define BUFLEN 10

// 関数設定
void lock_operation( int, int );

int main( int ac, char* av[] )
{
    int  fd;
    int  nread;
    char buf[BUFLEN];

    if( ac != 2 ) {
        fprintf( stderr, "usage: file_tc filename\n" );
        exit( 1 );
    }

    if( ( fd = open( av[1], O_RDONLY ) ) == -1 ) oops( av[1], 2 );
    lock_operation( fd, F_RDLCK );

    while( ( nread = read( fd, buf, BUFLEN ) ) > 0 ) write( 1, buf, nread );

    lock_operation( fd, F_UNLCK );
    close( fd );

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
