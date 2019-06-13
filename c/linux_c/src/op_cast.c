/*
 * comment
*/

#include <stdio.h>

int main(int argc, char** args) {

    char* cp = NULL;
    int*  ip = NULL;
    void* vp = NULL;

    cp = ip;
    cp = (char*)ip;
    cp = vp;

    return 0;
}
