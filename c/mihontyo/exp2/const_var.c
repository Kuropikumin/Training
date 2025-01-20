#include <stdio.h>

#define DQUOTE '\"'
#define SQUOTE '\''
#define YEN    '\\'
#define HTAB   '\t'
#define BEEP   '\a'
#define LF     '\n'

int main( void )
{
    int  i;
    char str[] = "これはビープのテストです";
    char c;

    for( i = 0; i < 20; i++ ) printf( "%c%s%c%c%c", DQUOTE, str, DQUOTE, BEEP, HTAB );
    printf( "%c", LF);

    c = YEN;
    for( i = 0; i < 20; i++ ) printf( "%c ", c);
    printf( "%c", LF );

    c = SQUOTE;
    for( i = 0; i < 20; i++ ) printf( "%c ", c);
    printf( "%c", LF );

    c = DQUOTE;
    for( i = 0; i < 20; i++ ) printf( "%c ", c);
    printf( "%c", LF );

    return 0;
}