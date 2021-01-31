/* sigdemo1.c
 *    目的：シグナルハンドラの仕組みを示す
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h> // sleep関数を利用するために追加

void f( int signal );

int main( void )
{
    void f( int ); // ハンドラを宣言する
    int  i;

    signal( SIGINT, f );
    for( i = 0; i < 5; i++ ) {
        printf( "Hello\n" );
        sleep( 1 );
    }

    return 0;
}

void f( int signal )
{
    printf( "OUCH!\n" );
}
