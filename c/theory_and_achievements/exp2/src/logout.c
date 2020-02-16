/* logout tty(char* line)
 *     utmp レコードにログアウトのマークをつける
 *     ユーザ名やリモートホスト名を空にはしない
 *     エラーの時は -1、成功した時は 0 を返す
*/

int logout_tty( char* line )
{
    int         fd;
    struct utmp rec;
    int         len = sizeof( struct utmp );
    int         retval = -1;                 // 悲観主義

    if( ( fd = open( UTMP_FILE, O_RDWR ) ) == -1 ) return -1; // ファイルのオープンに失敗したらエラーなので -1 を返す

    // 検索して置換する
    while( read( fd, &rec, len ) == len ) {
        if( strncmp( rec.ut_line, line, sizeof( rec.ut_line ) ) == 0 ) {
            rec.ut_type = DEAD_PROCESS;                             // ut_type を設定
            if( time( &rec.ut_time ) != -1 ) {                      // 時刻を設定
                if( lseek( fd, -len, SEEK_CUR ) != -1 ) {           // バックアップ
                    if( write( fd, &rec, len ) == len ) retval = 0; // 更新をして成功したことを記録する
                }
            }

            break;
        }
    }

    if( close( fd ) == -1 ) retval = -1;
    return retval;
}
