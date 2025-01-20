#include <stdio.h>
#include <string.h>

#define MAX_SIZE 40

int main( void )
{
    int  i;
    char buff1[] = "初期化配列1";
    char buff2[MAX_SIZE + 1];

    for( i = 0; i < MAX_SIZE; i++ ) buff2[i] = 0x20;
    buff2[i] = '\0';

    printf("配列buff1: %s、長さ: %ld\n", buff1, strlen( buff1 ) );
    printf("配列buff2: %s、長さ: %ld\n", buff2, strlen( buff2 ) );

    return 0;
}
