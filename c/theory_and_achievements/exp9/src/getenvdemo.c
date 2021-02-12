#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* cp = getenv( "LANG" );
    if( cp != NULL && strcmp( cp, "fr" ) == 0 ) printf( "Bonjour\n" );
    else                                        printf( "Hello\n" );

    return 0;
}
