#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* args[])
{
    struct stat infobuf;

    if ( argc == 2 ) {
        if( stat( *(args + 1), &infobuf) == -1 ) { //情報取得を実施
            perror( *(args + 1) );
        }
        else {
            printf(" The size of %s is %d\n", *(args + 1), infobuf.st_size);
        }
    }
    else {
        printf( "Usage: filesize file_name\n");
        exit(1);
    }

    return 0;
}
