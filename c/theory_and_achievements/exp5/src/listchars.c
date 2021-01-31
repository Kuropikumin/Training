/* listchars.c
 *    目的：入力に含まれているすべての文字を個別にリストアップする
 *    出力：文字とASCIIコードを1行に1ペアずつ
 *    入力：標準入力。Qという文字を検出するまで
 *    コメント：バッファリング/編集の有無を調べるのに役立つ
 */

#include <stdio.h>
int main( void )
{
    int c, n = 0;

    while( ( c = getchar() ) != 'Q' ) {
        printf( "char %3d is %c code %d\n", n++, c, c );
    }

    return 0;
}
