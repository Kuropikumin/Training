/*
 * comment
*/

#include <stdio.h>

char* sub(void) {
    char s[] = "test";

    printf("sub function: %s\n", s);
    return s;
}

int main(int argc, char** args) {

    printf("main function: %s\n", sub());
    return 0;
}
