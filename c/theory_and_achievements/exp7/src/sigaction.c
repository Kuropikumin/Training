/* sigaction.c
 *    目的：sigaction() の使い方を示す
 *    特徴：Ctrl+Cの処理中に、Ctrl+\をブロックする
 *          Ctrl+Cハンドラを設定しなおさないので、2度目で終了する
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h> // sleep関数を利用するために追加
#include <string.h> // strncmp関数を利用するために追加

#define INPUTLEN 100

int main( int ac, char* av[] )
{
    struct sigaction newhandler;        // 新しい設定
    sigset_t         blocked;           // ブロックされるシグナルの集合
    void             inthandler( int ); // ハンドラ
    char             x[INPUTLEN];

    // 2つのメンバを最初にロードする
    newhandler.sa_handler = inthandler;                // ハンドラ関数
    newhandler.sa_flags   = SA_RESETHAND | SA_RESTART; // オプション

    // ブロックされるシグナルリストを作る
    sigemptyset( &blocked );          // すべてのビットをクリアする
    sigaddset  ( &blocked, SIGQUIT ); // リストに SIGQUIT を追加する

    newhandler.sa_mask = blocked;

    if( sigaction( SIGINT, &newhandler, NULL ) == -1 ) {
        perror( "sigaction" );
    }
    else {
        while( 1 ) {
            fgets( x, INPUTLEN, stdin );
            printf( "input: %s", x );
        }
    }

    return 0;
}

void inthandler( int s )
{
    printf( "Received signal %d .. waiting\n", s );
    sleep( s );
    printf( "DONE handling signal %d .. waiting\n", s );
}

