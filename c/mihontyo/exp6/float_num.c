#include <stdio.h>

int main( void )
{
    float fl1 = 3.141592f;
    float fl2 = 314159.2e-5f;
    float fl3 = 0.0000000003141592e10f;

    double db1 = 3.141592653589793;
    double db2 = 314159.2653589793e-5;
    double db3 = 0.0000000003141592653589793e10;

    printf( "fl1[%%f]指定: %f\n", fl1 );
    printf( "fl1[%%.6f]指定: %.6f\n", fl1 );
    printf( "fl1[%%.6g]指定: %.6g\n", fl1 );
    printf( "fl1[%%.6e]指定: %.6e\n", fl1 );

    printf( "db1[%%f]指定: %f\n", db1 );
    printf( "db1[%%.15f]指定: %.15f\n", db1 );
    printf( "db1[%%.15g]指定: %.15g\n", db1 );
    printf( "db1[%%.15e]指定: %.15e\n", db1 );

    printf( "fl2[%%f]指定: %f\n", fl2 );
    printf( "fl2[%%.6f]指定: %.6f\n", fl2 );
    printf( "fl2[%%.6g]指定: %.6g\n", fl2 );
    printf( "fl2[%%.6e]指定: %.6e\n", fl2 );

    printf( "db2[%%f]指定: %f\n", db2 );
    printf( "db2[%%.15f]指定: %.15f\n", db2 );
    printf( "db2[%%.15g]指定: %.15g\n", db2 );
    printf( "db2[%%.15e]指定: %.15e\n", db2 );

    printf( "fl3[%%f]指定: %f\n", fl3 );
    printf( "fl3[%%.6f]指定: %.6f\n", fl3 );
    printf( "fl3[%%.6g]指定: %.6g\n", fl3 );
    printf( "fl3[%%.6e]指定: %.6e\n", fl3 );

    printf( "db3[%%f]指定: %f\n", db3 );
    printf( "db3[%%.15f]指定: %.15f\n", db3 );
    printf( "db3[%%.15g]指定: %.15g\n", db3 );
    printf( "db3[%%.15e]指定: %.15e\n", db3 );

    return 0;
}
