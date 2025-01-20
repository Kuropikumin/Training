#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100

int main( void )
{
    char buff1[BUFF_SIZE] = "連絡先の文字列";

    char buff2[] = {
        ( char )0x98, ( char )0x41, ( char )0x8c, ( char )0x8b,
        ( char )0x82, ( char )0xb7, ( char )0x82, ( char )0xe9,
        ( char )0x95, ( char )0xb6, ( char )0x8e, ( char )0x9a,
        ( char )0x97, ( char )0xf1, '\0'
    };


    strcat( buff1, buff2 );

    printf( "buff1の文字列: %s, sizeof buff2: %ld\n", buff1, sizeof buff2 );
    return 0;
}
