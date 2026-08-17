#include <stdio.h>

int *max (int *a, int *b);

int main(void) {
    // we can not only pass pointers to functions but also write functions that 
    // return pointers.
    int *p, i, j;
    p = max(&i, &j);

    // although the max function returns one of the pointers passed to it as an
    // argument, that's not the only possibility. a function could also a 
    // return a pointer to an external variable or a local variable that's been 
    // declared static.

    // never return a pointer to an automatic local variable:
    // int *f(void) {
    //     int i;
    //     return &i; // dangling pointer
    // }

    // the variable i doesn't exist once f return, so the pointer to it will be 
    // invalid. some compilers issue a warning such as "function returns 
    // address of local variable" in this situation.
    // any pointer, including the address of a variable, can be displayed by 
    // calling the printf function and using i p as the conversion specification

    // void f (const int *p){
        // int j;
        // *p = 0; /* WRONG - you cannot change the value of a const int */
        // p = &j; /* OKAY - you can change the pointer */
    // }
    // the const tells the compiler that the function will not change the
    // value of the variable pointed to by p. it says that f can't change the 
    // integer that p points to, it doesn't prevent f from changing p itself.
    // since arguments are passed by value, assigning p a new value - by making 
    // it point somewhere else - won't have any effect outside the function.


    // Q: When declaring a parameter of a pointer type, is it legal to put the word const in front of the parameter's name, as in the following example?
    // void f(int *const p)
    // A: Yes, although the effect isn't the same as if const precedes p's type. putting const before p's type protects the object that p points to. 
    // putting const after p's type protects p itself:
    // void f(int *const p) {
    //     *p = 0;  /* OKAY - you can change the object */
    //     p = &j; /* WRONG - you can't change where p points */
    // }

    // this feature isn't used very often. Since p is merely a copy of another 
    // pointer (the argument when the function is called), there's rarely any 
    // reason to protect it. an even greater rarity is the need to protect both 
    // p and the object it points to, which can be done by putting const both before and after p's type:

    // void f(const int *const p) {
    //     *p = 0;  /* WRONG - you can't change the object */
    //     p = &j; /* WRONG - you can't change where p points */
    // }
}

int *max(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}
