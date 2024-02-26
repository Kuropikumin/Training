#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int count_line( const char* path );
static void die( const char* s );

int main( int argc, char* argv[] ) {
    int i;

    if( argc < 2 ) {
        fprintf( stderr, "%s: file name not given\n", argv[0] );
        return 1;
    }
    for( i = 1; i < argc; i ++ ){
        printf( "%s: %d\n", argv[i], count_line( argv[i] ) );
    }
}

#define BUFFER_SIZE 2048

static int count_line( const char* path ) {
    int fd;
    unsigned char buf[BUFFER_SIZE];
    int n;
    int i, count = 0;

    fd = open( path, O_RDONLY );
    if( fd < 0 ) die( path );
    for( ;; ) {
        n = read( fd, buf, sizeof buf );
        if( n < 0 ) die( path );
        if( n == 0 ) break;
        if( n > 0 ) {
            for( i = 0; i < n; i++ ) {
                if( buf[i] == '\n' ) count++;
            }
        }
    }

    return count;
}

static void die( const char* s ) {
    perror( s );
    exit( 1 );
}
