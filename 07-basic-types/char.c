#include <stdio.h>

int main(void) {
    char ch;
    do {
        ch = getchar();
        // In C, characters are stored as ASCII values, which are integers.
        // When you print a char using %c, it prints the character.
        // When you print a char using %d, it prints the ASCII value.
        printf("%c is %d\n", ch, ch);
        // putchar(ch);
    }while(ch != '\n');

    return 0;
}

