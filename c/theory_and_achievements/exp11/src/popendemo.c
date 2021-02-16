/* popendemo.c
 *   目的：プログラムを標準入出力のためにオープンする方法を学ぶ
 * 重要ポイント：
 *         1. popen() は fopen() と同様に FILE* を返す
 *         2. popen() が返す FILE* は、すべての標準関数が読み書きに使える
 *         3. 終わったら pclose() を呼び出さなければならない
 */

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    FILE* fp;
    char  buf[100];
    int   i = 0;

    // コマンドをオープンする
    fp = popen( "who|sort", "r" );

    // コマンドから読み出しデータを標準出力する
    while( fgets( buf, 100, fp ) != NULL ) printf( "%3d %s", i++, buf );

    pclose( fp ); // 重要

    return 0;
}
