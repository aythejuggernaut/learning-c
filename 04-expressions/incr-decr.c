#include <stdio.h>

int main(void) {
    // int i;
    // i = 1;

    // printf("i is %d\n", ++i);
    // printf("i is %d\n", i);
    // printf("i is %d\n", i++);
    // printf("i is %d\n", i);

    int i, j, k;
    i = 1;
    j = 2;
    k = i++ + j++;
    printf("i is %d\n", i);
    printf("j is %d\n", j);
    printf("k is %d\n", k);

    return 0;
}