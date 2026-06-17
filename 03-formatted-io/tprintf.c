#include <stdio.h>

int main(void) {
    int i;
    float x;

    i = 40;
    x = 839.21f;

    printf("|%d|%5d|%-5d|%5.2d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);

    printf("This is a test\a");  // Alert (bell)
    printf("This is a test\b");  // Backspace
    printf("This is a test\n");  // Newline
    printf("This is a test\t");  // Tab
    printf("This is a test\\n"); // Backslash
    printf("This is a test\"");  // Double quote
    printf("This is a test\'");  // Single quote
    printf("This is a test\?");  // Question mark
    printf("This is a test\r");  // Carriage return
    printf("This is a test\v");  // Vertical tab
    

    return 0;
}