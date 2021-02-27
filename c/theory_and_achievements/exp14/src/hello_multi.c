/* hello_single.c - マルチスレッドの hello world プログラム */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // sleep関数を利用するのに必要

#define NUM 5

int main( void )
{
    pthread_t t1;                 // スレッドその1
    pthread_t t2;                 // スレッドその2
    void*     print_msg( void* );

    pthread_create( &t1, NULL, print_msg, ( void* )"hello" );
    pthread_create( &t2, NULL, print_msg, ( void* )"world\n" );

    pthread_join( t1, NULL );
    pthread_join( t2, NULL );

    return 0;
}

void* print_msg( void* m )
{
    char* cp = ( char* )m;
    int   i;
    for( i = 0; i < NUM; i++ ) {
        printf( "%s", cp );
        fflush( stdout );
        sleep( 1 );
    }
    return NULL;
}
