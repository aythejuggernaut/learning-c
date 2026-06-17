#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, first_sum, second_sum, total, check_digit;

    printf("Enter first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12, &i13);

    first_sum = i2 + i4 + i6 + i8 + i10 + i12;
    second_sum = i1 + i3 + i5 + i7 + i9 + i11;
    total = ((3 * first_sum) + second_sum) - 1;
    check_digit = 9 - (total  % 10);

    if (i13 == check_digit)
        printf("VALID\n");
    else
        printf("NOT VALID\n");

    return 0;
}

