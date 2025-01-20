#include <stdio.h>
#include <string.h>

#define BUFF_SIZE   100

int main( void )
{
    char buff1[] = "比較文字";
    char buff2[] = "比較文字";
    char buff3[BUFF_SIZE];

    strncpy( buff3, buff2, strlen( buff2 ) );
    buff3[strlen( buff2 )] = '\0';
    
    if( strcmp( buff1, buff3 ) == 0 ) printf( "buff1とbuff3は同一の文字列\n" );
    else                              printf( "buff1とbuff3は同一の文字列ではない\n" );

    return 0;
}
