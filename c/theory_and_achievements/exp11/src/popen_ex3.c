/* popen_ex3.c
 *   目的：popen を使って標準入力から読み出すプロセスの書き込みについて学ぶ
 *   詳細：2人のユーザに電子メールを書く
 *   注意：fprintfを使って送信データを成型するのがいかに簡単かに注意する
 */

#include <stdio.h>

int main( void )
{
    FILE* fp;

    // コマンドをオープンする
    fp = popen( "mail admin backup", "w" );
    fprintf( fp, "Error witch backup!!\n" );
    pclose( fp ); // 重要

    return 0;
}
