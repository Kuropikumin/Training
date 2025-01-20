#include <stdio.h>

int main( void )
{
    float fl = 3.141592f;
    int n    = 100;

    printf( "[%f + %d] = %f\n", fl, n, fl + n );
    printf( "[%f - %d] = %f\n", fl, n, fl - n );
    printf( "[%d * %f] = %f\n", n, fl, n*fl );
    printf( "[%d / %f] = %f\n", n, fl, n/fl );
    printf( "[%f / %d] = %f\n", fl, n, fl/n );
    printf( "%f = [++%f]\n", ++fl, fl );
    printf( "%f = [--%f]\n", --fl, fl );
    printf( "[%f++] = %f\n", fl++, fl );
    printf( "[%f--] = %f\n", fl--, fl );

    return 0;
}
