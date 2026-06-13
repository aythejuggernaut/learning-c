#include <stdio.h>

int main(void) {
    int hour, minutes;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minutes);

    if (hour <= 12) printf("Equivalent 12-hour time: %d:%0.2d AM\n", hour, minutes);
    else
        printf("Equivalent 12-hour time: %d:%0.2d PM\n", hour - 12, minutes);
    return 0;
}

