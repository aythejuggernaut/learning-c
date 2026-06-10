#include <stdio.h>

int main(void) {
    float x, polynomial_value;
    printf("Enter value of x: ");
    scanf("%f", &x);

    polynomial_value = ((((3 * x + 2)*x - 5)*x - 1)* x + 7)* x - 6;
    printf("Polynomial result: %.2f\n", polynomial_value);
}