/* forkdemo3.c
 *   目的：親プロセス（このプログラム実行時に生成されるプロセス）と
 *         子プロセス（forkによって作成されたプロセス）を判別する方法について学ぶ
 */

#include <stdio.h>
#include <unistd.h> // getpid, fork関数を利用するのに必要

int main( void )
{
    int fork_rv;

    printf( "Before: my pid is %d\n", getpid() ); // pidの表示

    fork_rv = fork();
    if     ( fork_rv == -1 ) perror( "fork failed!" );
    else if( fork_rv == 0 )  printf( "I am the child. my pid = %d\n", getpid() );
    else                     printf( "I am the parent. my child is %d\n", fork_rv );

    return 0;
}
