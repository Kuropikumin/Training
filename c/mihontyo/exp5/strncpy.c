#include <stdio.h>
#include <string.h>

#define BUFF_SIZE   100

int main( void )
{
    char buff1[BUFF_SIZE] = "コピー先の元の文字列";
    char buff2[]          = "文字列はどうなる？";

    strncpy( buff1 + 15, buff2, sizeof buff2 - 18 );
    buff1[24] = '\0';
    printf( "sizeof buff2 = %ld, sizeof buff2 - 12 = %ld, sizeof( buff2 - 12 ) = %ld, buff2 - 12 = %s\n", sizeof buff2, sizeof buff2 - 12, sizeof( buff2 - 12 ), buff2 - 12 );

    printf( "配列buff1の文字列: %s\n", buff1 );
    return 0;
}
