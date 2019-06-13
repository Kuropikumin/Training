/*
 * comment
*/

#include <stdio.h>

int main(int argc, char** args) {
    int val, mask = 0x03;
    val = 0xdeadbeef;

    printf("val: %x, mask: %x\n\n", val, mask);
    printf("%x\n", val & mask);
    printf("%x\n", val & ~mask);

    return 0;
}
