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

    // Also, a small improvement: getchar() actually returns an int, not a
    // char, so it can represent the special value EOF (-1). A more idiomatic
    // version is:

    // int ch;
    // while ((ch = getchar()) != EOF) {
    //     printf("%c is %d\n", ch, ch);
    //     if (ch == '\n')
    //         break;
    // }

    // This correctly handles end-of-file as well as ordinary characters.

    return 0;
}

