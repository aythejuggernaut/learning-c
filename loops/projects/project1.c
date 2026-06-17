#include <stdio.h>

int main(void) {
    float number;
    float largest_number = 0.0f;

    while (1) {
        printf("Enter a number: ");
        scanf("%f", &number);

        if (number <= 0) {
            printf("The largest number entered was %.2f\n", largest_number);
            break;
        }

        if (number > largest_number) {
            largest_number = number;
        }
    }   

    return 0;
}

