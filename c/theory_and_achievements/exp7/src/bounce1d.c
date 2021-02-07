/* bounce1d.c
 *        目的：ユーザが速度と向きを制御できるアニメーションを作成する
 *        注意：アニメーションはハンドラが実現する
 *              メインプログラムはキーボード入力を読み出す
 *  コンパイル： gcc bounce1d.c set_ticker.c -lcurses -o bounce1d
 */

#include <stdio.h>
#include <signal.h>
#include <curses.h>
#include <unistd.h> // sleep関数を利用するために追加
#include <string.h> // strncmp関数を利用するために追加
#include <sys/time.h>

// main と handler が使うグローバル設定
#define MESSAGE "hello"
#define BLANK   "     "

int row; // 現在の行
int col; // 現在の列
int dir; // 現在の進む方向

void move_msg( int signum );
int  set_ticker( int n_msecs );

int main( int ac, char* av[] )
{
    int  delay;           // 大きければ大きいほど遅い
    int  ndelay;          // 新しい遅延
    int  c;               // ユーザ入力
    void move_msg( int ); // タイマハンドラ

    initscr();
    crmode();
    noecho();
    clear();

    row   = 10;  // 開始位置（行）
    col   = 0;   // 開始位置（列）
    dir   = 1;   // 進む方向（行番号を増やすか減らすか）
    delay = 200; // ディレイ秒数（ミリ秒）

    move( row, col );
    addstr( MESSAGE );
    signal( SIGALRM, move_msg );
    set_ticker( delay );

    while( 1 ) {
        ndelay = 0;
        c = getch();
        if( c == 'Q' )              break;
        if( c == ' ' )              dir = -dir;
        if( c == 'f' && delay > 2 ) ndelay = delay/2;
        if( c == 's' )              ndelay = delay*2;
        if( ndelay > 0 )            set_ticker( delay = ndelay );
    }

    endwin();
    return 0;
}

void move_msg( int signum )
{
    signal( SIGALRM, move_msg ); // 念のためリセット
    move( row, col );            // 現在の表示位置に移動
    addstr( BLANK );             // 現在の文字を削除
    col += dir;                  // 移動後の行を計算
    move( row, col );            // 移動後の表示位置に移動
    addstr( MESSAGE );           // メッセージを描画
    refresh();                   // 表示

    // 境界条件の処理
    if     ( dir == -1 && col <= 0 )                        dir = 1;
    else if( dir == 1  && col + strlen( MESSAGE ) >= COLS ) dir = -1;
}

int set_ticker( int n_msecs )
/* set_ticker( number_of_milliseconds )
 *     SIGALRM が周期的に発行されるようにインターバルタイマを設定する
 *     エラーなら -1, 成功なら 0 を返す
 *     引数はミリ秒単位なので、秒とマイクロ病の組み合わせに変換する
 *     注意：set_ticerk( 0 )とすると、シグナルは送られない
 */
{
    struct itimerval new_timeset;
    long             n_sec, n_usecs;

    n_sec   = n_msecs/1000;                    // ミリ秒->秒への変換
    n_usecs = ( n_msecs%1000 )*1000L;          // ミリ秒の1秒以下の部分

    new_timeset.it_interval.tv_sec  = n_sec;   // 反復インターバルの設定
    new_timeset.it_interval.tv_usec = n_usecs; // 新しい値
    new_timeset.it_value.tv_sec     = n_sec;   // n_sec の値を保存する
    new_timeset.it_value.tv_usec    = n_usecs; // n_usec の値を保存する

    return setitimer( ITIMER_REAL, &new_timeset, NULL );
}
