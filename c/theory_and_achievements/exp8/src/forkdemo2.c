/* forkdemo2.c
 *   目的：子プロセス（forkコマンドによって生成されたプロセス）でもプロセスを生成できることを学ぶ
 *         fork関数を複数回実行し、どのような動作になるか確認する
 *         また、合計でどれだけ子プロセスが作成されるかを確認する
 */

#include <stdio.h>
#include <unistd.h> // getpid, fork関数を利用するのに必要

int main( void )
{
    int ret_from_fork = 100, mypid;

    printf( "Before: my pid is %d\n", getpid() ); // pidの表示
    fork();
    fork();
    fork();
    fork();
    printf( "After: my pid is %d\n", getpid() ); // pidの表示
    return 0;
}
