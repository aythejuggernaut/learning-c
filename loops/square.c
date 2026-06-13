#include <stdio.h>

int main(void) {
    int num, i;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &num);

    i = 1;

    while (i <= num) {
        printf("%10d%10d\n", i, i * i);
        i++;
    }
    
    return 0;
}

