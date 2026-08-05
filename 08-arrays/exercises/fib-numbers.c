#include <stdio.h>

int main(void) {
    int fib_numbers[40] = {0, 1};

    int length = sizeof(fib_numbers) / sizeof(fib_numbers[0]);

    for (int i = 2; i <= length; i++) {
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
    }

    for (int i = 0; i < length; i++) {
        printf("%d ", fib_numbers[i]);
    }

    printf("\n");
    return 0;
}

