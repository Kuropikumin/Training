/* incprint.c - 片方のスレッドがインクリメントして、もう片方が出力する */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // sleep 関数を利用するのに必要

#define NUM 5

int counter = 0;

int main( void )
{
    pthread_t t1;                   // 別スレッド
    void*     print_count( void* ); // 別スレッドで実行する関数
    int       i;

    pthread_create( &t1, NULL, print_count, NULL );
    for( i = 0; i < NUM; i++ ) {
        counter++;
        sleep( 1 );
    }

    pthread_join( t1, NULL );

    return 0;
}

void* print_count( void* m )
{
    int i;
    for( i = 0; i< NUM; i++ ) {
        printf( "count = %d\n", counter );
        sleep( 1 );
    }
    return NULL;
}
