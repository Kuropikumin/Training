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

static int count_line( const char* path ) {
    FILE* f;
    int c;
    int prev, count = 0;

    if( !( f = fopen( path, "r" ) ) ) die( path );
    while( ( c = fgetc( f ) ) != EOF ) {
        if( c == '\n' ) count += 1;
        prev = c;
    }
    if( prev != '\n' ) count += 1;

    return count;
}

static void die( const char* s ) {
    perror( s );
    exit( 1 );
}
