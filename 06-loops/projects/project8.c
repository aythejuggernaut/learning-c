#include <stdio.h>

int main(void) {
    int days, start_day;

    printf("Enter number of days in month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sun, etc.): ");
    scanf("%d", &start_day);

    for (int i = 0; i < start_day; i++) {
        printf("    ");
    }

    for (int i = 1; i <= days; i++) {
        printf("%4d", i);
        if ((i + start_day - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}

