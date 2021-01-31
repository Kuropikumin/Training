/* echostate.c
 *     fdが0のttyドライバのエコービットの状態を報告する
 *     ドライバから属性を読みだしてビットをテストする方法を示す
 */

#include <stdio.h>
#include <stdlib.h> // exit を利用するためにinclude（設定しないとwarningになる）
#include <termios.h>

int main( void )
{
    struct termios info;
    int    rv;

    rv = tcgetattr( 0, &info );
    if( rv == -1 ) {
        perror( "tcgetattr error:" );
        exit( 1 );
    }
    else {
        if( info.c_lflag & ECHO ) {
            printf( "echo is on, since its bit is 1\n" );
        }
        else {
            printf( "echo is off, since its bit is 0\n" );
        }
    }
    return 0;
}
