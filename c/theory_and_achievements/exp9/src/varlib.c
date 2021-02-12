/* varlib.c - smsh がコマンドを実行するために使うコード
 *     name = value の対を格納する簡単な記憶管理システム
 *     項目が環境の一部かどうか示すマークをサポートする
 *
 *     インターフェース：
 *         VLstore( name, value ) OKなら 1, そうでなければ 0 を返す
 *         VLlookup( name )       文字列を返す。含まれていなければ NULL を返す
 *         VLlist()               現在のテーブルを出力する
 *
 *     環境関連関数
 *         VLexport( name )       環境変数リストに名前を追加する
 *         VLtable2environ()      テーブルから環境にコピー
 *         VLenviron2table()      環境からテーブルにコピー
 *
 *     詳細：テーブルは、グローバルかどうかを示すフラグと name=value という形式の単一の
 *           文字列を含む構造体の配列という形で格納される。
 *           こうすると、環境への追加が楽になる。"name=" を探す限り、検索も簡単になる
 */

#include <stdio.h>
#include <stdlib.h>
#include "./header/varlib.h"
#include <string.h>

#define MAXVARS 200  // リストを使えばもっと良くなる

struct var {
    char* str;    // name=val文字列
    int   global; // 論理値
};

static struct var   tab[ MAXVARS ];             // テーブル
static struct var*  find_item( char*, int );
static        char* new_string( char*, char* ); // 非公開関数

int VLstore( char* name, char* val )
/*
 *   詳細：リストをたどり、名前が見つかったら値を交換する関数
 *         見つからなければ末尾に追加する
 *         削除はない
 * 戻り値：OKであれば 0, 問題があれば 1  （コマンドと同様）
 */
{
    struct var*  itemp;
           char* s;
           int   rv = 1;

    // 配置できそうなところを探し、新しい文字列を作る
    if( ( itemp = find_item( name, 1 )    ) != NULL &&
        ( s     = new_string( name, val ) ) != NULL
      ) {
        if( itemp->str ) free( itemp->str );
        itemp->str = s;
        rv = 0;
    }
    return rv;
}

char* new_string( char* name, char* val )
// name=value の形式の新文字列を返す。エラーの時は NULL を返す
{
    char* retval;

    retval = malloc( strlen( name ) + strlen( val ) + 2 );
    if( retval != NULL ) sprintf( retval, "%s=%s", name, val );
    return retval;
}

char* VLlookup( char* name )
// 戻り値： var の値を返す。name が設定されていなければ 空文字を返す
{
    struct var* itemp;

    if( ( itemp = find_item( name, 0 ) ) != NULL ) return itemp->str + 1 + strlen( name );
    return "";
}

int VLexport( char* name )
/*
 *   詳細：var にエキスポート必要のマークを付ける。
 *         その名前の変数がなければ追加する
 * 戻り値：問題があれば 1, OK であれば 0 を返す
 */
{
    struct var* itemp;
           int  rv = 1;

    if( ( itemp = find_item( name, 0 ) ) != NULL ) {
        itemp->global = 1;
        rv            = 0;
    }
    else if( VLstore( name, "" ) == 1 ) rv = VLexport( name );

    return rv;
}

static struct var* find_item( char* name, int first_blank )
/*
 *   詳細：テーブルから項目を探す
 * 戻り値：nameが存在する場合、構造ポインタを返す
 *         nameが見つからない場合、first_blank が 0 でなければ最初の空項目を探す
 *         から項目が見つかった場合そのポインタを返し、見つからない場合は NULL を返す
 */
{
    int   i;
    int   len = strlen( name );
    char* s;

    for( i = 0; i < MAXVARS && tab[i].str != NULL; i++ ) {
        s = tab[i].str;
        if( strncmp( s, name, len ) == 0 && s[len] == '=' ) {
            return &tab[i];
        }
    }

    if( i < MAXVARS && first_blank ) return &tab[i];

    return NULL;
}

void VLlist()
/*
 * 詳細：シェルの set コマンドを実行する
 *       変数テーブルの内容のリストを表示する
 *       この時、エキスポートされる変数は '*' 記号を追加する
 */
{
    int i;

    for( i = 0; i < MAXVARS && tab[i].str != NULL; i++ ) {
        if( tab[i].global ) printf( "   * %s\n", tab[i].str );
        else                printf( "     %s\n", tab[i].str );
    }
}

int VLenviron2table( char* env[] )
/*
 *   詳細：環境の文字列配列をロードして変数テーブルを初期化する
 * 戻り値：OKなら 1, そうでなければ 0 を返す
 */
{
    int   i;
    char* newstring;

    for( i = 0; env[i] != NULL; i++ ) {
        if( i == MAXVARS ) return 0;

        newstring = malloc( 1 + strlen( env[i] ) );
        if( newstring == NULL ) return 0;

        strcpy( newstring, env[i] );
        tab[i].str    = newstring;
        tab[i].global = 1;
    }

    while( i < MAXVARS ) {      // 静的なグローバル変数はデフォルトで
        tab[i].str      = NULL; // 初期化時に 0 でセットされるので、
        tab[i++].global = 0;    // これは本来不要な処理
    }

    return 1;
}

char** VLtable2environ()
/*
 *   詳細：新しい環境として使えるポインタ配列を構築する
 *   注意：メモリリークを避けるために、不要になったら開放する必要がある
 * 戻り値：環境配列を記録する配列ポインタ
 */
{
    int    i;      // 添え字
    int    j;      // 別の添え字
    int    n = 0;  // カウンタ
    char** envtab; // ポインタ配列

    // グローバル変数の数を数える
    for( i = 0; i < MAXVARS && tab[i].str != NULL; i++ ) {
        if( tab[i].global == 1 ) n++;
    }

    // 次に、その数の変数を格納できるだけの空間を確保する
    envtab = ( char** )malloc( ( n + 1 )*sizeof( char* ) );
    if( envtab == NULL ) return NULL;

    // 次に、配列にポインタをロードする
    for( i = 0, j = 0; i < MAXVARS && tab[i].str != NULL; i++ ) {
        if( tab[i].global == 1 ) envtab[j++] = tab[i].str;
    }

    envtab[j] = NULL;
    return envtab;
}
