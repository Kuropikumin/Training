/* ls1.c
 *     目的：ディレクトリ（複数の場合も含む）の内容をリストアップする
 *     動作：引数がない場合は、"."、そうでなければ引数のディレクトリに含まれるファイルを出力する
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_ls( char [] );

int main( int argc, char* args[] )
{
    if( argc == 1 ) do_ls( "." );
    else {
        while( --argc ) {
            printf( "%s: \n", *++args );
            do_ls( *args );
        }
    }

        return 0;
}

// dirname  というディレクトリのファイルをリストアップする
void do_ls( char dirname[] )
{
    DIR*           dir_ptr;
    struct dirent* direntp;

    if( ( dir_ptr = opendir( dirname ) ) == NULL ) fprintf( stderr, "ls1: cannot open %s\n", dirname );
    else {
        while( ( direntp = readdir( dir_ptr ) ) != NULL ) printf( "%s\n", direntp->d_name );
        closedir( dir_ptr );
    }
}
