/*
 * pointer test2
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char** args) {
    char s[]   = "abc\0d";
    char d[32] = {0};

    printf("s = %s, d = %s\n", s, d);
    strcpy(d, s);
    printf("s = %s, d = %s(%x, %x, %x, %x, %x, %x)\n",
            s, d, d[0], d[1], d[2], d[3], d[4], d[5]);

    memset(d, 0, sizeof(d));
    memcpy(d, s, 6);
    printf("s = %s, d = %s(%x, %x, %x, %x, %x, %x)\n",
            s, d, d[0], d[1], d[2], d[3], d[4], d[5]);

    return 0;
}
