/* play_again1.c
 *     目的  ：ユーザがほかのトランザクションを望んでいるかどうかを尋ねる
 *     方法  ：ttyをcr（非カノニカル）モードにして文字を読み込み、結果を返す
 *     戻り値：0->Yes, 1->No
 *     改善点：不適切な入力に対してエコーを返さないようにする
 *
 */

#include <stdio.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

int  get_response( char* question );
void set_crmode();
int  tty_mode( int how );

int main( void )
{
    int response;

    tty_mode( 0 );                        // ttyモードの情報を保持
    set_crmode();                         // ttyを、crモードに変更
    response = get_response( QUESTION );  // 回答を取得
    tty_mode( 1 );                        // 設定を復元
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
    int input;

    while( 1 ) {
        switch( input = getchar() ) {
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N':
            case EOF: return 1;
            default:
                printf( "\ncannot understand %c, ", input );
                printf( "Please type y or n\n" );
        }
    }
}

void set_crmode()
/*
 * 目的：ファイルディスクリプタ0（標準入力）をcrモードにする
 * 方法：termios のビットを操作する
 */
{
    struct termios ttystate;

    tcgetattr( 0, &ttystate );          // 現在のttyの情報を読み込む
    ttystate.c_lflag    &= ~ICANON;     // icanonオプションをオフにする設定（ICANON フラグの補数との＆でフラグをオフにできる）
    ttystate.c_cc[VMIN] =  1;           // 1文字ずつ読み込む設定
    tcsetattr( 0, TCSANOW, &ttystate ); // 設定を反映させる
}

int tty_mode( int how )
/*
 * how == 0 -> 現在のモードをセーブ、 how == 1 -> モードを復元
 */
{
    static struct termios original_mode;
    if     ( how == 0 ) {
        tcgetattr( 0, &original_mode );
        return 0;
    }
    else if( how == 1 ) return tcsetattr( 0, TCSANOW, &original_mode );
    else return -1;
}
