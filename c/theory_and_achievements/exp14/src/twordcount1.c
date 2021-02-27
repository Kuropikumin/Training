/* twordcount1.c - 2つのファイルのためのマルチスレッド wc バージョン1 */

#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h> // exit関数を利用するのに必要

int total_words;

int main( int ac, char* av[] )
{
    pthread_t t1; // スレッドその1
    pthread_t t2; // スレッドその2
    void*     count_words( void* );

    if( ac != 3 ) {
        printf( "usage: %s file file2\n", av[0] );
        exit( 1 );
    }

    total_words = 0;
    pthread_create( &t1, NULL, count_words, ( void* )av[1] );
    pthread_create( &t2, NULL, count_words, ( void* )av[2] );
    pthread_join( t1, NULL );
    pthread_join( t2, NULL );

    printf( "%5d: total words\n", total_words );
    return 0;
}

void* count_words( void* f )
{
    char* filename = ( char* )f;
    FILE* fp;
    int   c;
    int   prevc = '\0';

    if( ( fp = fopen( filename, "r" ) ) != NULL ) {
        while( ( c = getc( fp ) ) != EOF ) {
            if( isalnum( c ) && isalnum( prevc ) ) total_words++;
            prevc = c;
        }
        fclose( fp );
    }
    else perror( filename );

    return NULL;
}
