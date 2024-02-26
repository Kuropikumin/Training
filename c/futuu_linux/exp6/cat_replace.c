#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
    int i;

    for( i = 1; i < argc; i ++ ){
        FILE* f;
        int c;

        f = fopen( argv[i], "r" );
        if( !f ) {
            perror( argv[i] );
            exit( 1 );
        }
        while( ( c = fgetc( f ) ) != EOF ) {
            char* rc = "";
            int   replace_flag = 1;
            if( c == '\t' ) {
                rc = "\\t"; 
            }
            else if( c == '\n' ) {
                rc = "$\n";
            }
            else {
                replace_flag = 0;
            }
            
            if( replace_flag ) {
                if( fputs( rc, stdout ) == EOF ) exit( 1 );
            }
            else {
                if( fputc( c, stdout ) < 0 ) exit( 1 );
            }
        }
        fclose( f );
    }
    exit( 0 );
}