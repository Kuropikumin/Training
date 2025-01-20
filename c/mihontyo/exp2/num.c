#include <stdio.h>

int main( void )
{
    char  ch1 = 0x41;
    short sh1 = 0x7530;
    int   n1  = 0xf4240;
    long  l1  = 0x2c4020L;

    char  ch2 = 65;
    short sh2 = 030000;
    int   n2  = 1000000;
    long  l2  = 2900000L;

    char  ch3 = 0101;
    short sh3 = 072460;
    int   n3  = 03641100;
    long  l3  = 013040040L;

    float  f1 = 33344.0098f;
    double db = 2.718281828459045;

    printf( "( ch1, ch2, ch3 ) = ( %c, %c, %c )\n", ch1, ch2, ch3 );
    printf( "( sh1, sh2, sh3 ) = ( %hd, %hd, %hd )\n", sh1, sh2, sh3 );
    printf( "( n1, n2, n3 ) = ( %d, %d, %d )\n", n1, n2, n3 );
    printf( "( l1, l2, l3 ) = ( %ld, %ld, %ld )\n", l1, l2, l3 );
    printf( "f1: %lf\n", f1 );
    printf( "db: %.15f\n", db );
}
