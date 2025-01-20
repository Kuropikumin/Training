#include <stdio.h>

int main( void )
{
    char      ch = 'E';
    char   str[] = "漢字文字列";
    int        n = 200;
    double     d = 3.14;
    int       n1 = 100, n2 = 200, n3 = 300;

    printf( "nは、" );
    switch( ch ) {
        case 'A':
            printf( "文字「A」である\n" );
            break;
        case 'B':
            printf( "文字「B」である\n" );
            break;
        case 'C':
            printf( "文字「C」である\n" );
            break;
        default:
            printf( "ABCのどれでもない" );
            
    }

    /* caseに文字列や浮動小数点は使用できない
    printf( "strは、" );
    switch( str ) {
        case "文字表示列":
            printf( "strは「文字表示列」である\n" );
            break;
        default:
            printf( "strは「文字表示列」ではない\n" );
    }

    printf( "dは、" );
    switch( d ) {
        case 1.14:
            printf( "浮動小数点「1.14」である。\n" );
            break;
        case 2.14:
            printf( "浮動小数点「2.14」である。\n" );
            break;
        case 3.14:
            printf( "浮動小数点「3.14」である。\n" );
            break;
        default:
            printf( "「1.14, 2.14, 3.14」のどれでもない\n" );
    }
    */

    printf( "nは、" );
    switch( n ) {
        // case n1:
        case 100:
            printf( "整数値「100」である。\n" );
            break;
        // case n2:
        case 200:
            printf( "整数値「200」である。\n" );
            break;
        //case n3:
        case 300:
            printf( "整数値「300」である。\n" );
            break;
        default:
            printf( "「100, 200, 300」のどれでもない\n" );
    }



    return 0;
}
