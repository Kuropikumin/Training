/* waitdemo2.c
 *   目的：親プロセスはどうやって子プロセスのステータスを取得すればよいかを学ぶ
 *
 */

#include <stdio.h>
#include <stdlib.h>   // exit関数を利用するのに必要
#include <unistd.h>   // fork, sleep, getpid関数を利用するのに必要
#include <sys/wait.h> // wait関数を利用するのに必要

#define DELAY 5

int main( void )
{
    int  newpid;
    void child_code(), parent_code();

    printf( "before: mypid is %d\n", getpid() );

    if     ( ( newpid = fork() ) == -1 ) perror( "fork error!" );
    else if( newpid == 0 ) child_code( DELAY );
    else                   parent_code( newpid );
    return 0;
}

void child_code( int delay )
// 子プロセスは居眠りをしている
{
    printf( "child %d here. will sleep for %d seconds\n", getpid(), delay );
    sleep( delay );
    printf( "child done. about to exit\n" );
    exit( 17 );
}

void parent_code( int childpid )
// 親は子のプロセスが終了するのを待ってからメッセージを出力する
{
    int wait_rv;
    int child_status;
    int high_8, low_7, bit_7;

    wait_rv = wait( &child_status );
    printf( "done waiting for %d. Wait returned: %d\n", childpid, wait_rv );

    high_8 = child_status >> 8;   // 1111 1111 0000 0000
    low_7  = child_status & 0x7F; // 0000 0000 0111 1111
    bit_7  = child_status & 0x80; // 0000 0000 1000 0000
    printf( "status: exit=%d, sig=%d, core=%d\n", high_8, low_7, bit_7 );
}
