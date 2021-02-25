/* dgram.c
 *   目的：データグラムプログラムのためのサポート関数をまとめる
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define HOSTLEN 256

int make_internet_address( char* hostname, int port, struct sockaddr_in* addrp )
/*
 * ホスト名とポート番号を使ってインターネットソケットアドレスを組み立てる
 * (ホスト名, ポート番号) -> アドレス
 */
{
    struct hostent* hp;

    bzero( ( void* )addrp, sizeof( struct sockaddr_in ) );
    hp = gethostbyname( hostname );
    if( hp == NULL ) return -1;

    bcopy( ( void* )hp->h_addr, ( void* )&addrp->sin_addr, hp->h_length );
    addrp->sin_port = htons( port );
    addrp->sin_family = AF_INET;
    return 0;
}

int make_dgram_server_socket( int portnum )
{
    struct sockaddr_in saddr;             // アドレス情報
           char        hostname[HOSTLEN]; // ホスト名
           int         sock_id;           // ソケットID

    sock_id = socket( PF_INET, SOCK_DGRAM, 0 ); // ソケットの作成
    if( sock_id == -1 ) return -1;              // エラー処理

    // アドレスを構築して、ソケットに割り当てる
    gethostname( hostname, HOSTLEN ); // ホスト名から FQDN を取得
    make_internet_address( hostname, portnum, &saddr );

    // 接続およびエラー処理
    if( bind( sock_id, ( struct sockaddr* )&saddr, sizeof( saddr ) ) != 0 ) return -1;

    return sock_id;
}

int make_dgram_client_socket()
{
    return socket( PF_INET, SOCK_DGRAM, 0 );
}

int get_internet_address( char* host, int len, int* portp, struct sockaddr_in* addrp )
/*
 * インターネットソケットアドレスからホスト名とポート番号を抜き出す
 * *addrp -> ( host, port )
*/
{
    strncpy( host, inet_ntoa( addrp->sin_addr ), len );
    *portp = ntohs( addrp->sin_port );
    return 0;
}
