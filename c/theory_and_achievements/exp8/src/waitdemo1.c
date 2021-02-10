/* waitdemo1.c
 *   目的：wait関数によって、子プロセスの処理が終わるまで親プロセスが待機することを確認する
 *
 */

#include <stdio.h>
#include <stdlib.h>   // exit関数を利用するのに必要
#include <unistd.h>   // fork, sleep, getpid関数を利用するのに必要
#include <sys/wait.h> // wait関数を利用するのに必要

#define DELAY 10

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

    wait_rv = wait( NULL );
    printf( "done waiting for %d. Wait returned: %d\n", childpid, wait_rv );
}
