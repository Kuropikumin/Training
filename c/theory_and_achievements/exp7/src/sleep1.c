/* sleep1.c
 *    目的：sleepの仕組みを示す
 *    使い方：sleep1
 *    概要：ハンドラを設定し、alarm(), pause() を呼び出して、再び目を覚ます
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h> // alarm, pause 関数を利用するために追加
//#define  SHHHH "SHHHHHHHHH"

int main( void )
{
    void wakeup( int );

    printf( "about to sleep for 4 seconds\n" );
    signal( SIGALRM, wakeup );                  // SIGALRMをキャッチする関数を作成
    alarm( 4 );                                 // 目覚ましの設定をする
    pause();                                    // alarmからのシグナルが来るまで待つ
    printf( "Morning so soon?\n" );             // 処理に戻る
    return 0;
}

void wakeup( int signum )
{
    #ifndef SHHHH
        printf( "Alarm received from kernel\n" );
    #endif
}
