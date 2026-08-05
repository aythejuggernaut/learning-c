#include <stdio.h>
#include <stdbool.h>

int main(void) {

    bool digit_seen[10] = {false};
    bool repeated_seen[10] = {false};
    int repeated_digit[10];
    int digit, count = 0;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit] && !repeated_seen[digit]) {
            repeated_digit[count++] = digit;
            repeated_seen[digit] = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    if (count != 0) {
        printf("Repeated digit(s): ");
        for (int j = 0; j < count; j++) {
            printf("%d ", repeated_digit[j]);
        }
        printf("\n");
    } else
        printf("No repeated digit\n");

    return 0;
}




// #include <stdio.h>
// #include <stdbool.h>

// int main(void) {

//     bool digit_seen[10] = {false};
//     int repeated_digit[] = {0};
//     int digit;
//     long n;

//     printf("Enter a number: ");
//     scanf("%ld", &n);

//     int i = 0;
//     while (n > 0) {
//         digit = n % 10;
//         if (digit_seen[digit]) {
//             repeated_digit[i] = digit;
//             i++;
//         }
//         digit_seen[digit] = true;
//         n /= 10;
//     }

//     if (i != 0) {
//         printf("Repeated digit(s): ");
//         for (int j = 0; j < i; j++) {
//             printf("%d ", repeated_digit[j]);
//         }
//         printf("\n");
//     } else
//         printf("No repeated digit\n");

//     return 0;
// }

