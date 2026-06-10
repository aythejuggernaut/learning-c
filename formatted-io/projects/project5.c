#include <stdio.h>

int main(void) {
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16;
    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15, &num16);

    printf("%2d %2d %2d %2d\n", num1, num2, num3, num4);
    printf("%2d %2d %2d %2d\n", num5, num6, num7, num8);
    printf("%2d %2d %2d %2d\n", num9, num10, num11, num12);
    printf("%2d %2d %2d %2d\n", num13, num14, num15, num16);

    printf("Row sums: %d %d %d %d\n", num1+num2+num3+num4, num5+num6+num7+num8, num9+num10+num11+num12, num13+num14+num15+num16);
    printf("Col sums: %d %d %d %d\n", num1+num5+num9+num13, num2+num6+num10+num14, num3+num7+num11+num15, num4+num8+num12+num16);
    printf("Diagonal sums: %d %d\n", num1+num6+num11+num16, num4+num7+num10+num13);
    
    return 0;
}
