#include <stdio.h>

int lf_num = 4;

int main( void )
{
    int i;
    int count = 0;

    for( i = 0; i < 20; i++ ) {
        if( i != 0 && i%lf_num == 0 ) printf( "\n" );
        printf( "%d ", i );
        count++;
    }

    return 0;
}
