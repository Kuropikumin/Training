/* ls1.c
 *     目的：ディレクトリ（複数の場合も含む）の内容をリストアップする
 *     動作：引数がない場合は、"."、そうでなければ引数のディレクトリに含まれるファイルを出力する
 *     注意：stat と  pwd.h 、 grp.h を利用する
 *     バグ：ls2 /tmp を実施してみる
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void do_ls( char [] );
void do_stat( char*, char* );
void show_file_info( char*, struct stat* );
void mode_to_letters( int, char [] );
char* uid_to_name( uid_t );
char* gid_to_name( gid_t );

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
void do_ls( char dir_name[] )
{
    DIR*           dir_ptr;
    struct dirent* direntp;

    if( ( dir_ptr = opendir( dir_name ) ) == NULL ) fprintf( stderr, "ls1: cannot open %s\n", dir_name );
    else {
        while( ( direntp = readdir( dir_ptr ) ) != NULL ) do_stat( dir_name, direntp->d_name );
        closedir( dir_ptr );
    }
}

void do_stat( char* dir_name, char* file_name )
{
    struct stat info;

    char check_file_name[256] = {'\n'};
    sprintf(check_file_name, "%s%s", dir_name, file_name );
    if( stat( check_file_name, &info ) == -1 ) perror( file_name ); // stat の取得。失敗した場合、エラーを出力する
    else show_file_info( file_name, &info );                  // stat の情報を変換して表示する
}

void show_file_info( char* file_name, struct stat* info_p ) // file_name の情報を取り出す。情報は info_p に格納されている
{
    char* uid_to_name();
    char* ctime();
    char* gid_to_name();
    char* filemode();
    void  mode_to_letters();
    char  mode_str[11];

    mode_to_letters( info_p->st_mode, mode_str );

    printf("%s ",    mode_str);
    printf("%4ld ",  info_p->st_nlink);
    printf("%-8s ",  uid_to_name(info_p->st_uid));
    printf("%-8s ",  gid_to_name(info_p->st_gid));
    printf("%ld ",   info_p->st_size);
    printf("%.12s ", 4+ctime(&info_p->st_mtime));
    printf("%s\n",   file_name);
}

/* ユーティリティ関数
 *   これらの関数は st_mode と char 配列を受け付け、この配列にファイルタイプトパーミッションに対応する 9 文字をセットする
 *   注意：suid、sgid、sticky ビットに関連するコードはセットしない
*/

void mode_to_letters( int mode, char str[] )
{
    strcpy( str, "----------" ); // デフォルト設定（数べ手のパーミッションがない状態）

    if( S_ISDIR( mode ) ) str[0] = 'd'; // ディレクトリであるかの確認
    if( S_ISCHR( mode ) ) str[0] = 'c'; // キャラクタデバイスであるかの確認
    if( S_ISBLK( mode ) ) str[0] = 'b'; // ブロックデバイスであるかの確認

    //オーナーのパーミッション確認
    if( mode & S_IRUSR ) str[1] = 'r';
    if( mode & S_IWUSR ) str[2] = 'w';
    if( mode & S_IXUSR ) str[3] = 'x';

    //グループのパーミッション確認
    if( mode & S_IRGRP ) str[4] = 'r';
    if( mode & S_IWGRP ) str[5] = 'w';
    if( mode & S_IXGRP ) str[6] = 'x';

    //そのほか ユーザのパーミッション確認
    if( mode & S_IROTH ) str[7] = 'r';
    if( mode & S_IWOTH ) str[8] = 'w';
    if( mode & S_IXOTH ) str[9] = 'x';
}

#include <pwd.h>

// uid に対応するユーザ名を指すポインタを返す
// getpwuid を利用する
char* uid_to_name( uid_t uid )
{
    struct passwd* getpwuid();
    struct passwd* pw_ptr;
    static char    numstr[10];

    if( ( pw_ptr = getpwuid( uid ) ) == NULL ) {
        sprintf( numstr, "%d", uid );
        return numstr;
    }
    else return pw_ptr->pw_name;
}

#include <grp.h>

// gid に対応するグループ名を指すポインタを返す
// getgrgid を利用する
char* gid_to_name( gid_t gid )
{
    struct group* getgrgid();
    struct group* grp_ptr;
    static char   numstr[10];

    if( ( grp_ptr = getgrgid( gid ) ) == NULL ) {
        sprintf( numstr, "%d", gid );
        return numstr;
    }
    else return grp_ptr->gr_name;
}
