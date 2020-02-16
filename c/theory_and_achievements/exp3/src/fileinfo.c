/* fileinfo.c - stat() を使ってファイルのプロパティを取得し表示する
 *            - 一部のメンバは、意味が分からない値をそのまま表示している
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void show_stat_info(char* filename, struct stat* buf) // 名前：値 形式で stat 情報の一部を表示する
{
    printf("   mode: %o\n", buf->st_mode);
    printf("  links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("  group: %d\n", buf->st_gid);
    printf("   size: %ld\n", buf->st_size);
    printf("modtime: %ld\n", buf->st_mtime);
    printf("   name: %s\n", filename);
}

int main(int argc, char* args[])
{
    struct stat info; // ファイル情報を取得するためのバッファ

    if( argc > 1 ) {
        if( stat( args[1], &info ) != -1 ) {
            show_stat_info( args[1], &info );
            return 0;
        }
        else {
            perror( args[1] );
        }
    }

    return 1;
}
