/* exec1.c
 *   目的：プログラムが別のプログラムを起動する方法を示す
 *
 */

#include <stdio.h>  // printf関数を利用するのに必要
#include <unistd.h> // execvp関数を利用するのに必要
int main( void )
{
    char* arglist[4];

    arglist[0] = "ls"; // ここは実行するプログラム名である必要がある
    arglist[1] = "-l"; // 実行するオプション
    arglist[2] = 0 ;   // 最後はNULL（0）である必要がある

    printf( "* * * About to exec ls -l\n" );
    execvp( "ls", arglist );
    printf( "* * * ls is done. bye\n" );
    return 0;
}
