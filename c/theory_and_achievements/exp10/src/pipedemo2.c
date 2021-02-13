/* pipedemo2.c
 * 目的：fork() 呼び出しによって、パイプアクセスが重複する様子を示す
 *       親はパイプを読み書きし続けるが、子もパイプに書き込む
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <string.h> // strlen関数を利用するのに必要

#define CHILD_MESS   "I want a cookie\n"
#define PAR_MESS     "testing...\n"
#define oops( m, x ) { perror( m ); exit( x ); }

int main( void )
{
    int  len;         // 書き込み用
    int  pipefd[2];    // 2つのファイルディスクリプタ
    int  read_len;
    char buf[BUFSIZ]; // 読み出し側のためのバッファ

    // パイプを作成する
    if( pipe( pipefd ) == -1 ) oops( "could not make pipe", 1 );

    switch( fork() ) {
        case -1:
            oops( "cannot fork", 2 );

        // 子プロセスは 5秒ごとにパイプに書き込みをする
        case 0:
            len = strlen( CHILD_MESS );
            while( 1 ) {
                if( write( pipefd[1], CHILD_MESS, len ) != len ) oops( "write", 3 );
                sleep( 5 );
            }

        // 親プロセスはパイプを読み出し、パイプへの書き込みも行う
        default:
            len = strlen( PAR_MESS );
            while( 1 ) {
                if( write( pipefd[1], PAR_MESS, len ) != len ) oops( "write", 4 );
                sleep( 1 );
                read_len = read( pipefd[0], buf, BUFSIZ );
                if( read_len <= 0 ) break;
                write( 1, buf, read_len );
            }
    }

    return 0;
}
