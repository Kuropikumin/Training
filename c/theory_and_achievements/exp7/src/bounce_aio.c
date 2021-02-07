/* bounce_aio.c
 *        目的：ユーザ制御のアニメーション、aio_readなどを使う
 *        注意：set_ticker()はSIGALRMを送り、ハンドラはアニメーションを実現する
 *              キーボードはSIGIOを送り、main は pause() を呼び出すだけである。
 *  コンパイル： gcc bounce_async.c -lrt -lcurses -o bounce1d
 */

#include <stdio.h>
#include <signal.h>
#include <curses.h>
#include <aio.h>
#include <sys/time.h> // set_ticker部分で利用する
#include <unistd.h>   // pasue 関数で利用
#include <string.h>   // strlen関数で利用

// main と handler が使うグローバル設定
#define MESSAGE "hello"
#define BLANK   "     "

int row   =  10; // 現在の行 & 初期設定
int col   =   0; // 現在の列 & 初期設定
int dir   =   1; // 現在の進む方向 & 初期設定
int delay = 200; // 1フレーム当たりの秒数（ミリ秒） & 初期設定
int done  =   0;

struct aiocb kbcbuf;  // aio制御バッファ

int  set_ticker( int n_msecs );

int main( int ac, char* av[] )
{
    void on_alarm( int );
    void on_input( int );
    void setup_aio_buffer();

    initscr(); // 画面のセットアップ
    crmode();
    noecho();
    clear();

    signal( SIGIO, on_input );    // ハンドラのセット
    setup_aio_buffer();           // aio制御バッファを初期化する
    aio_read( &kbcbuf );          // 読み出しを要求する
    signal( SIGALRM, on_alarm );  // タイマハンドラを組み込む
    set_ticker( delay );          // タイマハンドラスタート

    mvaddstr( row, col, MESSAGE );

    while( !done ) {
        pause();
    }

    endwin();
    return 0;
}

void on_input( int signum )
{
    int   c  = getch();
    char* cp = (char*) kbcbuf.aio_buf;

    // エラーチェック
    if( aio_error( &kbcbuf ) != 0 ) perror( "reading failed" );

    if( aio_return( &kbcbuf ) == 1 ) {
        c = *cp;
        if     ( c == 'Q' || c == EOF ) done = 1;
        else if( c == ' ' )             dir = -dir;
    }

    // 新しい要求
    aio_read( &kbcbuf );
}

void on_alarm( int signum )
{
    signal( SIGALRM, on_alarm );   // signalのリセット
    mvaddstr( row, col, BLANK );   // 現在の文字を削除
    col += dir;                    // 移動後の行を計算
    mvaddstr( row, col, MESSAGE ); // メッセージを描画
    refresh();                   // 表示

}

void setup_aio_buffer()
/*
 * 構造体メンバを設定する
 * まず、read(fd, buf, num) と同様の引数とオフセットを指定する
 * 次に何をすべきか（シグナルを送る）と度のシグナルか（SIGIO）を指定する
 */
{
    static char input[1]; // 入力の1文字

    // 何を読むべきかを記述する
    kbcbuf.aio_fildes = 0;     // 標準入力
    kbcbuf.aio_buf    = input; // バッファ
    kbcbuf.aio_nbytes = 1;     // 読み出す文字数
    kbcbuf.aio_offset = 0;     // ファイルのオフセット

    // 読み出しが完了したときに何をすべきかを記述する
    kbcbuf.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
    kbcbuf.aio_sigevent.sigev_signo  = SIGIO;        // SIGIOを送る

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
