/* ticker_demo.c
 *    目的：interval の使い方のデモ
 *    概要：インターバル大麻を使って周期的にシグナルを生成する
 *          シグナルはカウントダウンのためにキャッチする
 */

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>   // pause関数を利用するために追加
#include <stdlib.h>   // exit関数を利用するために追加

int set_ticker( int n_msecs );

int main( void )
{
    void countdown( int );

    signal( SIGALRM, countdown );
    if( set_ticker( 500 ) == -1 ) perror( "set_ticker error : " );
    else {
        while( 1 ) pause();
    }
    return 0;
}

void countdown( int signum )
{
    static int num = 10;
    printf( "%d ..", num-- );
    fflush( stdout );
    if( num < 0 ) {
        printf( "DONE!\n" );
        exit( 0 );
    }
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
