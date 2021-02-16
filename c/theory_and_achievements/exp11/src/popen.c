/* popen.c - Unixライブラリ関数の popen() の実装の1つ
 *   FILE* popen( char* command, char* mode )
 *         command：通常のシェルコマンド
 *            mode："r" か "w"
 *          戻り値：コマンドに接続されたストリーム か NULL
 *            詳細：execl で "sh" "-c" command を実行する
 *            課題：子プロセスのシグナル処理をどうするか
 */

#include <stdio.h>
#include <signal.h>

#define READ  0
#define WRITE 1

FILE* popen( const char* command, const char* mode )
{
    int   pfp[2];     // パイプ
    int   pid;        // プロセスID
    int   parent_end;
    int   child_end;
    FILE* fdopen();   // fdopen は fd をストリームに変換する
    FILE* fd;

    if( *mode == 'r' ) {
        parent_end = READ;
        child_end  = WRITE;
    }
    else if( *mode == 'w' ) {
        parent_end = WRITE;
        child_end  = READ;
    }
    else return NULL;

    // パイプを作る
    if( pipe( pfp ) == -1 ) return NULL;

    // プロセスを作る
    if( ( pid = fork() ) == -1 ) {
        // プロセス作成に失敗したらパイプをクローズする
        close( pfp[0] );
        close( pfp[1] );
        return NULL;
    }

    // 親プロセス処理
    // 片方をクローズして、もう片方を fdopen にする
    if( pid > 0 ) {
        if( close( pfp[child_end] ) == -1 ) return NULL;
        return fdopen( pfp[parent_end], mode ); // 同じモード
    }

    // 子プロセスのコード
    // stdin または stdout をリダイレクトし、cmd を exec

    // 反対側をクローズし、制御を返さない
    // クローズに失敗したら強制終了
    if( close ( pfp[parent_end] ) == -1 ) exit ( 1 );

    // 子プロセスの内容を標準出力へと繋ぎ直す
    // 失敗したら強制終了
    if( dup2( pfp[child_end], child_end ) == -1 ) exit( 1 );

    // 作業が終了したらクローズ
    if( close( pfp[child_end] ) == -1 ) exit( 1 );

    // コマンドの実行ができる状態になったので実行
    execl( "/bin/sh", "sh", "-c", command, NULL );
    // 通常は以下の処理まではいかない
    exit( 1 );
}
