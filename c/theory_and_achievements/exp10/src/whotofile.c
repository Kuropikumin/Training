/* whotofile.c
 *   目的：ほかのプログラムの出力をリダイレクトするにはどうすればよいかを学ぶ
 * 考え方：fork してから、この中で出力をリダイレクトし、最後に exec する
 */

#include <stdio.h>
#include <stdlib.h>   // exit関数を利用するのに必要
#include <unistd.h>   // fork, close関数を利用するのに必要
#include <sys/wait.h> // wait関数を利用するのに必要
#include <fcntl.h>    // creat関数を利用するのに必要

int main( )
{
    int pid;
    int fd;

    // 新プロセスを作成する。失敗したら終了
    if( ( pid = fork() ) == -1 ) {
        perror( "fork error : " );
        exit( 1 );
    }

    // 子プロセスの仕事
    if( pid == 0 ) {
        // 親プロセスから引き継いだ標準出力先をクローズ
        close( 1 );
        // ファイルの作成および上記クローズしたファイルディスクリプタ先を fd に代入
        fd = creat( "./demo/userlist", 0644 );
        // 実行
        execlp( "who", "who", NULL );
        perror( "execlp" );
        exit( 1 );
    }

    // 親プロセスは子プロセスの処理終了を待ち、終了ステータスを報告
    if( pid != 0 ) {
        wait( NULL );
        printf( "Done running who. result in demo/userlist\n" );
    }

    return 0;
}
