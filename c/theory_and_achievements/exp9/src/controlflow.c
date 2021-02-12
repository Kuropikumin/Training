/* controlflow.c
 *  "if" 処理は、if_state と if_result の2つの状態編巣を使って行う
 */

#include <stdio.h>
#include <string.h>  // strcmp関数を利用するために必要
#include "./header/smsh.h"

// enum states  { NEUTRAL, WANT_THEN, THEN_BLOCK };
// else を実行するためにステータスを追加
enum states  { NEUTRAL, WANT_THEN, THEN_BLOCK, ELSE_BLOCK };
enum results { SUCCESS, FAIL };

static int if_state  = NEUTRAL;
static int if_result = SUCCESS;
static int last_stat = 0;

int syn_err( char* );

int ok_to_execute()
/*
 *   目的：シェルがコマンドを実行すべきかどうかを判断する
 * 戻り値：Yes なら 1, No なら 0
 *   詳細：THEN_BLOCK 内にいて、if_result が SUCCESS なら Yes
 *         THEN_BLOCK 内にいて、if_result が FAIL なら No
 *         WANT_THEN なら構文エラー（shは異なる）
 */
{
    int rv = 1; // default は 真

    if      ( if_state == WANT_THEN ) {
        syn_err( "then expected" );
        rv = 0;
    }
    else if( if_state == THEN_BLOCK && if_result == SUCCESS ) rv = 1;
    else if( if_state == THEN_BLOCK && if_result == FAIL )    rv = 0;
    else if( if_state == ELSE_BLOCK && if_result == SUCCESS ) rv = 0;  // else の場合、真ならば実行しない
    else if( if_state == ELSE_BLOCK && if_result == FAIL )    rv = 1;  // else の場合、偽ならば実行する

    return rv;
}

int is_control_command( char* s )
/*
 *   目的：コマンドがシェルコマンドかどうかを報告する bool 関数
 * 戻り値：0 か 1（制御構文なら1）
 */
{
    return ( strcmp( s, "if" )   == 0 ||
             strcmp( s, "then" ) == 0 ||
             strcmp( s, "else" ) == 0 ||
             strcmp( s, "fi" )   == 0
           );
}

int do_control_command( char** args )
/*
 *   目的："if", "then", "fi" を処理する - 状態を変更するかエラーを検出する
 * 戻り値： OK なら 0, 構文エラーなら -1
 *   メモ：I would have put returns all over the place, Barry says "no"
 */
{
    char* cmd = args[0];
    int   rv  = -1;

    if( strcmp( cmd, "if" ) == 0 ) {
        if( if_state != NEUTRAL ) rv = syn_err( "if unexpected" );
        else {
            last_stat = process( args + 1 );
            if_result = ( last_stat == 0 ? SUCCESS : FAIL );
            if_state  = WANT_THEN;
            rv        = 0;
        }
    }
    else if( strcmp( cmd, "then" ) == 0 ) {
        if( if_state != WANT_THEN ) rv = syn_err( "then unexpected" );
        else {
            if_state = THEN_BLOCK;
            rv = 0;
        }
    }
    else if( strcmp( cmd, "else" ) == 0 ) {
        if( if_state != THEN_BLOCK ) rv = syn_err( "else unexpected" );
        else {
            if_state = ELSE_BLOCK;
            rv = 0;
        }
    }
    else if( strcmp( cmd, "fi" ) == 0 ) {
        if( if_state != THEN_BLOCK && if_state != ELSE_BLOCK ) rv = syn_err( "fi unexpected" );
        else {
            if_state = NEUTRAL;
            rv = 0;
        }
    }
    else fatal( "internal error processing:", cmd, 2 );

    return rv;
}

int syn_err( char* msg )
/*   目的：制御構造内の構文エラーを処理する
 *   詳細：状態を NEUTRAL にリセットする
 * 戻り値：対話的モードなら -1, スクリプト内では、fatal 呼び出しになる
 */
{
    if_state = NEUTRAL;
    fprintf( stderr, "syntax error: %s\n", msg );
    return -1;
}
