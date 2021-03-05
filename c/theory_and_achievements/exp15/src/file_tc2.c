/* file_tc2.c - 現在の日時をファイルから読み出す。ロックのためにセマフォを使う
 *              プログラムは 99 というキーを持つ共有メモリを使い、9900 というキーを持つセマフォを使う
 */

#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h> // exit関数を利用するのに必要

#define TIME_MEM_KEY 99                          // ポート番号のようなもの
#define TIME_SEM_KEY 9900                        // ファイル名のようなもの
#define SEG_SIZE     ( ( size_t )100 )           // セグメントのサイズ
#define oops( m, x ) { perror( m ); exit( x ); }

union semun { int val; struct semid_ds* buf; ushort* array; };

// 関数設定
void wait_and_lock( int );
void release_lock( int );

int main( void )
{
    int   seg_id;
    char* mem_ptr;
    char* ctime();
    long  now;

    int   semset_id; //セマフォセットのID

    // 共有メモリセグメントを作る
    seg_id = shmget( TIME_MEM_KEY, SEG_SIZE, 0777 );
    if( seg_id == -1 ) oops( "shmget", 1 );

    // 共有メモリセグメントにアタッチし、アタッチした場所を指すポインタを取得する
    mem_ptr = shmat( seg_id, NULL, 0 );
    if( mem_ptr == ( void* ) -1 ) oops( "shmget", 2 );

    // 2このセマフォを持ち、キーが9900のセマフォセットに接続する
    semset_id = semget( TIME_SEM_KEY, 2, 0 );
    wait_and_lock( semset_id );

    printf( "The time, direct from memory: ..%s", mem_ptr );

    release_lock( semset_id );
    shmdt( mem_ptr );          // デタッチ。ここでは不要

    return 0;
}

void wait_and_lock( int semset_id )
/*
 * 2要素の処理セットを作って実行する
 * n_writers が 0 になるのを待って、n_readers をインクリメントする
 */
{
    union  semun  sem_info;   // プロパティ
    struct sembuf actions[2]; // 処理セット

    actions[0].sem_num = 1;        // sem[1] は n_writers
    actions[0].sem_flg = SEM_UNDO; // 自動クリーンアップ
    actions[0].sem_op  = 0;        // 0 になるのは待つ

    actions[1].sem_num = 0;        // sem[0] は n_readers
    actions[1].sem_flg = SEM_UNDO; // 自動クリーンアップ
    actions[1].sem_op  = 1;        // n_readersをインクリメント

    if( semop( semset_id, actions, 2 ) == -1 ) oops( "semop: locking", 10 );
}

void release_lock( int semset_id )
/*
 * 1要素の処理セットを作って実行する
 * n_readers をデクリメントする
 */
{
    union  semun  sem_info;   // プロパティ
    struct sembuf actions[1]; // 処理セット

    actions[0].sem_num = 0;        // sem[0] は n_readers
    actions[0].sem_flg = SEM_UNDO; // 自動クリーンアップ
    actions[0].sem_op  = -1;        // n_readers をデクリメントする

    if( semop( semset_id, actions, 1 ) == -1 ) oops( "semop: locking", 10 );
}
