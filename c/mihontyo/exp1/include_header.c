#include <stdio.h>
#include "stdlib.h"

int main( void )
{
    int i;

    for( i = 0; i < 127; i++ ) {
        if( 0x41 <= i && i <= 0x5a ) printf( "%c", i );
    }
    printf( "\n" );

    return EXIT_SUCCESS;
}