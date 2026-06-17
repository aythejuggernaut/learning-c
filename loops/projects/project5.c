#include <stdio.h>

int main(void) {
    int number, original, reversed = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &number);

    original = number;
    do {
        digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }while (number != 0);

    printf("The reverse of %d is %d\n", original, reversed);

    return 0;
}

