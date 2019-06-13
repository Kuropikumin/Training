/*
 * pointer test1
*/

#include <stdio.h>

int main(int argc, char** args) {
    char* s  = "ABCD";
    char a[] = "ABCD";

    printf("s=%s, a=%s\n", s, a);
    printf("sizeof s=%d, a=%d\n", sizeof(s), sizeof(a));

    a[0] = 'X';
    printf("s=%s, a=%s\n", s, a);

    s[0] = 'X';
    printf("s=%s, a=%s\n", s, a);

    return 0;
}
