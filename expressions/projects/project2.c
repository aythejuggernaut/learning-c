#include <stdio.h>

int main(void) {
    int number, first_digit, second_digit, third_digit;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    // if n is an integer, then n % 10 is the last digit in n
    // and n / 10 is n with the last digit removed.
    first_digit = number / 100;
    third_digit = number % 10;
    second_digit = number % 10;
    printf("First digit: %d\n", first_digit);
    printf("Second digit: %d\n", second_digit);
    printf("The reversal of %d is %d\n", number, second_digit * 10 + first_digit);

    return 0;
}