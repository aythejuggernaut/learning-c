#include <stdio.h>

int main (void) {
    float x, raise_to_5, raise_to_4, raise_to_3, raise_to_2, polynomial_value;
    printf("Enter value of x: ");
    scanf("%f", &x);

    raise_to_2 = x * x;
    raise_to_3 = x * x * x;
    raise_to_4 = raise_to_2 * raise_to_2;
    raise_to_5 = raise_to_2 * raise_to_3;

    polynomial_value = (3 * raise_to_5) + (2 * raise_to_4) - (5 * raise_to_3) - (x * raise_to_2) + (7 * x)  - 6;
    printf("Polynomial Value: %.2f\n", polynomial_value);
}
    
