// more01との変更点：コマンドは/dev/ttyから読み取る
#include <stdio.h>
#include <stdlib.h>

#define PAGELEN 24
#define LINELEN 512

void do_more ( FILE* );
int  see_more( FILE* );

int main( int argc, char* argv[] )
{
    FILE *fp;
    if( argc == 1 ) do_more( stdin );
    else
    {
        while( --argc )
        {
            if(( fp = fopen( *++argv, "r" )) != NULL )
            {
                do_more( fp );
                fclose( fp );
            }
            else exit( 1 );
        }
    }
    return 0;
}

/*
 PaGELEN 行の情報を読み、see_more()を呼び出して命令を待つ
 */
void do_more( FILE *fp )
{
    char line[LINELEN];
    int  num_of_lines = 0;
    int  reply;
    FILE* fp_tty;

    fp_tty = fopen( "/dev/tty", "r");  // コマンドストリームの設定
    if( fp_tty == NULL ) exit( 1 );    // コマンドストリームが利用できない場合は強制終了
    
    while( fgets( line, LINELEN, fp )) // 入力値がまだある場合
    {
        if( num_of_lines == PAGELEN ) // 画面いっぱいに表示されている場合
        {
            reply = see_more( fp_tty );       // 入力待ち

            if( reply == 0 ) break;    // 入力が「q」の場合、終了

            num_of_lines -= reply;    // カウンタをリセット
        }

        if( fputs( line, stdout ) == EOF ) exit( 1 ); //行を表示するか終了

        num_of_lines++;           // 行数を数える
    }
}

/*
 メッセージを出力して応答を待つ。先に進める行数を返す。
 qならノー、スペースならイエス、CRなら1行
 */
int see_more(FILE* cmd)
{
    int c;

    printf("\033[7m more? \033[m");
    while(( c = getc( cmd )) != EOF)
    {
        if      ( c == 'q' )  return 0;
        else if ( c == ' ' )  return PAGELEN;
        else if ( c == '\n' ) return 1;
    }
    return 0;
}
