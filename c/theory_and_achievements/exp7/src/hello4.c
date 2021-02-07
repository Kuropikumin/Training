/* hello4.c
 *     目的：アニメーションのために、消去、時間、描画を使う方法を示す
 */

#include <stdio.h>
#include <curses.h>
#include <unistd.h> // sleep関数を利用するために追加

int main( void )
{
    int i;
    initscr();                // curses をオンにする

    clear();                  // 描画をクリアする
    for( i = 0; i < LINES; i++ ) {
        move( i, 2*i );            // i行 2i列に移動する
        if( i%2 == 1 ) standout(); // 偶数行（最初が0なのでiの奇数偶数とは逆になる）なら強調する
        addstr( "Hello, World!" ); // 文字列を追加する
        if( i%2 == 1 ) standend(); // 強調を戻す
        sleep( 1 );                // 1秒スリープする
        refresh();                 // 画面を更新する

        move( i, 2*i );            // 元に戻る
        addstr( "             " ); // Hello, World!を削除する
    }

    endwin();                 // cursesをオフにする

    return 0;
}
