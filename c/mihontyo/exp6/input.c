#include <stdio.h>
#include <ctype.h>

#define MAX_STR  45
#define MAX_BUFF 1024

int main( void )
{
    int    ch;
    double d;
    int    n, step = 0;
    char   buff[MAX_BUFF + 1]    = "";
    char   strmsg[][MAX_STR + 1] = { 
        "浮動小数点数を入力してください\n", 
        "整数を入力してください\n", 
        "文字列を入力してください\n"
    };
    
    printf( "%s", strmsg[0] );
    while( 1 ) {
        do {
            ch = getchar();
            if( ch == '\n' ) printf( strmsg[step] );
        } while( isspace( ch ) );

        ungetc( ch, stdin );

        if( step == 0 ) {
            if( scanf( "%17lf", &d ) == 1 ) {
                printf( "変換できた浮動小数点数: %.15g\n", d );
                step++;
            }
            fflush( stdin );
            printf( strmsg[step] );
        }
        else if( step == 1 ) {
            if( scanf( "%5d", &n ) == 1 ) {
                printf( "変換できた整数: %d\n", n );
                step++;
            }
            fflush( stdin );
            printf( strmsg[step] );
        }
        else {
            if( scanf( "%1024s", buff ) == 1 ) {
                printf( "変換できた文字列: %s\n", buff );
                fflush( stdin );
                break;
            }
            else {
                fflush( stdin );
                printf( strmsg[step] );
            }
        }
    }

    return 0;
}
