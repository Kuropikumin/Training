#include <stdio.h>

int main( void )
{

    /* double 型の変数を宣言、初期化する */
    double d = 555.245778;

    /*  */
    /* 浮動小数点を表示する */
    printf( "浮動小数点値: %.6f\n", d );

    return 0;
}

/* 変更に伴う一時的なプール
    int n   = -1000;
    int num = -1000;
    printf( "%d\n", num );
*/