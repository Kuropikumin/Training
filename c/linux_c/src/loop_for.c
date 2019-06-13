/*
  * for loop check
*/

#include <stdio.h>

int main(void) {
    int i = 100;
    printf("before loop: %d\n", i);

    for(int i = 0; i < 10; i++) {
        printf("%d ", i);
    }
    puts("");
    printf("after loop: %d\n", i);

    return 0;
}
