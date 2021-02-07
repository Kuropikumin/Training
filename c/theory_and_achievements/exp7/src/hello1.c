/* hello1.c
 *     目的：curses を使うために必要な最小限の呼び出しをする
 *     概要：初期化、描画、入力待ち、終了
 */

#include <stdio.h>
#include <curses.h>

int main( void )
{
    initscr();                // curses をオンにする

                              // リクエストを送る
    clear();                  // 描画をクリアする
    move( 10, 20 );           // 10行 20列に移動する
    addstr( "Hello, World!"); // 文字列を追加する
    move( LINES - 1, 0 );     // 左隅に移動する

    refresh();                // 画面を更新
    getch();                  // ユーザ入力を待つ

    endwin();                 // cursesをオフにする

    return 0;
}
