/* rotate.c
 *    a->b, b->c, ... z->aの変換を行う
 *    目的：ttyモードを示すために役立つ
 */

#include <stdio.h>
#include <ctype.h>

int main( void )
{
    int c;
    while( ( c = getchar() ) != EOF ) {
        if( c == 'z' ) {
            c = 'a';
        }
        else if( islower( c ) ) {
            c++;
        }
        putchar( c );
    }
    return 0;
}
