#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
    int  i, len;
    char printc;

    if( argc != 2 ) {
        printf( "Usage: upcase < alphabets >\n" );
        exit( EXIT_FAILURE );
    }

    len = strlen( argv[1] );
    for( i = 0; i < len; i++ ) {
        if( 'a' <= argv[1][i] && argv[1][i] <= 'z' ) printc = argv[1][i] - ( 'a' - 'A' );
        else                                         printc = argv[1][i];
        printf( "%c", printc );
    }

    printf( "\n" );

    return 0;
}
