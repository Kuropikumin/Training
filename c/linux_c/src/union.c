/*
 * union test
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>

union sample_un {
    unsigned char reg;
    struct bits {
        unsigned char bit0:1;
        unsigned char bit1:1;
        unsigned char bit2:1;
        unsigned char bit3:1;
        unsigned char bit4:1;
        unsigned char bit5:1;
        unsigned char bit6:1;
        unsigned char bit7:1;
    } regbit;
};

int main(int argc, char** args) {
    union sample_un data;

    memset(&data, 0, sizeof(data));

    printf("sizeof        %d\n", sizeof(data));
    printf("offset reg    %d\n", offsetof(union sample_un, reg));
    printf("offset regbit %d\n", offsetof(union sample_un, regbit));

    data.reg = 0xc8;
    printf("0x%02x = %d%d%d%d%d%d%d%d\n",
            data.reg,
            data.regbit.bit7,
            data.regbit.bit6,
            data.regbit.bit5,
            data.regbit.bit4,
            data.regbit.bit3,
            data.regbit.bit2,
            data.regbit.bit1,
            data.regbit.bit0);

    return 0;
}
