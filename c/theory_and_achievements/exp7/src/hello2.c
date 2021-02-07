/* hello2.c
 *     目的：ループ内で curses を使うために必要な技術を示す
 *     概要：初期化、描画、終了
 */

#include <stdio.h>
#include <curses.h>

int main( void )
{
    int i;
    initscr();                // curses をオンにする

    clear();                  // 描画をクリアする
    for( i = 0; i < LINES; i++ ) {
        move( i, 2*i );            // i行 2i列に移動する
        if( i%2 == 1 ) standout(); // 偶数行（最初が0なのでiの奇数偶数とは逆になる）なら強調する
        addstr( "Hello, World!");  // 文字列を追加する
        if( i%2 == 1 ) standend(); // 強調を戻す
    }

    refresh();                // 画面を更新
    getch();                  // ユーザ入力を待つ
    endwin();                 // cursesをオフにする

    return 0;
}
