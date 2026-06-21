#include <stdio.h>
#include <stdbool.h> /* C99 only */

// This program uses the names book, true and false, which are defined 
// in C99's <stdbool.h> header. If your compiler doesn't support this header,
// you'll need to define these names yourself.

// #define true 1
// #define false 0
// typedef int bool;

int main(void) {

    bool digit_seen[10] = {false};
    int digit;
    // Notice that n has type long, allowing the user to enter numbers up to 
    // 2,147,483,647 (or more, on some machines).
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            break;
        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0)
        printf("Repeated digit\n");
    else
        printf("No repeated digit\n");

    return 0;
}

