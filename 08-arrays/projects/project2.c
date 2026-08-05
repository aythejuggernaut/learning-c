#include <stdio.h>
#include <stdbool.h>

#define N 10

int main(void) {
    bool digit_seen[N] = {false};
    int digit, repeated_digit[N] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            repeated_digit[digit] += 1;
        } else {
            digit_seen[digit] = true;
            repeated_digit[digit] = 1;
        }
        n /= 10;
    }

    printf("Digits:      ");
    for (int i = 0; i < N; i++) {
        printf("%d  ", i);
    }
    
    printf("\nOccurences:  ");
    for (int i = 0; i < N; i++) {
        printf("%d  ", repeated_digit[i]); 
    }
    printf("\n");

    return 0;
}
