#include <stdio.h>

int main(void) {
    // A for statement that counts up or down a total of n times will usually
    // have one of the following forms:
    // 1. Counting up from 0 to n-1:
    // for (i = 0 ; i < n ; i++) ...
    
    // 2. Counting up from 1 to n:
    // for (1 = 1; i <= n ; i++) ...
    
    // 3. Counting down from n-1 to 0:
    // for ( i = n - 1 ; i >= 0 ; i--) ...
    
    // 4. Counting down from n to 1:
    // for (i = n ; i > 0 ; i--) ...

    for (int i = 10; i > 0; i--) 
        printf("T minus %d and counting...\n", i);
    
    printf("Blast off!\n");

    // Omitting Expressions in a for statement
    // If the first expression is omitted, no initialization is performed
    // before the loop is executed:
    int i = 10;
    for (; i > 0; --i)
        printf("T minus %d and counting...\n", i);
    
    printf("Blast off!\n");

    // If we omit the third expression in a f o r statement, the loop body is
    // responsible for ensuring that the value of the second expression
    // eventually becomes false.
    for (i = 10; i > 0; )
        printf("T minus %d and counting...\n", i--);
    
    printf("Blast off!\n");

    // When the first and third expressions are both omitted, the resulting 
    // loop is nothing more than a while statement in disguise

    for (; i > 0;)
        printf("T minus %d and counting...\n", i--);
    
    printf("Blast off!\n");

    // is the same as
    while (i > 0) {
        printf("T minus %d and counting...\n", i--);
    }
    printf("Blast off!\n");

    // The while version is clearer and therefore preferable.
    // If the second expression is missing, it defaults to a true value, so the
    // for statement doesn't terminate (unless stopped in some other fashion).
    // For example, some programmers use the following f o r statement to establish an infinite loop:
    
    // for (;;)
    //     printf("This loop runs forever.");

    // Incidentally, a for statement may declare more than one variable,
    // provided that all variables have the same type:
    // for (int i = 0 , j = 0; i < n ; i++)

    // Comma operator: a way to evaluate two expressions in place of a single
    // expression. It causes both expressions to be evaluated, but only the
    // value of the second expression is used as the value of the
    // comma-separated expression.
    // for (int i = 0, j = 0; i < 10; i++, j++) {
    //     printf("i = %d, j = %d\n", i, j);
    // }

    // For example, suppose that we want to initialize two variables when
    // entering a for statement. Instead of writing

    // int sum = 0;
    // for (int i = 1; i <= N; i++)
    //     sum += i;
    
    // we can write
    // for (int sum = 0, i = 1; i <= N; i++) {
    //     sum += i;
    // }

    return 0;
}

