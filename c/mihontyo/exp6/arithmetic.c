#include <stdio.h>

int main( void )
{
    int n1 = 100, n2 = 30, n3 = 350, n4 = 3;
    printf( "n1 = %d, n2 = %d, n3 = %d, n4 = %d\n", n1, n2, n3, n4 );

    printf( "問題：n1 に n2 を加えて n4 で割り、その結果に n3 をかけると > %d\n", ( n1 + n2 )/n4*n3 );
    printf( "問題：n1 を n3 で割って n2 を加え、その結果を n4 で割ると > %d\n", n1/n3 + n2/n4 );
    printf( "問題：n1 にインクリメントした n2 をかけ、n3 を引き、その結果に n4 を加えると > %d\n", n1*( ++n2 ) - n3 + n4 );
    printf( "問題：n1 に負の n2 を加え n3 を引き、その結果を n4 で割ると > %d\n", ( n1 + (-n2) - n3 )/n4 );
    return 0;
}
