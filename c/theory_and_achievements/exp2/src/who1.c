#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST

void show_info( struct utmp* );

int main()
{
    struct utmp current_record;  // 情報をここに読みだす
    int    utmpfd;               // このデスクリプタから読み出す
    int    reclen = sizeof( current_record );

    if(( utmpfd = open( UTMP_FILE, O_RDONLY )) == -1 )
    {
        perror( UTMP_FILE ); // UTMP_FILEはutmp.hで定義されている
        exit( 1 );
    }

    while( read( utmpfd, &current_record, reclen ) == reclen ) show_info( &current_record );
    close( utmpfd );
    return 0;
}

void show_info( struct utmp* utbufp )
{
    printf("%-8.8s", utbufp->ut_name); // ログイン名
    printf(" ");
    printf("%-8.8s", utbufp->ut_line); // tty
    printf(" ");
    printf("%10ld",  utbufp->ut_time); // ログイン時間
    printf(" ");
    #ifdef SHOWHOST
        printf("(%s)", utbufp->ut_host); // ホスト
    #endif
    printf("\n");
}
