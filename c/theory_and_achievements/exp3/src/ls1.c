/* ls1.c
 *     $BL\E*!'%G%#%l%/%H%j!JJ#?t$N>l9g$b4^$`!K$NFbMF$r%j%9%H%"%C%W$9$k(B
 *     $BF0:n!'0z?t$,$J$$>l9g$O!"(B"."$B!"$=$&$G$J$1$l$P0z?t$N%G%#%l%/%H%j$K4^$^$l$k%U%!%$%k$r=PNO$9$k(B
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

// dirname  $B$H$$$&%G%#%l%/%H%j$N%U%!%$%k$r%j%9%H%"%C%W$9$k(B
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
