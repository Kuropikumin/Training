/* wait_test.c
 *   目的：wait関数がブロックするのは親プロセスのみかを確認
 *         親プロセス - 子プロセス - 孫プロセスを作成し、子プロセスでwait関数を実行する
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
    void child_code(), parent_code(), grandson_code();

    printf( "before: mypid is %d\n", getpid() );

    if     ( ( newpid = fork() ) == -1 ) perror( "fork error!" );
    else if( newpid == 0 ) child_code( DELAY );
    else                   parent_code( newpid );
    return 0;
}

void grandson_code( int childpid )
// 孫プロセスも居眠り
{
    printf( "grandson code pid is %d\n, child code pid is %d\n", getpid(), childpid );
    printf( "grandson 2seconds sleep.\n" );
    sleep( 2 );
    printf( "grandson done. about to exit\n" );
    exit( 20 );
}

void child_code( int delay )
// 子プロセスは居眠りをしている
{
    int newpid;
    printf( "child %d here.\n", getpid() );
    printf( "first, create grandson process\n" );
    if     ( ( newpid = fork() ) == -1 ) perror( "fork error!" );
    else if( newpid == 0 )               grandson_code( getpid() );
    else                                 wait( NULL );              // 孫プロセス処理が終わるまで待機
    printf( "second, child code will sleep for %d seconds\n", delay );
    sleep( delay );
    printf( "child done. about to exit\n" );
    exit( 17 );
}

void parent_code( int childpid )
// 親はメッセージを出力する
{
    printf( "done waiting for %d\n", childpid );
}
