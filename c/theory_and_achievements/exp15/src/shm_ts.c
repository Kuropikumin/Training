/* shm_ts.c - 共有メモリを使う時報サーバ、ちょっと特殊なアプリケーション */

#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <unistd.h> // sleep関数を利用するのに必要
#include <string.h> // strcpy関数を利用するのに必要

#define TIME_MEM_KEY 99                 // ファイル名のようなもの
#define SEG_SIZE     ( ( size_t ) 100 ) // セグメントサイズ
#define oops( m, x ) { perror( m ); exit( x ); }

int main( void )
{
    int   seg_id;
    char* mem_ptr;
    char* ctime();
    long  now;
    int   n;

    // 共有メモリセグメントを作る
    seg_id = shmget( TIME_MEM_KEY, SEG_SIZE, IPC_CREAT|0777 );
    if( seg_id == -1 ) oops( "shmget", 1 );

    // 共有メモリセグメントにアタッチし、アタッチした場所を指すポインタを取得する
    mem_ptr = shmat( seg_id, NULL, 0 );
    if( mem_ptr == ( void* ) -1 ) oops( "shmat", 2 );

    // 1分間実行
    for( n = 0; n < 60; n++ ) {
        time( &now );
        strcpy( mem_ptr, ctime( &now ) );
        sleep( 1 );
    }

    // 共有メモリセグメントを削除する
    shmctl( seg_id, IPC_RMID, NULL );

    return 0;
}
