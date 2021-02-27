/* tanimate.c - マルチスレッド、curses, usleep() を使って複数の文字列を動かす
 *   アイデア：動く文字列 1つにつき 1つのスレッド、キーボードコントロールのための
 *             1つのスレッド、通信のために共有変数
 * コンパイル：gcc tanimate.c -lcurses -pthread -o tanimate
 *      to do：共有変数のためにロックが必要、画像処理に独自スレッドを与えられるとなおよい
 */

#include <stdio.h>
#include <curses.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // strlen関数を利用するのに必要

#define MAXMSG 10    // 文字列の個数上限
#define TUNIT  20000 // 時間の単位（マイクロ秒で指定）

struct propset {
    char* str;   // メッセージ
    int   row;   // 行
    int   delay; // 上記単位で指定した遅延
    int   dir;   // +1 or -1
};

pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;

// 関数設定
int setup( int, char**, struct propset* );

int main( int ac, char* av[] )
{
    struct propset   props[MAXMSG]; // 文字列のプロパティ
           int       c;             // ユーザ入力
           pthread_t thrds[MAXMSG]; // スレッド
           void*     animate();     // スレッド実行関数
           int       num_msg;       // 文字列の個数
           int       i;

    if( ac == 1 ) {
        printf( "usage: tanimate string ..\n" );
        exit( 1 );
    }

    num_msg = setup( ac - 1, av + 1, props );

    // すべてのスレッドを作成する
    for( i = 0; i < num_msg; i++ ) {
        if( pthread_create( &thrds[i], NULL, animate, &props[i] ) ) {
            fprintf( stderr, "error creating thread" );
            endwin();
            exit( 0 );
        }
    }

    // ユーザ入力を処理する
    while( 1 ) {
        c = getch();

        if( c == 'Q' ) break;
        if( c == ' ' ) {
            for( i = 0; i < num_msg; i++ ) props[i].dir = -props[i].dir;
        }
        if( c >= '0' && c <= '9' ) {
            i = c - '0';
            if( i < num_msg ) {
                props[i].dir = -props[i].dir;
            }
        }
    }

    // すべてのスレッドをキャンセルする
    pthread_mutex_lock( &mx );
    for( i = 0; i < num_msg; i++ ) pthread_cancel( thrds[i] );
    endwin();

    return 0;
}

int setup( int nstrings, char* strings[], struct propset props[] )
{
    int num_msg = ( nstrings > MAXMSG ? MAXMSG : nstrings );
    int i;

    // 個々の文字列に行と速度を割り当てる
    srand( getpid() );
    for( i = 0; i < num_msg; i++ ) {
        props[i].str   = strings[i];             // メッセージ登録
        props[i].row   = i;                      // 行登録
        props[i].delay = 1 + ( rand()%15 );      // スピード設定
        props[i].dir   = ( ( rand()%2 ) ? 1: -1 ); // 文字の動く向き設定
    }

    // curses をセットアップする
    initscr();
    crmode();
    noecho();
    clear();
    mvprintw( LINES - 1, 0, "'Q' to quit, '0'..'%d' to bounce", num_msg - 1 );
    return num_msg;
}

void* animate( void* arg )
// 各スレッドで実行されるコード
{
    struct propset* info = arg;
           int      len  = strlen( info->str ) + 2;
           int      col  = rand()%( COLS - len - 3 );

    while( 1 ) {
        usleep( info->delay*TUNIT );

        pthread_mutex_lock( &mx );       // 同時にcursesを呼び出せるスレッドは1つだけにする
            move( info->row, col );
            addch( ' ' );
            addstr( info->str );
            addch( ' ' );
            move( LINES - 1, COLS - 1 ); // カーソルの移動
            refresh();                   // 表示
        pthread_mutex_unlock( &mx );     // curses の利用はここで終了

        // 項目を次の列に移動して跳ね返りをチェックする
        col += info->dir;

        if     ( col <= 0 && info->dir == -1 )         info->dir = 1;
        else if( col + len >= COLS && info->dir == 1 ) info->dir = -1;
    }
}
