#include <stdio.h>

int main(void) {
    // The break statement is particularly useful for writing loops in which 
    // the exit point is in the middle of the body rather than at the beginning or end

    int d, n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (d = 2; d < n; d++) {
        if (n % d == 0) {
            break;
        }
    }

    if (d >= n) {
        printf("%d is a prime number\n", n);
    } else {
        printf("%d is not a prime number\n", n);
    }

    return 0;
}

