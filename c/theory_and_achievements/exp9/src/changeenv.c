/* changeenv. - 環境の変更方法を学ぶ
 *              env を呼び出して新しい設定を表示する
 */

#include <stdio.h>
#include <unistd.h>

extern char** environ; // 文字列配列を指す

int main( void )
{
    char* table[3];

    table[0] = "TERM=vt100";          // テーブルに情報をセット
    table[1] = "HOME=/on/the/range";
    table[2] = 0;

    environ = table;                  // テーブルのアドレスをセットする

    execlp( "env", "env", NULL );     // env プログラムを実行する

    return 0;
}
