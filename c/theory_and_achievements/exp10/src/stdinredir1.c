/* stdinredir1.c
 *     目的：ファイルディスクリプタ0 を端末からファイルとの接続に置き換えて、
 *           標準入力をリダイレクトする方法を学ぶ
 * 操作内容：標準入力の 3 行分のデータを読みだしてから fd0 をクローズして、
 *           ディスクファイルをオープンしてから、さらに標準入力を 3 行読み出す
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <unistd.h> // close関数を利用するのに必要

int main( )
{
    int  fd;
    char line[100];

    // 3 行読んで出力する
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );

    // 入力をリダイレクトする
    close( 0 );   // 標準入力のファイルディスクリプタである 0 をクローズ
    fd = open( "/etc/passwd", O_RDONLY );

    // ファイルディスクリプタ 0 が使われている場合
    if( fd != 0 ) {
        // ファイルディスクリプタは開いている番号のうち、最も小さい番号を利用するため、
        // close と openの間に別のプログラムが実行されている可能性がある
        fprintf( stderr, "Could not open data as fd 0\n" );
        exit( 1 );
    }

    // 3 行読んで出力する
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );
    fgets( line, 100, stdin );
    printf( "%s", line );

    return 0;
}
