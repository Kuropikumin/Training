/* stdinredir2.c
 *     目的：標準入力をリダイレクトするための 2種類の方法を学ぶ
 *           #define を使ってどちらを利用するか選択する
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <unistd.h> // close関数を利用するのに必要

#define CLOSE_DUP // オープン、クローズ、複製、   クローズ
// #define USE_DUP2  オープン、複製2、   クローズ

int main( )
{
    int  fd;
    int  newfd;
    char line[100];

    // 3 行読んで出力する
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );

    // 入力をリダイレクトする
    fd = open( "/etc/passwd", O_RDONLY ); // オープン処理

#ifdef CLOSE_DUP       // CLOSE_DUPが定義されている場合
    close( 0 );        // クローズ処理
    newfd = dup( fd ); // 複製処理
#else
    newfd = dup2( fd, 0 ); // 複製2処理
#endif
    // ファイルディスクリプタ 0 が使われている場合
    if( newfd != 0 ) {
        // ファイルディスクリプタは開いている番号のうち、最も小さい番号を利用するため、
        // close と openの間に別のプログラムが実行されている可能性がある
        fprintf( stderr, "Could not open data as fd 0\n" );
        exit( 1 );
    }
    close( fd ); // クローズ処理

    // 3 行読んで出力する
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );

    return 0;
}
