/* exec_test.c
 *   目的：execvpでプロセス名が変わるかを確認する
 *   結論：exec_test プロセスが sleep プロセスに変更される
 */

#include <stdio.h>  // printf関数を利用するのに必要
#include <unistd.h> // execvp関数を利用するのに必要
int main( void )
{
    char* arglist[3];
    int   c = 0;

    arglist[0] = "sleep"; // ここは実行するプログラム名である必要がある
    arglist[1] = "5" ;    // sleep の秒数
    arglist[2] = 0 ;      // 最後はNULL（0）である必要がある

    printf( "* * * This process is exec2 exec \n" );
    c = getchar();

    printf( "* * * About to exec sleep 5\n" );
    execvp( "sleep", arglist );
    printf( "* * * ls is done. bye\n" );
    return 0;
}
