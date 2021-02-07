/* bounce2d1.c
 *        目的：2d における描画の制御方法を学ぶ
 *      仕様書：文字（デフォルトでは 'o'）を画面の端で弾ませる
 *              動きは複数のパラメータによって制御される
 *              キーボード読み出しでブロックされるが、タイマチックはSIGALRMを送り、
 *              それは ball_move にキャッチされる
 *  ユーザ入力：s 横方向のスピードを下げる S 縦方向のスピードを下げる
 *              f 横方向のスピードを上げる F 縦方向のスピードを上げる
 *              Q 終了
 *  コンパイル： gcc bounce2d1.c -lcurses -o bounce2d1
 */

#include <stdio.h>
#include <signal.h>
#include <curses.h>
#include <unistd.h>   // sleep関数を利用するために追加
#include <string.h>   // strncmp関数を利用するために追加
#include <sys/time.h> // set_ticker 部分で必要

#include "./header/bounce.h" // ユーザ設定ヘッダ

struct ppball the_ball;

// メインループ
void set_up();
void wrap_up();
void ball_move( int signum );
int  bounce_or_lose( struct ppball* bp );
int  set_ticker( int n_msecs );

int main( int ac, char* av[] )
{
    int c;

    set_up();

    while( ( c = getchar() ) != 'Q' ) {
        if     ( c == 'f' ) the_ball.x_ttm--;
        else if( c == 's' ) the_ball.x_ttm++;
        else if( c == 'S' ) the_ball.y_ttm++;
        else if( c == 'F' ) the_ball.y_ttm++;
    }

    wrap_up();
    return 0;
}

void set_up()
// 構造体、そのほかのものを初期化する
{
    void ball_move( int );

    the_ball.y_pos  = Y_INIT;
    the_ball.x_pos  = X_INIT;
    the_ball.y_ttg  = the_ball.y_ttm = Y_TTM;
    the_ball.x_ttg  = the_ball.x_ttm = X_TTM;
    the_ball.y_dir  = 1;
    the_ball.x_dir  = 1;
    the_ball.symbol = DFL_SYMBOL;

    initscr();
    noecho();
    crmode();

    signal( SIGINT, SIG_IGN );
    mvaddch( the_ball.y_pos, the_ball.x_pos, the_ball.symbol );
    refresh();

    signal( SIGALRM, ball_move );
    set_ticker( 1000/TICKS_PER_SEC );
}

void wrap_up()
{
    set_ticker( 0 );
    endwin();
}

void ball_move( int signum )
{
    int y_cur, x_cur, moved;

    signal( SIGALRM, SIG_IGN ); // このタイミングでは SIGALRM をキャッチしないようにする
    y_cur = the_ball.y_pos;
    x_cur = the_ball.x_pos;
    moved = 0;

    if( the_ball.y_ttm > 0 && the_ball.y_ttg-- == 1 ) { // y軸の変更タイミングである場合
        the_ball.y_pos += the_ball.y_dir;               // 移動
        the_ball.y_ttg  = the_ball.y_ttm;               // 変更タイミングのリセット
        moved = 1;                                      // 移動した記録
    }

    if( the_ball.x_ttm > 0 && the_ball.x_ttg-- == 1 ) { // x軸の変更タイミングである場合
        the_ball.x_pos += the_ball.x_dir;               // 移動
        the_ball.x_ttg  = the_ball.x_ttm;               // 変更タイミングのリセット
        moved = 1;                                      // 移動した記録
    }

    if( moved ) { // 移動した場合
        mvaddch( y_cur, x_cur, BLANK );
        mvaddch( y_cur, x_cur, BLANK );
        mvaddch( the_ball.y_pos, the_ball.x_pos, the_ball.symbol );
        bounce_or_lose( &the_ball );
        refresh();
    }
    signal( SIGALRM, ball_move ); // 信頼性のないシステム用
}

int bounce_or_lose( struct ppball* bp )
{
    int return_val = 0;

    if( bp->y_pos == TOP_ROW ) {
        bp->y_dir  = 1;
        return_val = 1;
    }
    else if ( bp->y_pos == BOT_ROW ) {
        bp->y_dir  = -1;
        return_val = 1;
    }

    if( bp->x_pos == LEFT_EDGE ) {
        bp->x_dir  = 1;
        return_val = 1;
    }
    else if ( bp->x_pos == RIGHT_EDGE ) {
        bp->x_dir  = -1;
        return_val = 1;
    }

    return return_val;

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
