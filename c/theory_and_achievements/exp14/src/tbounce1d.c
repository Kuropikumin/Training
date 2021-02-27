/* tbounce1d.c - 2つのスレッドを使ってコントロールされたアニメーション
 *       注意：1つのスレッドがアニメーションを処理し、
 *             もう1つのスレッドがキーボード入力を処理する
 * コンパイル：gcc tbounce1d.c -lcurses -pthread -o tbounce1d
 */

#include <stdio.h>
#include <curses.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //strlen関数を利用するのに必要

#define MESSAGE " hello "

// 両方のスレッドが使う共通変数。ミューテックスが必要
int row;   // 現在の行
int col;   // 現在の列
int dir;   // 移動の方向
int delay; // 大きいほど遅くなる

int main( void )
{
    int       ndelay;     // 新しい遅延
    int       c;          // ユーザ入力
    pthread_t msg_thread; // スレッド
    void*     moving_msg();

    initscr();
    crmode();
    noecho();
    clear();

    row   = 10;  // 開始位置（行）
    col   = 0;   // 開始位置（列）
    dir   = 1;   // 行番号に1を加える
    delay = 200; // 200ミリ秒

    if( pthread_create( &msg_thread, NULL, moving_msg, MESSAGE ) ) {
        fprintf( stderr, "error creating thread" );
        endwin();
        exit( 0 );
    }

    while( 1 ) {
        ndelay = 0;
        c = getch();
        if( c == 'Q' )              break;
        if( c == ' ' )              dir = -dir;
        if( c == 'f' && delay > 2 ) ndelay = delay/2;
        if( c == 's' )              ndelay = delay*2;
        if( ndelay > 0 )            delay  = ndelay;
    }

    pthread_cancel( msg_thread );
    endwin();

    return 0;
}

void* moving_msg( char* msg )
{
    while( 1 ) {
        usleep( delay*1000 );
        move( row, col );
        addstr( msg );
        refresh();

        // 次の列に移動し、跳ね返りをチェックする
        col += dir;
        if     ( col <= 0 && dir == -1 )                   dir = 1;
        else if( col + strlen( msg ) >= COLS && dir == 1 ) dir = -1;
    }
}
