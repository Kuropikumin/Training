/* ls1.c
 *     $BL\E*!'%G%#%l%/%H%j!JJ#?t$N>l9g$b4^$`!K$NFbMF$r%j%9%H%"%C%W$9$k(B
 *     $BF0:n!'0z?t$,$J$$>l9g$O!"(B"."$B!"$=$&$G$J$1$l$P0z?t$N%G%#%l%/%H%j$K4^$^$l$k%U%!%$%k$r=PNO$9$k(B
 *     $BCm0U!'(Bstat $B$H(B  pwd.h $B!"(B grp.h $B$rMxMQ$9$k(B
 *     $B%P%0!'(Bls2 /tmp $B$r<B;\$7$F$_$k(B
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

// dirname  $B$H$$$&%G%#%l%/%H%j$N%U%!%$%k$r%j%9%H%"%C%W$9$k(B
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
    if( stat( check_file_name, &info ) == -1 ) perror( file_name ); // stat $B$N<hF@!#<:GT$7$?>l9g!"%(%i!<$r=PNO$9$k(B
    else show_file_info( file_name, &info );                  // stat $B$N>pJs$rJQ49$7$FI=<($9$k(B
}

void show_file_info( char* file_name, struct stat* info_p ) // file_name $B$N>pJs$r<h$j=P$9!#>pJs$O(B info_p $B$K3JG<$5$l$F$$$k(B
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

/* $B%f!<%F%#%j%F%#4X?t(B
 *   $B$3$l$i$N4X?t$O(B st_mode $B$H(B char $BG[Ns$r<u$1IU$1!"$3$NG[Ns$K%U%!%$%k%?%$%W%H%Q!<%_%C%7%g%s$KBP1~$9$k(B 9 $BJ8;z$r%;%C%H$9$k(B
 *   $BCm0U!'(Bsuid$B!"(Bsgid$B!"(Bsticky $B%S%C%H$K4XO"$9$k%3!<%I$O%;%C%H$7$J$$(B
*/

void mode_to_letters( int mode, char str[] )
{
    strcpy( str, "----------" ); // $B%G%U%)%k%H@_Dj!J?t$Y<j$N%Q!<%_%C%7%g%s$,$J$$>uBV!K(B

    if( S_ISDIR( mode ) ) str[0] = 'd'; // $B%G%#%l%/%H%j$G$"$k$+$N3NG'(B
    if( S_ISCHR( mode ) ) str[0] = 'c'; // $B%-%c%i%/%?%G%P%$%9$G$"$k$+$N3NG'(B
    if( S_ISBLK( mode ) ) str[0] = 'b'; // $B%V%m%C%/%G%P%$%9$G$"$k$+$N3NG'(B

    //$B%*!<%J!<$N%Q!<%_%C%7%g%s3NG'(B
    if( mode & S_IRUSR ) str[1] = 'r';
    if( mode & S_IWUSR ) str[2] = 'w';
    if( mode & S_IXUSR ) str[3] = 'x';

    //$B%0%k!<%W$N%Q!<%_%C%7%g%s3NG'(B
    if( mode & S_IRGRP ) str[4] = 'r';
    if( mode & S_IWGRP ) str[5] = 'w';
    if( mode & S_IXGRP ) str[6] = 'x';

    //$B$=$N$[$+(B $B%f!<%6$N%Q!<%_%C%7%g%s3NG'(B
    if( mode & S_IROTH ) str[7] = 'r';
    if( mode & S_IWOTH ) str[8] = 'w';
    if( mode & S_IXOTH ) str[9] = 'x';
}

#include <pwd.h>

// uid $B$KBP1~$9$k%f!<%6L>$r;X$9%]%$%s%?$rJV$9(B
// getpwuid $B$rMxMQ$9$k(B
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

// gid $B$KBP1~$9$k%0%k!<%WL>$r;X$9%]%$%s%?$rJV$9(B
// getgrgid $B$rMxMQ$9$k(B
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
