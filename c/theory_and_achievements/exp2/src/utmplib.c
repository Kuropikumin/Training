/* utmplib.c - utmpファイルからの読み出しをバッファリングする関数
 *
 * 含まれる関数は次のとおり
 *     utmp_open( filename ) - ファイルをオープンする
 *                             エラーの時は-1を返す
 *     utmp_next( )          - 次の構造体をさすポインタを返す
 *                             eofの時にはNULLを返す
 *     utmp_close()          - ファイルを閉じる
 *
 *     一度の読み出しでNRECS個の構造体を読み出し、バッファから構造体を1個ずつ提供する
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <utmp.h>

#define NRECS 16
#define NULLUT (( struct utmp* ) NULL )
#define UTSIZE ( sizeof( struct utmp ) )

static char utmpbuf[NRECS*UTSIZE];
static int  num_recs;
static int  cur_rec;
static int  fd_utmp = -1;

int utmp_open( char* filename )
{
    fd_utmp = open( filename, O_RDONLY );
    cur_rec = num_recs = 0;
    return fd_utmp;
}

int utmp_reload() // バッファに、次のレコードのチャンクを読み出す
{
    int amt_read;                                      // 読み出したいバイト数
    amt_read = read( fd_utmp, utmpbuf, NRECS*UTSIZE ); // 何個得られたか？
    num_recs = amt_read/UTSIZE;                        // ポインタをリセットする
    cur_rec  = 0;
    return num_recs;
}

struct utmp* utmp_next()
{
    struct utmp* recp;

    if( fd_utmp == -1 ) return NULLUT;                             // エラー?
    if( cur_rec == num_recs && utmp_reload() == 0 ) return NULLUT; // まだ残っている？

    recp = ( struct utmp* ) &utmpbuf[cur_rec*UTSIZE];
    cur_rec++;
    return recp;
}

int utmp_close()
{
    if( fd_utmp != -1 ) close( fd_utmp ); // オープンされている fd_utmp をクローズする
    return 0;
}
