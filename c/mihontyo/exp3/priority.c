#include <stdio.h>

int main( void )
{
    int a = 1, b = 99, c = 55;

    if( ( a < b ? a:b ) && ( a > b ? a:b ) < 100 ) printf( "a( %2d )とb( %2d )の小さいほうはゼロではなくて、大きいほうは100未満\n", a, b );
    if( ( b < c ? b:c ) && ( b > c ? b:c ) > 50 )  printf( "b( %2d )とc( %2d )の小さいほうはゼロではなくて、大きいほうは50より大きい\n", b, c );
    if( ( a < c ? a:c ) && ( a > c ? a:c ) < 50 )  printf( "a( %2d )とc( %2d )の小さいほうはゼロではなくて、大きいほうは50未満\n", a, c );

    return 0;
}
