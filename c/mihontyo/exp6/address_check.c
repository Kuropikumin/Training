#include <stdio.h>

int main( void )
{
    int     n  = 100;
    double  d  = 3.14159265;
    int*    pn = &n;
    double* pd = &d;

    printf( "int* 型ポインタpnの値: %p\n", pn );
    printf( "double* 型ポインタpdの値: %p\n", pd );
    printf( "int* 型ポインタpnを関節参照した値: %d\n", *pn );
    printf( "double* 型ポインタpdを関節参照した値: %f\n", *pd );
    return 0;
}
