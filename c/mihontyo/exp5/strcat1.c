#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100

int main( void )
{
    char buff1[BUFF_SIZE] = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', '\0'
    };

    char buff2[] = {
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'
    };

    strcat( buff1, buff2 );

    printf( "buff1の文字列: %s\n", buff1 );
    return 0;
}
