#include <stdio.h>

int main( void )
{
    long          l  = 2000000000;
    short         sh;
    char          ch;
    unsigned int  un = 4000000000;
    unsigned char uch;
    double        db = 3.14159265358979323;
    float         fl;

    sh = l;
    printf( "l(%ld)を代入したsh: %hd\n", l, sh );

    ch = sh;
    printf( "sh(%hd)を代入したch: %d\n", sh, ch );

    uch = un;
    printf( "un(%u)を代入したuch: %u\n", un, uch );

    fl = db;
    printf( "db(%.15f)を代入したfl: %.15f\n", db, fl );

    return 0;
}
