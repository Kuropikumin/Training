/* execute.c - smsh のためにコマンドを読んで解析する関数
 *
 *     char* next_cmd( char* prompt, FILE* fp ) - 次のコマンドを取得する
 *     char** splitline( char* str )            - 文字列を解析する
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./header/smsh.h"

char* next_cmd( char* prompt, FILE* fp )
/*
 *   目的：fp から次のコマンド業を読み出す
 * 戻り値：コマンド行を保持する動的に確保した文字列
 * エラー：EOF なら NULL（本当はエラーではない）
 *         emalloc() から fatal を呼び出す
 *   メモ：BUFSIZ単位でメモリを保持する
 */
{
    char* buf;          // バッファ
    int   bufspace = 0; // サイズ合計
    int   pos      = 0; // 現在位置
    int   c;            // 入力文字

    printf( "%s", prompt );  // ユーザにプロンプトを出力する

    while( ( c = getc( fp ) ) != EOF ) {
        // need space?
        if( pos + 1 >= bufspace ) {
            if( bufspace == 0 ) buf = emalloc( BUFSIZ );                  // 1 は \0 のため y：初回
            else                buf = erealloc( buf, bufspace + BUFSIZ ); // 拡張
            bufspace += BUFSIZ;                                           // サイズを更新
        }

        // コマンドの末尾？
        if( c == '\n' ) break;

        // 違うのでバッファに追加
        buf[pos++] = c;
    }

    if( c == EOF && pos == 0 ) return NULL;         // EOF で入力無しと判断し、入力無しと回答
    buf[pos] = '\0';                                // 文字列の最後は \0 で終了する
    return buf;
}

/*
 * splitline( 行を解析して文字列配列に分割する )
 */
#define is_delim(x) ( ( x ) == ' ' || ( x ) == '\t' )

char** splitline( char* line )
/*
 *   目的：行を空白区切りのトークンに分割する
 * 戻り値：トークンのコピーを指す末尾が NULL のポインタ配列
 *         行にトークンが含まれていない場合は NULL
 *   動作：配列を順にチェックし、文字列を探してコピーを作る
 *   メモ：strtok() を使えば簡単だが、あとでクォートに対応するつもりなので、strtok() は利用しない
 */
{
    char*  newstr();
    char** args;
    int    spots = 0;    // テーブルの要素数
    int    bufspace = 0; // テーブルのバイト数
    int    argnum = 0;   // 使った要素の数
    char*  cp = line;    // 文字列の pos
    char*  start;
    int    len;

    if( line == NULL ) return NULL;  // 特殊条件の処理

    args     = emalloc( BUFSIZ );   // 配列の初期化
    bufspace = BUFSIZ;
    spots    = BUFSIZ/sizeof( char* );

    while( *cp != '\0' ) {
        while( is_delim( *cp ) ) cp++;  // 先頭のスペースをスキップ

        if( *cp == '\0' ) break; // 現在の位置が line の末端ならwhileループから抜ける

        // 配列が十分なスペースを持つようにする（+1 は NULL の分）
        if( argnum + 1 >= spots ) {
            args      = erealloc( args, bufspace + BUFSIZ );
            bufspace += BUFSIZ;
            spots    += ( BUFSIZ/sizeof( char* ) );
        }

        // 先頭にマークを付け、単語の末尾を探す
        start = cp;
        len   = 1;
        while( *++cp != '\0' && !(is_delim( *cp ) ) )  len++;
        args[argnum++] = newstr( start, len );
    }
    args[argnum] = NULL;
    return args;
}

char* newstr( char* s, int l )
/*   目的：文字列のコンストラクタ
 * 戻り値：文字列、NULL にはならない
 */
{
    char* rv = emalloc( l + 1 );

    rv[l] = '\0';
    strncpy( rv, s, l );
    return rv;
}

void freelist( char** list )
/*
 *   目的：splitline が返したリストを開放する
 * 戻り値：なし
 *   動作：リスト内のすべての文字列を開放してリストを開放する
 */
{
    char** cp = list;
    while( *cp ) free( *cp++ );
    free( list );
}

void* emalloc( size_t n )
{
    void* rv;

    if( ( rv = malloc( n ) ) == NULL ) fatal( "out of memory", "", 1 );
    return rv;
}

void* erealloc( void* p, size_t n )
{
    void* rv;
    if( ( rv = realloc( p, n ) ) == NULL ) fatal( "realloc() failed", "", 1 );
    return rv;
}
