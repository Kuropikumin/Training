#include <stdio.h>
#include <string.h>

int main( void )
{
    char buff1[100] = "連結その1";

    char buff2[] = "連結その2";

    strcat( buff1, buff2 );

    printf( "buff1の文字列: %s\n", buff1 );
    return 0;
}
