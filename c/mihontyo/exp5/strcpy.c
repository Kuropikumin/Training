#include <stdio.h>
#include <string.h>

#define BUFF_SIZE   100
#define ALPHA       65
#define ALPHA_COUNT 26

int main( void )
{
    char buff[BUFF_SIZE] = "";
    char work[BUFF_SIZE];
    int  i, j;

    for( i = ALPHA, j = 0; i < ALPHA + ALPHA_COUNT; i++, j++ ) {
        work[j++] = ( char )i;
        work[j]   = ' ';
    }
    work[j] = '\0';

    strcpy( buff, work );

    printf( "配列buffの文字列: %s\n", buff );
    return 0;
}
