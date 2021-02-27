/* twebserv.c - マルチスレッドバージョンの最小限のWebサーバ（version 0.2）
 *       目的：マルチスレッドを利用したWebサーバの作成を実施する
 *     使い方：twebserv <ポート番号>
 *       機能：GETコマンドのみをサポートする
 *             カレントディレクトリで動作する
 *             新しいスレッドを作って個々の陸背うとを処理する
 *             内部状態を報告する特殊URLのstatusをサポートする
 * コンパイル：gcc src/webserv.c src/socklib.c -lpthread -o exe/twebserv
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>     // fork関数を利用するのに必要

#include <dirent.h>
#include <time.h>

#include <sys/socket.h> // accept関数を利用するのに必要

// サーバの統計情報
time_t server_started;
int    server_bytes_sent;
int    server_requests;

// 別ファイル（socklib.c）で定義されている関数
int make_server_socket( int );

// 関数定義
void  setup( pthread_attr_t* );
void  skip_rest_of_header( FILE* );
void  sanitize( char* );
int   http_reply( int, FILE**, int, char*, char*, char* );
int   built_in( char*, int );
void  not_implemented( int );
void  do_404( char*, int );
int   isadir( char* );
int   not_exist( char* );
void  do_ls( char*, int );
char* file_type( char* );
void  do_cat( char*, int );
void  process_rq( char*, int );
void* handle_call( void* );

int main( int ac, char* av[] )
{
    int            sock;
    int            fd;
    int*           fdptr;
    pthread_t      worker;
    pthread_attr_t attr;
    void*          handle_call( void* );

    if( ac == 1 ) {
        fprintf( stderr, "usage: twebserv portnum\n" );
        exit( 1 );
    }

    sock = make_server_socket( atoi( av[1] ) );
    if( sock == -1 ) {
        perror( "makeing socket" );
        exit( 2 );
    }

    setup( &attr );

    // ここからメインループ: handole_call が呼ばれるたびに新しいスレッドを作成する
    while( 1 ) {
        // 呼び出しを受け付けて、ソケットをストリーム化する
        fd = accept( sock, NULL, NULL );
        server_requests++;

        fdptr  = malloc( sizeof( int ) );
        *fdptr = fd;
        pthread_create( &worker, &attr, handle_call, fdptr );
    }

    return 0;
}

void setup( pthread_attr_t* attrp )
// ステータス変数を初期化し、スレッド属性をデタッチに設定する
{
    pthread_attr_init( attrp );
    pthread_attr_setdetachstate( attrp, PTHREAD_CREATE_DETACHED );

    time( &server_started );
    server_requests   = 0;
    server_bytes_sent = 0;
}

void skip_rest_of_header( FILE* fp )
/* skip_rest_of_header( FILE* )
 *   機能：CRNLを検出するまで、すべてのリクエスト情報を読み飛ばす
 */
{
    char buf[BUFSIZ];
    while( fgets( buf, BUFSIZ, fp ) != NULL && strcmp( buf, "\r\n" ) != 0 );
}

void sanitize( char* str )
// すべてのパスがカレントディレクトリの下を指していることを確かめる
{
    char* src;
    char* dest;

    src = dest = str;

    while( *src ) {
        if     ( strncmp( src, "/../", 4 ) == 0 ) src += 3;
        else if( strncmp( src, "//", 2 ) == 0 )   src += 1;
        else                                      *dest++ = *src++;
    }
    *dest = '\0';

    if( *str == '/' ) strcpy( str, str + 1 );

    if( str[0] == '\0'              ||
        strcmp( str, "./" )    == 0 ||
        strcmp( str, "./../" ) == 0
      ) strcpy( str, "." );
}

int http_reply( int fd, FILE** fpp, int code, char* msg, char* type, char* content )
{
    FILE* fp = fdopen( fd, "w" );
    int   bytes = 0;

    if( fp != NULL ) {
        bytes  = fprintf( fp, "HTTP/1.0 %d %s\r\n", code, msg );
        bytes += fprintf( fp, "Content-type: %s\r\n\r\n", type );
        if( content ) bytes += fprintf( fp, "%s\r\n", content );
    }

    fflush( fp );
    if( fpp ) *fpp = fp;
    else      fclose( fp );
    return bytes;
}

int built_in( char* arg, int fd )
// ここで組み込みURLを処理する。現在は "status" のみ
{
    FILE* fp;

    if( strcmp( arg, "status" ) != 0 ) return 0;

    http_reply( fd, &fp, 200, "OK", "text/plain", NULL );

    fprintf( fp, "Server started: %s",   ctime( &server_started ) );
    fprintf( fp, "Total requests: %d\n", server_requests );
    fprintf( fp, "Bytes sent out: %d\n", server_bytes_sent );

    fclose( fp );
    return 1;
}

void not_implemented( int fd )
// 実装されていないHTTPコマンドのリクエストが来た場合
{
    http_reply( fd, NULL, 501, "Not Implemented", "text/plain", "That command is not implemented" );
}

void do_404( char* item, int fd )
// 指定されたオブジェクトがない場合
{
    http_reply( fd, NULL, 404, "Not Found", "text/plain", "The item you seek is not here" );
}

/* --------------------------------------------------------------- *
 * ディレクトリリスト部分
 * isadir() は stat を使う。 not_exist() も stat を使う
 * --------------------------------------------------------------- */
int isadir( char* f )
{
    struct stat info;
    return( stat( f, &info ) != -1 && S_ISDIR( info.st_mode ) );
}

int not_exist( char* f )
{
    struct stat info;
    return( stat( f, &info ) == -1 );
}

void do_ls( char* dir, int fd )
{
           DIR*    dirptr;
    struct dirent* direntp;
           FILE*   fp;
           int     bytes = 0;

    bytes  = http_reply( fd, &fp, 200, "OK", "text/plain", NULL );
    bytes += fprintf( fp, "Listing of Directory %s\n", dir );

    if( ( dirptr = opendir( dir ) ) != NULL ) {
        while( direntp = readdir( dirptr ) ) {
            bytes += fprintf( fp, "%s\n", direntp->d_name );
        }
        closedir( dirptr );
    }

    fclose( fp );
    server_bytes_sent += bytes;
}

/* --------------------------------------------------------------- *
 * ファイル表示関数
 * file_type( filename ) は "拡張子" を返す。do_cat はその情報を使う
 * --------------------------------------------------------------- */
char* file_type( char* f )
{
    char* cp;
    if( ( cp = strrchr( f, '.' ) ) != NULL ) return cp + 1;
    return "";
}

void do_cat( char* f, int fd )
/* --------------------------------------------------------------- *
 * do_cat( filename, fd )
 * ヘッダを送ってから内容を送り返す
 * --------------------------------------------------------------- */
{
    char* extension = file_type( f );
    char* type      = "text/plain";
    FILE* fpsock;
    FILE* fpfile;
    int   c;
    int   bytes = 0;

    if     ( strcmp( extension, "html" ) == 0 ) type = "text/html";
    else if( strcmp( extension, "gif" ) == 0 )  type = "image/gif";
    else if( strcmp( extension, "jpg" ) == 0 )  type = "image/jpeg";
    else if( strcmp( extension, "jpeg" ) == 0 ) type = "image/jpeg";

    fpsock = fdopen( fd, "w" ); // 接続されたソケットに書き込むファイルストリーム
    fpfile = fopen( f, "r" );   // 呼び出されるファイルを読み取り専用で開く

    if( fpsock != NULL && fpfile != NULL ) {
        bytes = http_reply( fd, &fpsock, 200, "OK", type, NULL );
        while( ( c = getc( fpfile ) ) != EOF ) {
            putc( c, fpsock );
            bytes++;
        }
        fclose( fpfile );
        fclose( fpsock );
    }
    server_bytes_sent += bytes;
}

void process_rq( char* rq, int fd )
/* process_rq( char*, int )
 *  機能：リクエスト処理を実行し、fdにレスポンスを書き込む
 *        新プロセスでリクエストを処理する
 *  入力：rq は HTTPコマンド（GET /foo/bar.html HTTP/1.0）
 *        fd はファイルディスクリプタ
 */
{
    char cmd[BUFSIZ];
    char arg[BUFSIZ];

    if( sscanf( rq, "%s%s", cmd, arg ) != 2 ) return;
    sanitize( arg );
    printf( "sanitized version is %s\n", arg );

    if     ( strcmp( cmd, "GET" ) != 0 ) not_implemented( fd );
    else if( built_in( arg, fd ) );
    else if( not_exist( arg ) )          do_404( arg, fd );
    else if( isadir( arg ) )             do_ls( arg, fd );
    else                                 do_cat( arg, fd );
}

void* handle_call( void* fdptr )
{
    FILE* fpin;
    char  request[BUFSIZ];
    int   fd;

    fd = *( int* )fdptr; // 引数からfdを取得
    free( fdptr );

    fpin = fdopen( fd, "r" );       //バッファ入力
    fgets( request, BUFSIZ, fpin ); // クライアントリクエストを読み出す
    printf( "got a call on %d: request = %s", fd, request );
    skip_rest_of_header( fpin );

    process_rq( request, fd ); // クライアントリクエストを処理する

    fclose( fpin );
}
