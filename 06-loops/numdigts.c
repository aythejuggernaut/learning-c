#include <stdio.h>

int main(void) {
    int n, digits = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);
    
    do {
        n /= 10;
        digits++;
    } while (n != 0);
    
    printf("The number has %d digit(s).\n", digits);
    
    return 0;
}

