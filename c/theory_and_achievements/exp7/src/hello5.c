/* hello5.c
 *     目的：メッセージを画面内で跳ね返らせる
 */

//#include <stdio.h>
#include <curses.h>
#include <unistd.h> // sleep関数を利用するために追加

#define LEFTEDGE  10
#define RIGHTEDGE 20
#define ROW       10

int main( void )
{
    char* message = "Hello";
    char* blank   = "     ";
    int   dir     = 1;
    int   pos     = LEFTEDGE;


    initscr();                // curses をオンにする

    clear();                  // 描画をクリアする
    while( 1 ) {
        move( ROW, pos );                // ROW( 10 )行 pos列に移動する
        addstr( message );               // 文字列を追加する
        move( LINES - 1, COLS - 1 );     // カーソルを止める
        refresh();                       // 画面を更新する
        sleep( 1 );                      // 1秒スリープする
        move( ROW, pos );                // ROW( 10 )行 pos列に移動する
        addstr( blank );                 // 文字列を消去する

        pos += dir;                      // 位置を先に進める
        if( pos >= RIGHTEDGE ) dir = -1; // 跳ね返りチェック（右端なら左方向へ進む）
        if( pos <= LEFTEDGE )  dir = +1; // 跳ね返りチェック（左端なら右方向へ進む）
    }

    endwin();                 // cursesをオフにする

    return 0;
}
