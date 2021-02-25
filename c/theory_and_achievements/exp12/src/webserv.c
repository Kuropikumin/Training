/* webserv.c - 最小限のWebサーバ（version 0.2）
 *       目的：Webサーバの作成を実施する
 *     使い方：webserv <ポート番号>
 *       機能：GETコマンドのみをサポートする
 *             カレントディレクトリで動作する
 *             新しい子プロセスを作って個々のリクエストを処理する
 *             非常に大きなセキュリティホールがあるので、あくまでもデモ用である
 *             ほかにも弱点はいくつもあるが、スタート地点としては満足である
 * コンパイル：gcc src/webserv.c src/socklib.c -o exe/webserv
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>     // exit関数を利用するのに必要
#include <unistd.h>     // fork関数を利用するのに必要
#include <sys/socket.h> // accept関数を利用するのに必要

// socklib.c で定義している関数
int   make_server_socket( int );

// サーバ処理で必要となる関数
void  read_til_crnl( FILE* );
void  process_rq( char*, int );
void  header( FILE*, char* );
void  cannot_do( int );
void  do_404( char*, int );
void  do_cat( char*, int );

// ディレクトリリスト部
int   isadir( char* );
int   not_exist( char* );
void  do_ls( char*, int );

//cgi処理部
char* file_type( char* );
int   ends_in_cgi( char* );
void  do_exec( char*, int );

int main( int ac, char* av[] )
{
    int   sock;
    int   fd;
    FILE* fpin;
    char  request[BUFSIZ];

    if( ac == 1 ) {
        fprintf( stderr, "usage: ws portnum\n" );
        exit( 1 );
    }

    sock = make_server_socket( atoi( av[1] ) );
    if( sock == -1 ) exit( 2 );

    // ここからメインループ
    while( 1 ) {
        // 呼び出しを受け付けて、ソケットをストリーム化する
        fd = accept( sock, NULL, NULL );
        fpin = fdopen( fd, "r" );

        // リクエストを読み出す
        fgets( request, BUFSIZ, fpin );
        printf( "got a call: request = %s", request );
        read_til_crnl( fpin );

        // クライアントが要求した処理を実行する
        process_rq( request, fd );
        fclose( fpin );
    }

    return 0;
}

void read_til_crnl( FILE* fp )
/* -------------------------------------------- *
 * read_til_crnl( FILE* fp )
 * CRNLを検出するまで、すべてのリクエスト情報を読み飛ばす
 * -------------------------------------------- */
{
    char buf[BUFSIZ];
    while( fgets( buf, BUFSIZ, fp ) != NULL && strcmp( buf, "\r\n" ) != 0 );
}

void process_rq( char* rq, int fd )
/* -------------------------------------------- *
 * process_rq( char* rq, int fd )
 * リクエストが要求してきた処理を実行し、fdにレスポンスを書き込む
 * 新プロセスでリクエストを処理する
 * rq は HTTPコマンド：GET /foo/bar.html HTTP/1.0
 * -------------------------------------------- */
{
    char cmd[BUFSIZ];
    char arg[BUFSIZ];

    // 新しいプロセスを作成し、子プロセスでなければすぐリターンする
    if( fork() != 0 ) return;

    strcpy( arg, "./" ); // 引数の前に "./" をつける（現在のディレクトリ配下を探す）
    if( sscanf( rq, "%s%s", cmd, arg + 2 ) != 2 ) return;

    // cmd および arg の値からサーバで実行する処理を決める
    if     ( strcmp( cmd, "GET" ) != 0 ) cannot_do( fd );
    else if( not_exist( arg ) )          do_404( arg, fd );
    else if( isadir( arg ) )             do_ls( arg, fd );
    else if( ends_in_cgi( arg ) )        do_exec( arg, fd );
    else                                 do_cat( arg, fd );
}

void header( FILE* fp, char* content_type )
/* -------------------------------------------- *
 * header( FILE* fp, char* content_type )
 * レスポンスヘッダの生成：すべての処理が必要とする
 *                         content_type が NULL なら、Content-type 行は送らない
 * -------------------------------------------- */
{
    fprintf( fp, "HTTP/1.0 200 OK\r\n" );
    if( content_type ) fprintf( fp, "Content-type: %s\r\n", content_type );
}

void cannot_do( int fd )
// 実装されていないHTTPコマンドのリクエストが来た場合
{
    FILE* fp = fdopen( fd, "w" );

    fprintf( fp, "HTTP/1.0 501 Not Implemented\r\n" );
    fprintf( fp, "Content-type: text/plain\r\n" );
    fprintf( fp, "\r\n" );

    fprintf( fp, "That command is not yet implemented\r\n" );
    fclose( fp );
}

void do_404( char* item, int fd )
// 指定されたオブジェクトがない場合
{
    FILE* fp = fdopen( fd, "w" );

    fprintf( fp, "HTTP/1.0 404 Not Found\r\n" );
    fprintf( fp, "Content-type: text/plain\r\n" );
    fprintf( fp, "\r\n" );

    fprintf( fp, "The item you requested: %s\r\n is not found\r\n", item );
    fclose( fp );
}

/* --------------------------------------------------------------- *
 * ディレクトリリスト部分
 * isadir() は stat を使う。 not_exist() も stat を使う
 * do_ls は ls を実行するが、避けるべき（別コマンドをクライアント側が指定する場合があるため）
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
    FILE* fp;

    fp = fdopen( fd, "w" );
    header( fp, "text/plain" );
    fprintf( fp, "\r\n" );
    fflush( fp );

    dup2( fd, 1 );
    dup2( fd, 2 );
    close( fd );
    execlp( "ls", "ls", "-l", dir, NULL );
    perror( dir );
    exit( 1 );
}

/* --------------------------------------------------------------- *
 * cgi処理部分
 * 拡張子をチェックする関数とプログラムを実行する関数
 * --------------------------------------------------------------- */
char* file_type( char* f )
// ファイル名のうち、'.' 以下の文字列を返す
// '.' が見つからない場合、空文字を返す
{
    char* cp;
    if( ( cp = strrchr( f, '.' ) ) != NULL ) return cp + 1;
    return "";
}

int ends_in_cgi( char* f )
{
    return ( strcmp( file_type(f), "cgi" ) == 0 );
}

void do_exec( char* prog, int fd )
{
    FILE* fp;

    fp = fdopen( fd, "w" );
    header( fp, NULL );
    fprintf( fp, "\r\n" );
    fflush( fp );

    dup2( fd, 1 );
    dup2( fd, 2 );
    close( fd );
    execl( prog, prog, NULL );
    perror( prog );
}

void do_cat( char* f, int fd )
/* --------------------------------------------------------------- *
 * do_cat( filename, fd )
 * ヘッダを送ってから内容を送り返す
 * --------------------------------------------------------------- */
{
    char* extension = file_type( f );
    char* content   = "text/plain";
    FILE* fpsock;
    FILE* fpfile;
    int   c;

    if     ( strcmp( extension, "html" ) == 0 ) content = "text/html";
    else if( strcmp( extension, "gif" ) == 0 )  content = "image/gif";
    else if( strcmp( extension, "jpg" ) == 0 )  content = "image/jpeg";
    else if( strcmp( extension, "jpeg" ) == 0 ) content = "image/jpeg";

    fpsock = fdopen( fd, "w" ); // 接続されたソケットに書き込むファイルストリーム
    fpfile = fopen( f, "r" );   // 呼び出されるファイルを読み取り専用で開く

    if( fpsock != NULL && fpfile != NULL ) {
        header( fpsock, content );
        fprintf( fpsock, "\r\n" );
        while( ( c = getc( fpfile ) ) != EOF ) putc( c, fpsock );
        fclose( fpfile );
        fclose( fpsock );
    }

    exit( 0 );
}
