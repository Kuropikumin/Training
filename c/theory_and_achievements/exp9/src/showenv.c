/* showenv. - 環境を読み出して出力する方法を学ぶ
 */

#include <stdio.h>

extern char** environ; // 文字列配列を指す

int main( void )
{
    int i;

    for( i = 0; environ[i]; i++ ) printf( "%s\n", environ[i] );

    return 0;
}
