#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
    if( argc != 1 ) {
        printf( "引数を入力してください!\n" );
        return EXIT_FAILURE;
    }

    printf( "入力したコマンドライン引数: %s\n", argv[0] );

    return 0;
}