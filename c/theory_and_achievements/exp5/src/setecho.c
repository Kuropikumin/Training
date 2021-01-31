/* setecho.c
 *     使い方：setecho [y|n]
 *     学習ポイント：tty属性を読み出し、書き換え、リセットする方法を学ぶ
 */

#include <stdio.h>
#include <stdlib.h> // exit を利用するためにinclude（設定しないとwarningになる）
#include <termios.h>

#define oops( s, x ) { perror( s ); exit( x ); }

int main( int ac, char* av[] )
{
    struct termios info;

    if( ac == 1 ) {
        printf( "Usage: setcho [y|n]\n" );
        exit( 0 );
    }

    if( tcgetattr( 0, &info ) == -1 ) oops( "tcgetattr error:", -1 );

    if( av[1][0] == 'y' )      info.c_lflag |= ECHO;
    else if( av[1][0] == 'n' ) info.c_lflag &= ~ECHO;

    if( tcsetattr( 0, TCSANOW, &info ) == -1 ) oops( "tcsetattr error:", 2 );

    return 0;
}
