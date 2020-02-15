#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFERSIZE 4096
#define COPYMODE   0644

void oops(char*, char*);

main(int argc, char* args[])
{
    int  in_fd, out_fd, n_chars;
    char buf[BUFFERSIZE];

    if(argc != 3) {
        fprintf( stderr, "usage: %s source destination\n", *args );
        exit(1);
    }

    if( ( in_fd  = open(  args[1], O_RDONLY ) ) == -1 ) oops("Cannot open ",  args[1]);
    if( ( out_fd = creat( args[2], COPYMODE ) ) == -1 ) oops("Cannot creat ", args[2]);

    // BUFFERSIZE 分データを取得して書き込む
    while( ( n_chars = read( in_fd, buf, BUFFERSIZE ) ) > 0 ) {
        if( write( out_fd, buf, n_chars ) != n_chars ) oops("Write error to ", args[2]);
    }

    if( n_chars == -1 ) oops("Read error from ", args[1]);

    if( close( in_fd ) == -1 || close( out_fd ) == 1) oops("Error closing files", "");

}

void oops(char* s1, char* s2)
{
    fprintf(stderr, "Error: %s ", s1);
    perror(s2);
    exit(1);
}
