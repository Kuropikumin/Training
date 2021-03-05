/* file_ts2.c - 現在の日時を共有メモリで共有する。ロックのためにセマフォを使う
 *   使い方：file_ts2 <ファイル名>
 *     動作：プログラムは 99 というキーを持つ共有メモリを使い、
 *           9900 というキーを持つセマフォを使う
 */

#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <signal.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <string.h> // strcpy関数を利用するのに必要
#include <unistd.h> // sleep関数を利用するのに必要

#define TIME_MEM_KEY 99   // ファイル名のようなもの
#define TIME_SEM_KEY 9900
#define SEG_SIZE     ( ( size_t )100 )
#define oops( m, x ) { perror( m ); exit( x ); }

union semun { int val; struct semid_ds* buf; ushort* array; };
int   seg_id, semset_id; // cleanup() のためにグローバルにしてある

// 関数設定
void cleanup( int );
void set_sem_value( int, int, int );
void wait_and_lock( int );
void release_lock( int );

int main( int ac, char* av[] )
{
    char*  mem_ptr;
    char*  ctime();
    time_t now;
    int    n;

    // 共有メモリセグメントを作る
    seg_id = shmget( TIME_MEM_KEY, SEG_SIZE, IPC_CREAT|0777 );
    if( seg_id == -1 ) oops( "shmget", 1 );

    // 共有メモリセグメントにアタッチし、アタッチした場所を指すポイントを取得する
    mem_ptr = shmat( seg_id, NULL, 0 );
    if( mem_ptr == ( void* )-1 ) oops( "shmat", 2 );

    // セマフォセットを作る： キーは9900、セマフォは2個
    // モード rw-rw-rw-
    semset_id = semget( TIME_SEM_KEY, 2, ( 0666|IPC_CREAT|IPC_EXCL ) );
    if( semset_id == -1 ) oops( "semget", 3 );

    set_sem_value( semset_id, 0, 0 ); //カウンタの値はともに 0
    set_sem_value( semset_id, 1, 0 );

    signal( SIGINT, cleanup );

    // 1分間実行
    for( n = 0; n < 60; n++ ) {
        // 時刻の取得
        time( &now );
        printf( "\tshm_ts2 waiting for lock\n" );

        // メモリのロック
        wait_and_lock( semset_id );
        printf( "\tshm_ts2 updating memory\n" );

        // メモリへの書き込み
        strcpy( mem_ptr, ctime( &now ) );
        sleep( 5 );

        // ロック解除
        release_lock( semset_id );
        printf( "\tshm_ts2 released lock\n" );
        sleep( 1 );
    }

    cleanup( 0 );

    return 0;
}

void cleanup( int n )
{
    shmctl( seg_id,    IPC_RMID, NULL );           // 共有メモリの削除
    semctl( semset_id, 0,        IPC_RMID, NULL ); // セマフォセットの削除
}

void set_sem_value( int semset_id, int semnum, int val )
// セマフォを初期化する
{
    union semun initval;

    initval.val = val;
    if( semctl( semset_id, semnum, SETVAL, initval ) == -1 ) oops( "semctl", 4 );
}

void wait_and_lock( int semset_id )
/*
 * 2要素の処理セットを作って実行する
 * n_readers が 0 になるのを待って、n_writers をインクリメントする
 */
{
    struct sembuf actions[2]; //処理セット

    actions[0].sem_num = 0;        // sem[0] は n_readers
    actions[0].sem_flg = SEM_UNDO; // 自動クリーンアップ
    actions[0].sem_op  = 0;        // 読み手がなくなるまで待つ

    actions[1].sem_num = 1;        // sem[1] は n_writers
    actions[1].sem_flg = SEM_UNDO; // 自動クリーンアップ
    actions[1].sem_op  = 1;        // n_writersをインクリメント

    if( semop( semset_id, actions, 2 ) == -1 ) oops( "semop: locking", 10 );
}

void release_lock( int semset_id )
/*
 * 1要素の処理セットを使って実行する
 * n_writers をデクリメントする
 */
{
    struct sembuf actions[1];

    actions[0].sem_num = 1;        // sem[0] は n_writers
    actions[0].sem_flg = SEM_UNDO; // 自動クリーンアップ
    actions[0].sem_op  = -1;       // n_writers をデクリメントする

    if( semop( semset_id, actions, 1 ) == -1 ) oops( "semop: locking", 10 );
}
