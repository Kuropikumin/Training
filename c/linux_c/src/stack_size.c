/*
 * stack size
*/

#include <stdio.h>

void sub2(void) {
    static char buf[1024];
}

void sub(void) {
    char buf[1024];
}

int main(int argc, char** args) {
    sub();
    sub2();

    return 0;
}
