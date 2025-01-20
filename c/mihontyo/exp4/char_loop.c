#include <stdio.h>

int main( void )
{
    unsigned char a     = 0;
    int           count = 0;

    while( a < 200 ) {
        printf( "%d: %c\n", count, a ); 
        a++;
        count++;

        if( count > 20000 ) break;
    }

    return 0;
}
