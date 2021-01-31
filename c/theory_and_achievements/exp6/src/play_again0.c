/* play_again0.c
 *     目的  ：ユーザがほかのトランザクションを望んでいるかどうかを尋ねる
 *     方法  ：質問をして、Yes/Noの回答を待つ
 *     戻り値：0->Yes, 1->No
 *     改善点：いちいちEnterを押さなくても済むようにする
 *
 */

#include <stdio.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

int get_response( char* question );

int main( void )
{
    int response;

    response = get_response( QUESTION );
    return response;
}

int get_response( char* question )
/*
 * 目的  ：質問をして Yes/No の回答を待つ
 * 方法  ：getcharを使って y/n 以外の回答を無視する
 * 戻り値：0->Yes, 1->No
 */
{
    printf( "%s (y/n)?", question );
    while( 1 ) {
        switch( getchar() ) {
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N':
            case EOF: return 1;
        }
    }
}
