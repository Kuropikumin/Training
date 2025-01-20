#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100

int main( void )
{
    char buff[BUFF_SIZE] = "";
    char strbuff[] = "この文字列を連結する";

    char* pchar = buff;

    strcat( pchar, strbuff );

    printf( "buffの文字列: %s\n", pchar );
    return 0;
}
