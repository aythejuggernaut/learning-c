#include <stdio.h>

int main(void) {
    int i, j;
    float x, y;

    printf("Enter two integers and two floating-point numbers: ");
    scanf("%d%d%f%f", &i, &j, &x, &y);
    printf("i = %d, j = %d, x = %f, y = %f\n", i, j, x, y);

    return 0;
}