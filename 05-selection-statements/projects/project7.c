#include <stdio.h>

int main(void){
    int num1, num2, num3, num4, min, max;
    
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    min = num1;
    max = num1;
    if (num2 > max) max = num2;
    if (num3 > max) max = num3;
    if (num4 > max) max = num4;

    if (num2 < min) min = num2;
    if (num3 < min) min = num3;
    if (num4 < min) min = num4;
    
    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
    
    return 0;
}

