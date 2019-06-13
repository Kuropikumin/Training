/*
 * comment
*/

#include <stdio.h>

int main(int argc, char** args) {

    char s[] = "hello";
    char* p  = "hello";
    int n[]  = {1, 2, 3};

    printf("s[] %d\n", sizeof(s));
    printf("*p  %d\n", sizeof(p));
    printf("n[] %d %d\n", sizeof(n), sizeof(n)/sizeof(n[0]));

    return 0;
}
