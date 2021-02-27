/* twordcount4.c - 2つのファイルのためのマルチスレッド wc バージョン4
 *                 条件変数を使ってカウント関数が計算結果を早く報告できるようにする
 */

#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h> // exit関数を利用するのに必要

struct arg_set { // 1つの引数に2つの値を詰め込む
    char* fname; // 解析するファイル名
    int   count; // ファイル名に対するカウント数
};

struct arg_set*        mailbox = NULL;
       pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
       pthread_cond_t  flag = PTHREAD_COND_INITIALIZER;

int main( int ac, char* av[] )
{
           pthread_t t1;    // スレッドその1
           pthread_t t2;    // スレッドその2
    struct arg_set   args1; // スレッドその1の情報
    struct arg_set   args2; // スレッドその2の情報
           void*     count_words( void* );
           int       reports_in  = 0;
           int       total_words = 0;

    if( ac != 3 ) {
        printf( "usage: %s file file2\n", av[0] );
        exit( 1 );
    }

    pthread_mutex_lock( &lock ); // メールボックスをロック

    args1.count = 0;     // args1初期設定
    args1.fname = av[1]; // args1初期設定
    pthread_create( &t1, NULL, count_words, ( void* )&args1 );

    args2.count = 0;     // args2初期設定
    args2.fname = av[2]; // args2初期設定
    pthread_create( &t2, NULL, count_words, ( void* )&args2 );

    while( reports_in < 2 ) {
        printf( "MAIN: wainting for flag to go up\n" );
        pthread_cond_wait( &flag, &lock );  // 連絡を待つ
        printf( "MAIN: Wow! flag was raised, I have the lock\n" );
        printf( "%7d: %s\n", mailbox->count, mailbox->fname );
        total_words += mailbox->count;
        if( mailbox == &args1 ) pthread_join( t1, NULL );
        if( mailbox == &args2 ) pthread_join( t2, NULL );

        mailbox = NULL;
        pthread_cond_signal( &flag );
        reports_in++;                 // 通知を待つ
    }
    printf( "%7d: total words\n", total_words );
    return 0;
}

void* count_words( void* f )
{
    struct arg_set* args  = f;     // キャストして正しい型に直す
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

    printf( "COUNT: waiting to get lock\n" );
    pthread_mutex_lock( &lock );             // メールボックスを取得する
    printf( "COUNT: have lock, storing data\n" );
    if( mailbox != NULL ) {
        printf( "COUNT: oops..mailbox not empty. waitfor signal\n" );
        pthread_cond_wait( &flag, &lock );
    }

    mailbox = args;                     // メールボックスに引数を指すポインタを書き込む
    printf( "COUNT: raising flag\n" );
    pthread_cond_signal( &flag );       // フラグをシグナリングする
    printf( "COUNT: unlocking box\n" );
    pthread_mutex_unlock( &lock );      // メールボックスを開放する

    return NULL;
}
