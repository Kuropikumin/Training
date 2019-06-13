/*
 * postfix check
*/

#include <stdio.h>

//              123456789ABCDEF
char g_str[] = "hello, world!";

int main(int argc, char** args) {

    char* cp = g_str;
    int*  ip = (int*)g_str;
    long* lp =(long*)g_str;

    printf("cp: %p, ip: %p, lp: %p\n", cp, ip, lp);
    printf("cp= %s, ip= %s, lp= %s\n", cp, ip, lp);
    puts("---------------------------");

    cp++;
    ip++;
    lp++;
    printf("cp: %p, ip: %p, lp: %p\n", cp, ip, lp);
    printf("cp= %s, ip= %s, lp= %s\n", cp, ip, lp);
    puts("---------------------------");

    cp--;
    ip--;
    lp--;
    printf("cp: %p, ip: %p, lp: %p\n", cp, ip, lp);
    printf("cp= %s, ip= %s, lp= %s\n", cp, ip, lp);

    return 0;
}
