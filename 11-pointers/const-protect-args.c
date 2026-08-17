#include <stdio.h>

int main(void)
{
    // when we call a function and pass it a pointer to a variable, we normally 
    // assume that the function will modify the variable (otherwise, why would 
    // the function require a pointer?). For example, if we see a statement like
    // f(&x);

    // in a program, we'd probably expect f to change the value of x. It i 
    // possible, though, that f merely needs to examine the value of x, not 
    // change it. the reason for the pointer might be efficiency: passing the 
    // value of a variable can waste time and space if the variable requires a 
    // large amount of storage.
    // we can use the word const to document that a function won't change an 
    // object whose address is passed function. const goes in the parameter's 
    // declaration, just before the specification of its type.

    // void f(const int *p)
    // {
    //    *p = 0; /* WRONG - p is declared as a pointer to a constant int, */
    //            /* so we cannot change the value of the object that p points to. */
    // }
}

