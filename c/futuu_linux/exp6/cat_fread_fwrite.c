#include <stdio.h>
#include <stdlib.h>

void do_cat( char* path );

int main( int argc, char* argv[] ) {
    int i;

    if( argc < 2 ) {
        fprintf( stderr, "%s: file name not given\n", argv[0] );
        exit( 1 );
    }

    for( i = 0 ; i < argc; i++ ) {
        do_cat( argv[i] );
    }
}

#define BUFFER_SIZE 2048

void do_cat( char* path ) {
    unsigned char buf[BUFFER_SIZE] = "";
    FILE* f;
    int flag = 1;

    if( ( f = fopen( path, "r" ) ) ) {
        while( flag ) {
            size_t n_read = fread( buf, 1, sizeof buf, f );
            if( ferror( f ) ) {
                fprintf( stderr, "%s: fread error\n", path );
                exit( 1 );
            }
            else {
                size_t n_written = fwrite( buf, 1, n_read, stdout );
                if( n_written < n_read ) {
                    fprintf( stderr, "%s: fwrite error\n", path );
                    exit( 1 );
                }
                else {
                    if( n_read < sizeof buf ) flag = 0;
                }
            }
        }
    }
    else {
        fprintf( stderr, "%s: file open error\n", path );
        exit( 1 );
    }
}