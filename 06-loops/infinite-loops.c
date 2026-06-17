#include <stdio.h>

int main(void) {
    int count = 0;

    // c programmers sometimes deliberately create an infinite
    // loop by using a nonzero constant as the controlling expression.

    // a while statement of this form will execute forever unless its body
    // contains a statement that transfers control out of the loop (return,
    // break, goto) or calls a function that causes the program to terminate
    // (exit, abort, etc.)

    while (1) {
        printf("This will print forever - I hope %d times!\n", count);
        count++;
        if (count > 1000) {
            break;
        }
    }

    return 0;
}

