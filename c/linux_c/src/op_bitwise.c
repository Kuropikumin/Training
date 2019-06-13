/*
 * bit wise
*/

#include <stdio.h>

int main(int argc, char** args) {
    int           num  = 0xf0f0f0f0;
    unsigned int  unum = 0xf0f0f0f0;
    unsigned char buf  = 0x8F;
    unsigned long val;

    printf("num: %x, unum: %x, buf: %c\n", num, unum, buf);

    printf("%0x %0x\n", num >> 1, unum >> 1);

    val = buf << 24;
    printf("%016lx\n", val);
    val = (unsigned long)buf << 24;

    printf("%016lx\n", val);

    return 0;
}
