#include <stdio.h>

int main( void )
{
    short       sh = 10000;
    long        lg = 2000000000L;
    long double ld = 3.141592653589793238462643383L;

    printf( "表示文字: A\n");
    printf( "%%cを使った文字表示: %c\n", 'A' );
    printf( "%%Xを使った16進数表示: %X\n", 'A' );
    printf( "符号付10進数を表示: %d\n", -1000 );
    printf( "符号なし10進数表示: %u\n", 1000 );
    printf( "%%sを使った文字表示: %s\n", "これは文字列" );

    printf( "%%1.27Lfを使った小数点以下27桁のlong double型浮動小数点表示:\n%1.27Lf\n", ld );
    printf( "%%#030dを使った前ゼロ、30桁幅の符号付10進数表示:\n%#030d\n", 1000 );

    printf( "%%hdを使ったshort型符号付10進数表示: %hd\n", sh );
    printf( "%%ldを使ったlong型符号付10進数表示: %ld\n", lg );

    return 0;
}