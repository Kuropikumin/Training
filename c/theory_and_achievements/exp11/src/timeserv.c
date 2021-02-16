/* timeserv.c - ソケットベースの時報サーバ
 *
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

int main( int ac, char* av[] )
{
    struct sockaddr_in saddr;             // ここにアドレスを構築する
    struct hostent*    hp;                // アドレスの一部
           char        hostname[HOSTLEN]; // 同上
           int         sock_id;           // 回線ID
           int         sock_fd;           // ファイルディスク
           FILE*       sock_fp;           // ソケットをストリームとして使う
           char*       ctime();           // 秒を文字列に変換する
           time_t      thetime;           // 報告する時刻

    // ステップ1：カーネルにソケットを要求する
    sock_id = socket( PF_INET, SOCK_STREAM, 0 ); // ソケットの要求
    if( sock_id == -1 ) oops( "Socket" );        // ソケット要求に失敗した場合

    // ステップ2：ソケットにアドレスをバインドする
    //            アドレスは、ホストとポートを設定する
    bzero( ( void* )&saddr, sizeof( saddr ) ); // 構造体をクリアする
    gethostname( hostname, HOSTLEN );          // 実行するホスト名の取得
    hp = gethostbyname( hostname );            // ホスト情報を取得する

    bcopy( ( void* )hp->h_addr, ( void* )&saddr.sin_addr, hp->h_length ); // ホスト情報を設定
    saddr.sin_port = htons( PORTNUM );                                    // ソケットポートを設定
    saddr.sin_family = AF_INET;                                           // アドレスファミリを設定

    // バインドに失敗した場合
    if( bind( sock_id, (struct sockaddr* )&saddr, sizeof( saddr ) ) != 0 ) oops( "bind" );

    // ステップ3：キューサイズを1としてソケットを着信できる状態にする
    if( listen( sock_id, 1 ) != 0 ) oops( "listen" );

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
