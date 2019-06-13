/*
 * strict test
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct sample_st {
    char  c; //1byte
    int   n; //4byte
    void* p; //8byte
             // = 13byte
};

struct sample_st_packed {
    char  c; //1byte
    int   n; //4byte
    void* p; //8byte
             // = 13byte
} __attribute__ ((packed));

struct sample_st_nopad {
    char  c; //1byte
    unsigned char pad1[3]; //3byte;
    int   n; //4byte
    void* p; //8byte
             // = 16byte
};

int main(int argc, char** args) {
    struct sample_st        st;
    struct sample_st_packed st_p;
    struct sample_st_nopad  st_nop;

    memset(&st    , 0, sizeof(st));
    memset(&st_p  , 0, sizeof(st_p));
    memset(&st_nop, 0, sizeof(st_nop));

    printf("sizeof   %d\n", sizeof(st));
    printf("offset c %d\n", offsetof(struct sample_st, c));
    printf("offset n %d\n", offsetof(struct sample_st, n));
    printf("offset p %d\n", offsetof(struct sample_st, p));
    puts("------------------------------------");

    printf("sizeof   %d\n", sizeof(st));
    printf("offset c %d\n", offsetof(struct sample_st_packed, c));
    printf("offset n %d\n", offsetof(struct sample_st_packed, n));
    printf("offset p %d\n", offsetof(struct sample_st_packed, p));
    puts("------------------------------------");

    printf("sizeof   %d\n", sizeof(st));
    printf("offset c %d\n", offsetof(struct sample_st_nopad, c));
    printf("offset n %d\n", offsetof(struct sample_st_nopad, n));
    printf("offset p %d\n", offsetof(struct sample_st_nopad, p));
    puts("------------------------------------");

    return 0;
}
