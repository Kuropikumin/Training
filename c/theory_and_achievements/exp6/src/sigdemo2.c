/* sigdemo1.c
 *    目的：シグナルハンドラを無視する方法を示す
 *          Ctrl+C を無視する、Ctrl+\で終了する
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h> // sleep関数を利用するために追加

int main( void )
{
    signal( SIGINT, SIG_IGN );

    printf( "If you want to stop, Enter Ctrl+\\" );

    while ( 1 ) {
        printf( "Hello\n" );
        sleep( 1 );
    }

    return 0;
}
