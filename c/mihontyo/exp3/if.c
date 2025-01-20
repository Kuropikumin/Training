#include <stdio.h>
#include <string.h>

int main( void )
{
    char strarray[10][8] = {
        "いぬ1", "さる3", "うま2", "とり1", "さる1",
        "うま3", "いぬ1", "いぬ1", "うま2", "とり2" 
    };

    int uma = 0, inu = 0, saru = 0, tori = 0;
    int i = 0;

    while( i < 10 ) {
        if( strncmp( strarray[i], "うま", 6 ) == 0 ) {
            switch( strarray[i++][6] ) {
                case '1':
                    uma += 1;
                    break;
                case '2':
                    uma += 2;
                    break;
                case '3':
                    uma += 3;
            }   
        }
        else if( strncmp( strarray[i], "いぬ", 6 ) == 0 ) {
            switch( strarray[i++][6] ) {
                case '1':
                    inu += 1;
                    break;
                case '2':
                    inu += 2;
                    break;
                case '3':
                    inu += 3;
            }   
        }
        else if( strncmp( strarray[i], "とり", 6 ) == 0 ) {
            switch( strarray[i++][6] ) {
                case '1':
                    tori += 1;
                    break;
                case '2':
                    tori += 2;
                    break;
                case '3':
                    tori += 3;
            }               
        }
        else {
            switch( strarray[i++][6] ) {
                case '1':
                    saru += 1;
                    break;
                case '2':
                    saru += 2;
                    break;
                case '3':
                    saru += 3;
             }  
        }
    }

    printf( "うま: %d, いぬ: %d, とり: %d, さる%d\n", uma, inu, tori, saru);
    return 0;
}
