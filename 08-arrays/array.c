#include <stdio.h>

#define N 10

int main(void) {
    int a[N];
    
    for (int i = 0; i < N; i++) {
        a[i] = i * i;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

