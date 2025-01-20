#include <stdio.h>
#include <assert.h>

int main( void )
{
    int i, j;

    for( i = 0, j = 9; i < 10; i++, j-- ) {
        assert( j != 0 );
        printf( "i: %d, j: %d, i/j = %d\n", i, j, i/j );
    }

    return 0;
}
