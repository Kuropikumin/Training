/* lclnt1.c - ライセンスサーバクライアントバージョン
 *     lclnt_funcs1.o dgram.o とリンク
 */

#include <stdio.h>
#include <stdlib.h> // exit 関数を利用するために必要
#include <unistd.h> // sleep 関数を利用するために必要

// 別ファイル(lclnt_funcs1.c)
void setup();
void shut_down();
int  get_ticket();
void release_ticket();
int  validate_ticket();

void do_regular_work()
/* アプリケーションの本来の仕事がここに入る
 */
{
    printf( "SuperSleep version 1.0 Running - Licensed Software\n" );
    sleep( 10 );

    if( validate_ticket() != 0 ) {
        printf( "Server errors. Please Try later.\n" );
        return;
    }
    sleep( 10 );
}

int main( int ac, char* av[] )
{
    setup();
    if( get_ticket() != 0 ) exit ( 0 );

    do_regular_work();

    release_ticket();
    shut_down();

    return 0;
}
