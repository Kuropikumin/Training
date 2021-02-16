/* tinybc.c
 *   目的：双方向パイプの作り方、使い方を学ぶ
 *   詳細：入力は、数値、演算子、数値の順で指定する
 *         tinybc は、これを数値\n数値\n演算子\np に変換してdcに渡す
 *         dcより返された結果を標準出力に書き込む
 *
 *  参考図：
 *                  +---------+                +-------+
 *          stdin > 0         >== pipetodc ====>       |
 *                  |  tinyc  |                |  dc - |
 *         stdout < 1         <== pipefromdc ==<       |
 *                  +---------+                +-------+
 *
 *  プログラムの概要：
 *        a. 2つのパイプを作る
 *        b. fork呼び出し（新しいプロセスを作成する）
 *        c. dc になる予定の新プロセスの中で標準入出力をパイプに接続し、execl dc
 *        d. tinybc プロセスの中では、特に配管の必要はない
 *           通常のにゅうりゅつ力を介してユーザとやり取りし、
 *           パイプを介してプログラム間の情報のやり取りをする
 *        e. 最後にパイプをクローズすると、dc は終了する
 *    注意：複数のレスポンスを処理しない
 */

#include <stdio.h>
#include <stdlib.h>   // exit関数を利用するのに必要
#include <unistd.h>   // pipe関数を利用するのに必要
#include <sys/wait.h> // wait関数を利用するのに必要

#define oops( m, x ) { perror( m ); exit( x ); }

void be_dc( int*, int* );
void be_bc( int*, int* );
void fatal( char* );

int main( void )
{
    int pid;
    int todc[2];
    int fromdc[2];

    // 2つのパイプを作る
    if( pipe( todc ) == -1 || pipe( fromdc ) == -1 ) oops( "pipe failed", 1 );

    // ユーザインターフェースのためのプロセスを作る
    if( ( pid = fork() ) == -1 ) oops( "cannot fork", 2 );

    // 子プロセス処理
    if( pid == 0 ) be_dc( todc, fromdc );
    else {
        be_bc( todc, fromdc );
        wait( NULL );
    }

    return 0;
}

void be_dc( int in[2], int out[2] )
// 標準入出力をセットアップしてから、最後に execl dc
{
    // 標準入力を入力用パイプに接続する
    if( dup2( in[0], 0 ) == -1 ) oops( "dc: cannot redirect stdin", 3 );
    close( in[0] );
    close( in[1] );

    // 標準出力を出力用パイプに接続する
    if( dup2( out[1], 1 ) == -1 ) oops( "dc: cannot redirect stdout", 4 );
    close( out[0] );
    close( out[1] );

    // -オプションをつけて dc を execl する
    execlp( "dc", "dc", "-", NULL );
    oops( "Cannot run dc", 5 );
}

void be_bc( int todc[2], int fromdc[2] )
/*
 * 標準入力から読み出したものを逆ポーランド記法に変換し、パイプに送る
 * 別のパイプから処理結果を読み出し、ユーザに返す
 * fdopen() を呼び出してファイルでスクリプタをストリームに変換する
 */
{
    int   num1;
    int   num2;
    char  operation[BUFSIZ];
    char  message[BUFSIZ];
    char* fgets();
    FILE* fpout;
    FILE* fpin;
    FILE* fdopen();

    // セットアップ
    close( todc[0] );   // dcに情報を送るパイプ空は読みださない
    close( fromdc[1] ); // dcから情報が送られてくるパイプには書き込まない

    // ファイルディスクリプタをストリームに変換する
    fpout = fdopen( todc[1], "w" );
    fpin  = fdopen( fromdc[0], "r" );
    if( fpout == NULL || fpin == NULL ) fatal( "Error convering pipes to streams" );

    // メインループ
    while( printf( "tinybc: " ), fgets( message, BUFSIZ, stdin ) != NULL ) {
        // parse input
        if( sscanf( message, "%d%[-+*/^]%d", &num1, operation, &num2 ) != 3 ) {
            printf( "syntac error\n" );
            continue;
        }

        if( fprintf( fpout, "%d\n%d\n%c\np\n", num1, num2, *operation ) == EOF ) fatal( "Error writing" );

        fflush( fpout );

        if( fgets( message, BUFSIZ, fpin ) == NULL ) break;

        printf( "%d %c %d = %s", num1, *operation, num2, message );
    }

    fclose( fpout ); // パイプをクローズする
    fclose( fpin );  // dcはEOFを検知する
}

void fatal( char* mess )
{
    fprintf( stderr, "Error: %s\n", mess );
    exit( 1 );
}
