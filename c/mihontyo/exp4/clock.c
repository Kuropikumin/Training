#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 200

void Delay( int milli_second )
{
    clock_t current_time, end_time;

    current_time = clock()/CLOCKS_PER_SEC;
    if( current_time == ( clock_t )-1 ) {
        fprintf( stderr, "時間の計測で時間が発生しました\n" );
        exit( EXIT_FAILURE );
    }

    printf( "CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC );
    end_time = current_time + 5;

    printf( "( current_time, end_time ) = ( %ld, %ld )\n", current_time, end_time );
    while( current_time < end_time ) {
        current_time = clock()/CLOCKS_PER_SEC;
        if( current_time == ( clock_t )-1 ) {
            fprintf( stderr, "時間の計測で時間が発生しました\n" );
            exit( EXIT_FAILURE );
        }
    }
}

int main( void )
{
    int answer;
    char buffer[ MAX_SIZE + 1 ] = "";

    printf( "問題：1から100までの整数の合計はいくつですか?（制限時間20秒）\n"
            "このプログラムは5秒間何も応答しません\n" );
    Delay( 5*1000 );

    printf( "では回答してください > " );
    do {
        buffer[0] = '\0';
        scanf( "%200[0-9Qq]", buffer );

        if( strlen( buffer ) == 0 ) printf( "整数値を入力してください：" );
        fflush( stdin );

        if( buffer[0] == 'Q' || buffer[0] == 'q' ) exit( EXIT_SUCCESS );
    } while( sscanf( buffer, "%d", &answer ) != 1 );

    if( answer == 5050 ) printf( "正解\n" );
    else                 printf( "不正解\n正解は5050です\n" );

    return 0;
}
