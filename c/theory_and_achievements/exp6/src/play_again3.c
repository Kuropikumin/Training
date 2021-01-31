/* play_again3.c
 *     目的  ：ユーザがほかのトランザクションを望んでいるかどうかを尋ねる
 *     方法  ：ttyをcr（非カノニカル）モード, エコーなしモード, 遅延なしモードにして文字を読みこみ、結果を返す
 *     戻り値：0->Yes, 1->No, 2->タイムアウト
 *     改善点：SIGINTが発生したときに端末モードをリセットするようにする
 */

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> // sleep関数を利用するために追加
#include <ctype.h>  // tolower関数を利用するために追加

#define ASK       "Do you want another transaction"
#define TRIES     3
#define SLEEPTIME 2
#define BEEP      putchar( '\a' )

int  get_response( char* question, int maxtries );
int  tty_mode( int how );
int  get_ok_char();
void set_cr_noecho_mode();
void set_nodelay_mode();

int main( void )
{
    int response;

    tty_mode( 0 );                         // ttyモードの情報を保持
    set_cr_noecho_mode();                  // ttyを、crモード、エコーなしモードに変更
    set_nodelay_mode();                    // 入力なしならEOFと同じ
    response = get_response( ASK, TRIES ); // 回答を取得

    printf("\n");
    if     ( response == 0 ) printf( "You select Yes\n" );
    else if( response == 1 ) printf( "You slect No\n" );
    else if( response == 2 ) printf( "Time out\n" );

    tty_mode( 1 );                         // 設定を復元
    return response;
}

int get_response( char* question, int maxtries )
/*
 * 目的  ：質問をして Yes/No の回答を待つ
 * 方法  ：getcharを使って y/n 以外の回答に警告を鳴らす
 * 戻り値：0->Yes, 1->No, 2->タイムアウト
 */
{
    int input;
    printf( "%s (y/n)?", question ); // 質問文
    fflush( stdout );                // 標準入力をリセットする

    while( 1 ) {
        sleep( SLEEPTIME );
        input = tolower( get_ok_char() );
        if      ( input == 'y' )    return 0;
        else if ( input == 'n' )    return 1;
        else if ( maxtries-- == 0 ) return 2;
        BEEP;
    }
}

int tty_mode( int how )
/*
 * how == 0 -> 現在のモードをセーブ、 how == 1 -> モードを復元
 * termios だけでなく、 fcntl フラグも処理する
 */
{
    static struct termios original_mode;
    static int            original_flags;

    if     ( how == 0 ) {
        tcgetattr( 0, &original_mode );
        original_flags = fcntl( 0, F_GETFL );
        return 0;
    }
    else if( how == 1 ) {
        int result_attr, result_fcntl = 0;
        result_attr  = tcsetattr( 0, TCSANOW, &original_mode );
        result_fcntl = fcntl( 0, F_SETFL, original_flags );

        if( result_attr == -1 || result_fcntl == -1 ) return -1;
        else                                          return 0;
    }
    else return -1;
}

int get_ok_char()
/*
 * 認められている文字列（今回では y, Y, n, N の4種類）の入力があるまで待つ
 * それ以外の入力があった場合、何も表示せずに再度入力を待つ
 */
{
    int c;
    while( ( c = getchar() ) != EOF && strchr( "yYnN", c ) == NULL ) ;
    return c;
}

void set_cr_noecho_mode()
/*
 * 目的：ファイルディスクリプタ0（標準入力）をcrモード, エコーなしモードにする
 * 方法：termios のビットを操作する
 */
{
    struct termios ttystate;

    tcgetattr( 0, &ttystate );          // 現在のttyの情報を読み込む
    ttystate.c_lflag    &= ~ICANON;     // icanonオプションをオフする設定（ICANON フラグの補数との＆でフラグをオフにできる）
    ttystate.c_lflag    &= ~ECHO;       // echoオプションをオフにする設定（ECHO フラグの補数との＆でフラグをオフにできる）
    ttystate.c_cc[VMIN] =  1;           // 1文字ずつ読み込む設定
    tcsetattr( 0, TCSANOW, &ttystate ); // 設定を反映させる
}

void set_nodelay_mode()
/*
 * 目的：ファイルディスクリプタ0（標準入力）を遅延なしモード（ブロック解除）にする
 * 方法：fctlを使ってビットを設定する
 * 注意：tcsetattr() でも同じことができるが煩雑になる
 */
{
    int termflags;

    termflags = fcntl( 0, F_GETFL ); // 現在の設定を飲みだす
    termflags |= O_NDELAY;           // 遅延なし設定をオンにする
    fcntl( 0, F_SETFL, termflags );  // 設定を反映させる
}
