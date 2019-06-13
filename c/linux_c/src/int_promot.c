/*
 * integral promotion
*/

#include <stdio.h>

int main(int argc, char** args) {
    char a;
    int  ix, iy;
    unsigned char c, d;

    a  = 0x80;
    ix = 0x81;
    iy = a + ix;
    printf("%0x + %0x = %0x\n\n", a, ix, iy);

    c = 0x7f;
    d = (~c)>>4;
    printf("%0x, %0x\n", c, d);

    ix = ~c;
    printf("ix = %0x\n", ix);

    ix >>= 4;
    printf("ix = %0x\n", ix);

    iy = ix & 0xff;
    printf("iy = %0x\n", iy);

    d = iy;
    printf("d = %0x\n", d);

    return 0;
}
