/* psh2.c -- prompting shell version 2
 *         目的：psh1の問題点であった、ワンショット問題（別コマンドを実行すると終了してしまう問題）を解消する
 *               execvp() を使うが、先にforc()を使い、シェルがほかのコマンドを実行するための
 *               子プロセスの終了を待てるようにする
 * 新しい問題点：シェルはシグナルをキャッチしてしまう。vi 実行後にctrl+Cを押してみる
 */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>   // execvp関数を利用するのに必要
#include <stdlib.h>   // exit関数、malloc関数を利用するのに必要
#include <sys/wait.h> // wait関数を利用するのに必要

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
// fork, execvp, wait を使ってコマンドを起動する
{
    int pid, exitstatus;

    pid = fork();
    switch( pid ) {
        case -1:
            perror( "fork failed" );
            exit( 1 );
        case 0:
            execvp( arglist[0], arglist );
            perror( "execvp failed" );
            exit( 1 );
        default:
            while( wait( &exitstatus ) != pid );
            printf( "child exited with status %d, %d\n", exitstatus >> 8, exitstatus&0377 );
    }

    return 0;
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
