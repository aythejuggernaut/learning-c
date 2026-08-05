#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 10

int main(void) {
    bool digit_seen[ARRAY_SIZE] = {false};
    bool repeated_digit[ARRAY_SIZE] = {false};
    int digit;
    long n;

    while (1) {
        printf("Enter a number: ");
        scanf("%ld", &n);

        if (n <= 0) break;

        digit = n % 10;

        if (digit_seen[digit]) {
            repeated_digit[digit] += 1;
        } else {
            digit_seen[digit] = true;
            repeated_digit[digit] = 1;
        }
        n /= 10;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", repeated_digit[i]);
     }
     printf("\n");

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (repeated_digit[i])
            printf("Digit %d seen %d times\n", i, repeated_digit[i]); 
    }

    return 0;
}

