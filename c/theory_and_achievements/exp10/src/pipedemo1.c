/* pipedemo1.c
 * 目的：パイプの作り方と使い方を示す
 * 効果：パイプを作成し、書き込み側に出力し、読み出し側から読み出す
 *       回りくどいが、パイプがどのようなものかはわかる
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <string.h> // strlen関数を利用するのに必要

int main( void )
{
    int len;
    int i;
    int apipe[2];     // 2つのファイルディスクリプタ
    char buf[BUFSIZ]; // 読み出し側のためのバッファ

    // パイプを作成する
    if( pipe( apipe ) == -1 ) {
        perror( "could not make pipe" );
        exit( 1 );
    }
    printf( "Got a pipe! It is file descriptors: { %d, %d }\n", apipe[0], apipe[1] );

    // 標準入力を読み出し、パイプに書き込み、パイプから読み出して出力する
    while( fgets( buf, BUFSIZ, stdin ) ) {

        // パイプに書き込む
        len = strlen( buf );
        if( write( apipe[1], buf, len ) != len ) {
            perror( "Writing to pipe" );
            break;                       // pipe
        }
        for( i = 0; i < len; i++ ) buf[i] = 'X'; // 消去

        // パイプから読み出す
        len = read( apipe[0], buf, BUFSIZ );
        if( len == -1 ) {
            perror( "reading from pipe" );
            break;
        }

        // 標準出力に送り出す
        if( write( 1, buf, len ) != len ) {
            perror( "writing to stdout" );
            break;
        }
    }

    return 0;
}
