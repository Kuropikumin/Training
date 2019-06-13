/*
 * pointer test3
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char** args) {
    int n = 0xdeadbeef;
    unsigned char s[4];

    memcpy(s, &n, 4);
    printf("%02x %02x %02x %02x\n", s[0], s[1], s[2], s[3]);

    return 0;
}
