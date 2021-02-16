/* rlsd.c - リモート ls サーバ
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
#include <ctype.h>   // isalnum関数を利用する際に必要

#define PORTNUM 15000
#define HOSTLEN 256
#define oops( msg ) { perror( msg ); exit( 1 ); }

void sanitize( char* );

int main( int ac, char* av[] )
{
    struct sockaddr_in saddr;             // ここにアドレスを構築する
    struct hostent*    hp;                // アドレスの一部
           char        hostname[HOSTLEN]; // 同上
           int         sock_id;           // 回線ID
           int         sock_fd;           // ファイルディスク
           FILE*       sock_fpi;          // 入力用ストリーム
           FILE*       sock_fpo;          // 出力用ストリーム
           FILE*       pipe_fp;           // popen を使って ls を実行する際に使用するファイルポインタ
           char        dirname[BUFSIZ];   // 送付されたディレクトリのパス
           char        command[BUFSIZ];   // popen 用
           int         dirlen;            // ディレクトリパスの長さ
           int         c;

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
        if( sock_fd == -1 ) oops( "accept" );        // 着信エラー

        // 読み出し方向をストリームとしてオープン
        if( ( sock_fpi = fdopen( sock_fd, "r" ) ) == NULL ) oops( "fdopen reading" );

        if( fgets( dirname, BUFSIZ - 5, sock_fpi ) == NULL ) oops( "reading dirname" );
        sanitize( dirname );

        // 書き込み方向をストリームとしてオープン
        if( ( sock_fpo = fdopen( sock_fd, "w" ) ) == NULL ) oops( "fdopen writing" );

        sprintf( command, " ls %s", dirname );
        if( ( pipe_fp = popen( command, "r" ) ) == NULL ) oops( "popen" );

        while( ( c = getc( pipe_fp ) ) != EOF ) putc( c, sock_fpo );
        pclose( pipe_fp );
        fclose( sock_fpo );
        fclose( sock_fpi );
    }

    return 0;
}

void sanitize( char* str )
/*
 * 誰かが " ; rm *" のようなディレクトリ名を送ってきたときに、
 * 素直に ls ; rm *" を実行するのはまずい
 *
 * そこで、スラッシュと英数字以外のすべての文字を取り除く
 * もっと良い方法があるがそれは練習問題参照
 */
{
    char* src;
    char* dest;

    for( src = dest = str; *src; src++ ) {
        if( *src == '/' || isalnum( *src ) ) *dest++ = *src;
    }
    *dest = '\0';
}
