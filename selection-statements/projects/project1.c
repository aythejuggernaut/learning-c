#include <stdio.h>

int main(void) {
    int number, digit;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number >= 0 && number < 9) {
        digit = 1;
    } else if (number <= 99) {
        digit = 2;
    } else if (number <= 999) {
        digit = 3;
    } else {
        digit = 4;
    }
    printf("The number %d has %d %s.\n", number, digit, digit == 1 ? "digit" : "digits");

    return 0;
}
