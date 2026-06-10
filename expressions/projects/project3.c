#include <stdio.h>

int main(void) {
    int first_digit, second_digit, third_digit;
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &first_digit, &second_digit, &third_digit);

    printf("The reversal of %d%d%d is %d%d%d\n", first_digit, second_digit, third_digit, third_digit, second_digit, first_digit);

    return 0;
}

