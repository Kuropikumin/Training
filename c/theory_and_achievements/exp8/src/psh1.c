/* psh1.c -- prompting shell version 1
 *   目的：sh プログラムについて学ぶ
 *         コマンドと引数の入力を促す
 *         execvp 呼び出しのために引数配列を作る
 *         execvp() を使い、制御を返さない
 */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h> // execvp関数を利用するのに必要
#include <stdlib.h> // exit関数、malloc関数を利用するのに必要

#define MAXARGS 20  // コマンド引数の上限
#define ARGLEN  100 // トークンのサイズ

char* makestring( char* buf );
int   execute( char* arglist[] );

int main( void )
{
    char* arglist[MAXARGS + 1 ]; // ポインタの配列
    char* makestring();          // メモリの確保などを実行
    char  argbuf[ARGLEN];        // 入出力を読み込む
    int   numargs = 0;           // 配列の添字

    while( numargs < MAXARGS ) {
        printf( "Arg[%d]? ", numargs );
        if( fgets( argbuf, ARGLEN, stdin ) && *argbuf != '\n' ) {
            arglist[numargs++] = makestring( argbuf );
        }
        else {
            if( numargs > 0 ) {
                arglist[numargs] = NULL;
                execute( arglist );
                numargs = 0;
            }
        }
    }

    return 0;
}

int execute( char* arglist[] )
// execvp を使ってコマンドを起動する
{
    execvp( arglist[0], arglist );
    perror( "execvp failed" );
    exit( 1 );
}

char* makestring( char* buf )
// 改行を取り除き、文字列の記憶領域を作る
{
    char* cp;

    buf[strlen(buf) - 1] = '\0';
    cp = (char *)malloc( strlen( buf ) + 1 );

    if( cp == NULL ) {
        fprintf( stderr, "no memory\n" );
        exit( 1 );
    }
    strcpy( cp, buf );
    return cp;
}
