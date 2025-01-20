#include <stdio.h>

int main( void )
{
    int    i;
    int    n;
    char   ch = 0;
    double db = 0;

    ch += 40;
    printf( "ch: %c\n", ch );

    n = 1000;
    printf( "n: %d\n", n );

    printf( "db: %lf\n", db );

    for( i = 0; i < 10; i++ ) printf( "%d ", i );
    printf( "\n" );

    return 0;
}
