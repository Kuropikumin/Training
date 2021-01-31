/* showtty.c
 *     現在のtty設定の一部を表示する
 */

#include <stdio.h>
#include <stdlib.h> // exit を利用するためにinclude（設定しないとwarningになる）
#include <termios.h>

#define oops( s, x ) { perror( s ); exit( x ); }

struct flaginfo{ int fl_value; char* fl_name; };

struct flaginfo input_flags[] = {
    { IGNBRK, "Ignore break condition" },
    { BRKINT, "Signal interrupt on break" },
    { IGNPAR, "Ignore chars with parity errors" },
    { PARMRK, "Mark parity errors" },
    { INPCK , "Enable input parity check" },
    { ISTRIP, "Strip character" },
    { INLCR , "Map NL to CR on input" },
    { IGNCR , "Ignore CR" },
    { ICRNL , "Map CR to NL on input" },
    { IXON  , "Enable start/stop output control" },
    // { _IXANY, "すべての文字の再出力を可能にする" },
    { IXOFF , "Enable start/stop input control" },
    { 0     , NULL }
};

struct flaginfo local_flags[] = {
    { ISIG  , "Enable signals" },
    { ICANON, "Canonical input ( erase and kill )" },
    // { _XCASE, "カノニカルな大文字/小文字表示に" },
    { ECHO  , "Enable echo" },
    { ECHOE , "Echo ERASE as BS-SPACE-BS" },
    { ECHOK , "Echo KILL by starting new line" },
    { 0     , NULL }
};

void showbaud( int thespeed );
void show_some_flags( struct termios* ttyp );
void show_flagset( int thevalue, struct flaginfo thebitnames[] );

int main( void )
{
    struct termios info;

    if( tcgetattr( 0, &info ) == -1 ) {
        oops( "tcgetattr error:", 1 );
    }
    else {
        showbaud( cfgetospeed( &info ) );
        printf( "The erase character is ascii %d, Ctrl-%c\n",
                info.c_cc[VERASE], info.c_cc[VERASE] - 1 + 'A' );
        printf( "The line kill character is ascii %d, Ctrl-%c\n",
                info.c_cc[VKILL], info.c_cc[VKILL] - 1 + 'A' );
        show_some_flags( &info );
    }
    return 0;
}

void showbaud( int thespeed )
// 英語でスピードを表示する
{
    printf( "the baud rate is " );
    switch( thespeed ) {
        case B300:  printf( "300\n" );                 break;
        case B600:  printf( "600\n" );                 break;
        case B1200: printf( "1200\n" );                break;
        case B1800: printf( "1800\n" );                break;
        case B2400: printf( "2400\n" );                break;
        case B4800: printf( "4800\n" );                break;
        case B9600: printf( "9600\n" );                break;
        default:    printf( "Fast!! %d\n", thespeed ); break;
    }
}

void show_some_flags( struct termios* ttyp )
/* c_iflag と c_lflag の2つのフラグセットの値を表示する
 * c_oflag と c_cflag はごく簡単に追加できる
 * 構造体配列を追加して、ここに2行分のコードを追加すればよい
 */
{
    show_flagset( ttyp->c_iflag, input_flags );
    show_flagset( ttyp->c_lflag, local_flags );
}

void show_flagset( int thevalue, struct flaginfo thebitnames[] )
// 各ビットパターンをチェックし、わかりやすいタイトルを表示する
{
    int i;

    for( i = 0; thebitnames[i].fl_value; i++ ) {
        printf( " %s is ", thebitnames[i].fl_name );
        if( thevalue & thebitnames[i].fl_value ) printf( "ON\n" );
        else                                     printf( "OFF\n" );
    }
}
