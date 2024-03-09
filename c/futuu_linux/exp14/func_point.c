#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define INIT_BUFSIZE 1024

char* my_getcwd( void ) {
    char* buf;
    char* tmp;
    size_t size = INIT_BUFSIZE;

    buf = malloc( size );
    if( !buf ) {
        return NULL;
    }

    for( ;; ) {
        errno = 0;
        if( getcwd( buf, size ) ) {
            return buf;
        }
        if( errno != ERANGE ) {
            break;
        }
        size *= 2;
        tmp = realloc( buf, size );
        if( !tmp ) break;
        buf = tmp;
    }
    free( buf );
    return NULL;
}

int plus1( int n ) {
    return n + 1;
}

int main( int argc, char* argv[] ) {    
    int (*f)( int );
    int result;

    f = plus1;
    result = f( 5 );

    printf( "%d\n", result );

    exit( 0 );
}