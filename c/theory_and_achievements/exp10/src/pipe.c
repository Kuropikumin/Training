/* pipe.c
 *   目的：1つのプロセスから別のプロセスにデータを流す
 *         パイプラインの作り方を示す。引数として 2つの
 *         コマンドをとり、av[1] の出力を av[2] の入力に接続する
 * 使い方：pipe command1 command2
 *   効果：command1 | command2
 *   制限：コマンドは引数をとることができない
 *         引数の個数がわかっているので execlp() を使う
 *   注意：子プロセスと親プロセスを取り換えると面白いことになる
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // exit関数を利用するのに必要
#include <string.h> // strlen関数を利用するのに必要

#define CHILD_MESS   "I want a cookie\n"
#define PAR_MESS     "testing...\n"
#define oops( m, x ) { perror( m ); exit( x ); }

int main( int ac, char** av )
{
    int  thepipe[2];  // 2つのファイルディスクリプタ
    int  newfd;       // パイプで役立つ
    int  pid;         // プロセスID

    // 制限に引っかかった場合
    if( ac != 3 ) {
        fprintf( stderr, "usage: pipe cmd1 cmd2\n" );
        exit( 1 );
    }
    // パイプを作成する
    if( pipe( thepipe ) == -1 ) oops( "could not make pipe", 1 );

    // パイプを作ったのでプロセスを2つにする
    if( ( pid = fork() ) == -1 ) oops( "Cannot fork", 2 ); // プロセス作成及び例外処理

    // これ以降はプロセスが 2つ（親プロセスと子プロセス）存在する
    // 親はパイプから読みこむ

    if( pid > 0 ) { // 親は av[2] を実行する

        close( thepipe[1] ); // 親はパイプに書き込まない
        if( dup2( thepipe[0], 0 ) == -1 ) oops( "could not redirect stdin", 3 );

        close( thepipe[0] ); //標準入力の複製を作り、パイプをクローズする

        execlp( av[2], av[2], NULL );
        oops( av[2], 4 );
    }

    // 子は av[1] を実行し、パイプに書き込む
    close( thepipe[0] ); // 子はパイプから読み出さない

    if( dup2( thepipe[1], 1 ) == -1 ) oops( "could not redirect stdout", 4 );

    close( thepipe[1] ); // 標準出力の複製を作り、パイプをクローズする

    execlp( av[1], av[1], NULL );
    oops( av[1], 5 );

    return 0;
}
