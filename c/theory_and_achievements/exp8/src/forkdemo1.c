/* forkdemo1.c
 *   目的：forkの動作を確認する
 *         forkが2つのプロセスを作り、それぞれがforkからの戻り値によって区別できることを示す
 */

#include <stdio.h>
#include <unistd.h> // getpid, sleep, fork関数を利用するのに必要

int main( void )
{
    int ret_from_fork = 100, mypid;

    mypid = getpid();                          // このプログラムのpidを取得
    printf( "Before: my pid is %d\n", mypid ); // pidの表示

    ret_from_fork = fork();

    sleep( 10 );

    printf( "After: my pid is %d, fork() said %d\n", getpid(), ret_from_fork );
    return 0;
}
