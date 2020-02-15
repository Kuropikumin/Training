#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SHOWHOST

void show_info( struct utmp* );
void showtime (time_t);

int main()
{
    struct utmp* utbufp;       // 次のレコードをさすポインタを保持する
    struct utmp* *utmp_next(); // これがないとエラーになる

    if( utmp_open( UTMP_FILE ) == -1 ) {
        perror( UTMP_FILE ); // UTMP_FILEはutmp.hで定義されている
        exit( 1 );
    }

    while( ( utbufp = utmp_next() ) != (( struct utmp* ) NULL ) ) show_info( utbufp );
    utmp_close();
    return 0;
}

void show_info( struct utmp* utbufp )
{
    if( utbufp->ut_type != USER_PROCESS ) return;
    printf("%-8.8s", utbufp->ut_name); // ログイン名
    printf(" ");
    printf("%-8.8s", utbufp->ut_line); // tty
    printf(" ");
    showtime( utbufp->ut_time ); // ログイン時間
    printf(" ");
    #ifdef SHOWHOST
        printf("(%s)", utbufp->ut_host); // ホスト
    #endif
    printf("\n");
}

void showtime( long timeval )
/* 人間が理解しやすい形式で時刻を表示する
 * ctime を使って文字列を組み立ててから、その一部を抜き出す
 * 注意： %12.12s は文字列を char 12個分で出力紙、長さを12バイト以下に制限する
*/
{
    char* cp;                  // 時刻のアドレスを保持するポインタ
    cp = ctime( &timeval );    // 時刻を文字列に変換する
                               // 変換形式は以下のとおり
                               // Mon Feb  4 00:46:40 EST 1991 <-> 0123456789012345
    printf("%12.12s", cp + 4); // 4文字目から12文字を出力する
}
