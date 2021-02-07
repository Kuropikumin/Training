/* sigdemo3.c
 *    目的：シグナルの問いに対する答えを示す
 *        問1：シグナルが届いた後もハンドラは有効か？
 *        問2：シグナルXの処理中にシグナルXが届いたらどうなるか？
 *        問3：シグナルY処理中にシグナルXが届いたらどうなるか？
 *        問4：read()中にシグナルが届いたらどうなるか？
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h> // sleep関数を利用するために追加
#include <string.h> // strncmp関数を利用するために追加

#define INPUTLEN 100

int main( int ac, char* av[] )
{
    void inthandler( int );
    void quithandler( int );
    char input[INPUTLEN];
    int  nchars;

    signal( SIGINT,  inthandler );
    signal( SIGQUIT, quithandler );

    do {
        printf( "\nType a message\n" );
        nchars = read( 0, input, ( INPUTLEN - 1 ) );

        if( nchars == -1 ) perror( "read returned an error" );
        else {
            input[nchars] = '\0';
            printf( "You typed: %s", input );
        }
    } while( strncmp( input, "quit", 4 ) != 0 );

    return 0;
}

void inthandler( int s )
{
    printf( "Received signal %d .. waiting\n", s );
    sleep( 2 );
    printf( " Leaving inthandler \n" );
}

void quithandler( int s )
{
    printf( "Received signal %d .. waiting\n", s );
    sleep( 3 );
    printf( " Leaving quithandler \n" );
}
