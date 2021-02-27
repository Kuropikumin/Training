/* twordcount3.c - 2つのファイルのためのマルチスレッド wc バージョン3
 *                 ファイルごとにカウンタを1つずつ作る
 */

#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h> // exit関数を利用するのに必要

struct arg_set { // 1つの引数に2つの値を詰め込む
    char* fname; // 解析するファイル名
    int   count; // ファイル名に対するカウント数
};

int main( int ac, char* av[] )
{
           pthread_t t1;    // スレッドその1
           pthread_t t2;    // スレッドその2
    struct arg_set   args1; // スレッドその1の情報
    struct arg_set   args2; // スレッドその2の情報
           void*     count_words( void* );

    if( ac != 3 ) {
        printf( "usage: %s file file2\n", av[0] );
        exit( 1 );
    }

    args1.count = 0;     // args1初期設定
    args1.fname = av[1]; // args1初期設定
    pthread_create( &t1, NULL, count_words, ( void* )&args1 );

    args2.count = 0;     // args2初期設定
    args2.fname = av[2]; // args2初期設定
    pthread_create( &t2, NULL, count_words, ( void* )&args2 );
    pthread_join( t1, NULL );
    pthread_join( t2, NULL );

    printf( "%5d: total words\n", args1.count + args2.count );
    return 0;
}

void* count_words( void* f )
{
    struct arg_set* args  = f;
           FILE*    fp;
           int      c;
           int      prevc = '\0';

    if( ( fp = fopen( args->fname, "r" ) ) != NULL ) {
        while( ( c = getc( fp ) ) != EOF ) {
            if( isalnum( c ) && isalnum( prevc ) ) args->count++;
            prevc = c;
        }
        fclose( fp );
    }
    else perror( args->fname );

    return NULL;
}
