/* smsh1.c small-shell version 1
 *     目的：pshを基礎として作った shell コマンド
 *           コマンド行を解析して文字列配列を作る
 *           fork, exec, waitを使い、シグナルを無視する
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./header/smsh.h"

#define DFL_PROMPT "> "

void fatal( char* s1, char* s2, int n );

int main( void )
{
    char*  cmdline;
    char*  prompt;
    char** arglist;
    int    result;
    void   setup();

    prompt = DFL_PROMPT;
    setup();

    while( ( cmdline = next_cmd( prompt, stdin ) ) != NULL ) {
        if( ( arglist = splitline( cmdline ) ) != NULL ) {
            result = execute( arglist );
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
