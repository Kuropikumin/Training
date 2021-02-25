/* new_timeserv.c - ソケットベースの時報サーバ
 *                  socklib.c を使って書き直す
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <strings.h>
#include <stdlib.h>  // exit関数を利用する際に必要

#define PORTNUM 13000
#define HOSTLEN 256
#define oops( msg ) { perror( msg ); exit( 1 ); }

int make_server_socket( int );

int main( int ac, char* av[] )
{
    int    sock_id;           // 回線ID
    int    sock_fd;           // ファイルディスク
    FILE*  sock_fp;           // ソケットをストリームとして使う
    char*  ctime();           // 秒を文字列に変換する
    time_t thetime;           // 報告する時刻

    sock_id = make_server_socket( PORTNUM );

    // メインループ：accept(), write(), close()
    while( 1 ) {
        sock_fd = accept( sock_id, NULL, NULL );     // 着信を待つ
        printf( "Wow! got a call!\n" );
        if( sock_fd == -1 ) oops( "accept" );        // 着信エラー

        sock_fp = fdopen( sock_fd, "w" );            // sock_fdのファイルディスクリプタをストリーム化
        if( sock_fp == NULL ) oops( "fdopen" );      // ソケットをファイルストリーム化に失敗した場合

        thetime = time( NULL );                      // 時刻取得を行う

        fprintf( sock_fp, "The time here is ... " );
        fprintf( sock_fp, "%s", ctime( &thetime ) ); // 時刻を文字列化
        fclose( sock_fp );
    }

    return 0;
}
