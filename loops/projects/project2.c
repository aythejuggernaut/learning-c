#include <stdio.h>

int main(void) {
    int m, n, remainder;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    
    if (m < 0 && n < 0) {
        printf("Please enter positive integers.");
        return 0;
    }

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    
    printf("Greatest common divisor: %d\n", m);

    return 0;
}
// In simple steps:
// 1. Start with two numbers m and n
// 2. Compute the remainder of m ÷ n
// 3. Shift values:
//    old n becomes new m
//    remainder becomes new n
// 4. Repeat
// 5. Stop when n == 0
// 6. The answer is m

// Why this works (intuition)
// Each step keeps the set of common divisors unchanged, but reduces the numbers, so you get closer and closer to the answer without listing factors.
// Quick check with your idea (12, 28)
// (28, 12)
// remainder = 4 → (12, 4)
// remainder = 0 → (4, 0)
// stop → answer = 4

