/* smsh2.c small-shell version 2
 *     目的：pshを基礎として作った shell コマンド
 *           コマンド解析をサポートする smsh
 *           さらに、if...then...else..fi ロジックをサポートする（process()呼び出し）
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "./header/smsh.h"

#define DFL_PROMPT "> "

void fatal( char* s1, char* s2, int n );

int main( void )
{
    char*  cmdline;
    char*  prompt;
    char** arglist;
    int    result;
    int    process( char** );
    void   setup();

    prompt = DFL_PROMPT;
    setup();

    while( ( cmdline = next_cmd( prompt, stdin ) ) != NULL ) {
        if( ( arglist = splitline( cmdline ) ) != NULL ) {
            result = process( arglist );
            freelist( arglist );
        }
        free( cmdline );
    }

    return 0;
}

void setup()
/*
 *   目的：シェルの初期化
 * 戻り値：なし。トラブルが起きたら fatal() を呼び出す
 */
{
    signal( SIGINT,  SIG_IGN );
    signal( SIGQUIT, SIG_IGN );
}

void fatal( char* s1, char* s2, int n )
{
    fprintf( stderr, "Error: %s, %s\n", s1, s2 );
    exit( n );
}
