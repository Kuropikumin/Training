#include <stdio.h>

#define ITEMS 7

int main( void )
{
    int narray[ITEMS] = { 500, 100, 800, 400, 200, 700, 900 };

    int* pnarray[ITEMS] = { NULL };
    int* pitem          = NULL;

    int i, j;

    for( i = 0; i < ITEMS; i++ ) pnarray[i] = &narray[i];

    for( i = 0; i < ITEMS; i++ ) printf( "%d ", *pnarray[i] );
    printf( "\n" );

    for( i = 0, j = ITEMS - 1; i < j; i++, j-- ) {
        pitem      = pnarray[i];
        pnarray[i] = pnarray[j];
        pnarray[j] = pitem;
    }
    
    for( i = 0; i < ITEMS; i++ ) printf( "%d ", *pnarray[i] );
    printf( "\n" );

    return 0;
}
