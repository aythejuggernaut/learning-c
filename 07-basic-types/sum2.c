#include <stdio.h>

int main(void) {
    long n, sum = 0;

    // d, o, u, x

    printf("This program sums a series of integers. \n");
    printf("Enter integers (0 to terminate): ");
    
    scanf("%ld", &n);
    while (n != 0) {
        sum += n;
        scanf("%ld", &n);
        printf("Number added.  Enter next number (0 to terminate): ");
    }
    printf("The sum is %ld\n", sum);
   
    return 0;
}

