#include <stdio.h>

int main(void)
{
    int n, sum;

    n = sum = 0;

    while (n++ < 10) {
        sum += n;
    }

    printf("%d\n", sum);

    return 0;
}
