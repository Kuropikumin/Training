/* echoWindows.c
 *     使用方法：echoWindows
 */    

#include <sys/ioctl.h>
#include <stdio.h>

void printScreenDimensions();

int main( void )
{
    printScreenDimensions();
    return 0;
}

void printScreenDimensions()
{
    struct winsize wbuf;

    if( ioctl( 0, TIOCGWINSZ, &wbuf ) != -1 ) {
        printf( "%d rows x %d cols\n", wbuf.ws_row,    wbuf.ws_col );
        printf( "%d wide x %d tall\n", wbuf.ws_xpixel, wbuf.ws_ypixel );
    }
}
