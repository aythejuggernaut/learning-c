#include <stdio.h>

int main(void)
{
    // A statement can be null-devoid of symbols except for the semicolon at 
    // the end. The null statement is primarily good for one thing: writing
    // loops whose bodies are empty.
    // C programmers customarily put the null statement on a line by itself. 
    // Otherwise, someone reading the program might get confused about whether
    // the statement after the for was actually its body:
    int n = 10, d;
    for (int d = 2; d < n && n % d != 0; d++);
    if (d < n)
        printf("%d is divisible by %d\n", n, d);

    // Q: Are there any other ways to make an empty loop body stand out besides
    // putting the null statement on a line by itself?
    // Some programmers use a dummy continue statement:
    for (int d = 2; d < n && n % d != 0; d++)
        continue;
    // Others use an empty compound statement:
    for (int d = 2; d < n && n % d != 0; d++)
        {}

}