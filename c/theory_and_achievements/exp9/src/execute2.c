/* execute2.c - smsh がコマンドを実行するために使うコード
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "./header/varlib.h" // VLtable2environ 関数を利用するために追加

int execute( char* argv[] )
/*
 *   目的：引数を渡してプログラムを起動する
 * 戻り値：waitを介して返された終了ステータス。エラーは -1
 * エラー：fork() か wait() がエラーを起こした時には -1
 */
{
    extern char** environ;
           int pid;
           int child_info = -1;

    if( argv[0] == NULL ) return 0;

    if     ( ( pid = fork() ) == -1 ) perror( "fork error" );
    else if( pid == 0 ) {
        environ = VLtable2environ();
        signal( SIGINT,  SIG_DFL );
        signal( SIGQUIT, SIG_DFL );
        execvp( argv[0], argv );
        perror( "cannot execute command" );
        exit( 1 );
    }
    else {
        if( wait( &child_info ) == -1 ) perror( "wait" );
    }
    return child_info;
}

