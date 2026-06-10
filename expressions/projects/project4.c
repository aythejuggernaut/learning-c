#include <stdio.h>

int main(void) {
    int number;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);

    // printf("Using %%d: %d\n", number);
    // printf("Using %%o: %o\n", number);
    // printf("Using %%#o: %#o\n", number);

    printf("In octal, the number %d is %#o\n", number, number);

    return 0;
}

