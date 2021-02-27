/* hello_single.c - シングルスレッドの hello world プログラム */

#include <stdio.h>
#include <unistd.h> // sleep関数を利用するのに必要

#define NUM 5

int main( void )
{
    void print_msg( char* );

    print_msg( "hello" );
    print_msg( "world\n" );

    return 0;
}

void print_msg( char* m )
{
    int i;
    for( i = 0; i < NUM; i++ ) {
        printf( "%s", m );
        fflush( stdout );
        sleep( 1 );
    }
}
