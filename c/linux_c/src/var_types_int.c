/*
 * bytes of data type
*/

#include <stdio.h>

int main(int argc, char** args) {
    char      c;
    short     s;
    int       i;
    long      l;
    long long ll;
    void      *pv;
    int       *pi;
    long      *pl;

    printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n", sizeof(c), sizeof(s), sizeof(i), sizeof(l), sizeof(ll));
    printf("void pointer: %d, int pointer: %d, long pointer: %d\n", sizeof(pv), sizeof(pi), sizeof(pl));
}
