#include <stdio.h>
#include <string.h>

#define ITEMS  8
#define MAXLEN 15

int main( void )
{
    char strarray[][MAXLEN + 1] = { "なたね", "あずき", "こんにゃく", "さとうきび", "じゃがいも", "てんさい", "さつまいも", "らっかせい" };
    
    // 入れ替え作業用の配列
    char* pstrarray[ITEMS] = {""};
    char* ptemp            = "";

    int i, sortedpos, tobeselected; // ループ制御
    int count = 0;

    for( i = 0; i < ITEMS; i++ ) printf( "%s ", strarray[i] );
    printf( "\n" );

    // ポインタ配列の初期化
    for( i = 0; i < ITEMS; i++ ) pstrarray[i] = &strarray[i][0];


    for( sortedpos = 0; sortedpos < ITEMS; sortedpos++ ) {
        tobeselected = sortedpos;
        for( i = sortedpos + 1; i < ITEMS; i++ ) {
            if( strcmp( pstrarray[tobeselected], pstrarray[i] ) > 0 ) tobeselected = i;
        }

        ptemp                   = pstrarray[tobeselected];
        pstrarray[tobeselected] = pstrarray[sortedpos];
        pstrarray[sortedpos]    = ptemp;
        count += 3;
    }

    for( i = 0; i < ITEMS; i++ ) printf( "%s ", pstrarray[i] );
    printf( "\n" );

    for( i = 0; i < ITEMS; i++ ) printf( "%s ", strarray[i] );
    printf( "\n" );
    
    printf( "コピーした回数: %d\n", count );

    return 0;
}
