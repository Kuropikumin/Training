#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
    int num;
    char* str;

    num = 77;
    printf( "%dをprintfします\n", num );
    printf( "%%10d  = %10d|\n",  num );
    printf( "%%10x  = %10x|\n",  num );
    printf( "%%010x = %010x|\n", num );
    puts( "" );
    str = "abc";
    printf( "%sをprintfします\n", str );
    printf( "%%10s  = %10s|\n",  str );
    printf( "%%-10s = %-10s|\n", str );

    return 0;
}