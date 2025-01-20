#include <stdio.h>

int main( void )
{
    int i;
    char charry[] = { 'K', '5', '3', 'p', 'Y', '7', '9', 'R', '3', 'z' };

    for( i = 0; i < 10; i++ ) {
        if( charry[i] > 0x2f && charry[i] < 0x3a ) printf( "%c", charry[i] );
        else                                       printf( "." );
    }
    printf( "\n" );

    return 0;
}
