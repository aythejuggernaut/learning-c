#include <stdio.h>

int main(void) {
    // prior to C23, the auto specifier was allowed only for objects declared 
    // at block scope (except function parameter lists). it indicates automatic 
    // storage duration and no linkage, which are the defaults for these kinds of declarations.
    // C23 introduced type inference into the C language by expanding the 
    // definition of the existing auto storage-class specifier. Prior to C23, 
    // declaring a variable in C requires the user to name a type. However, 
    // when the declaration includes an initializer, the type can be derived 
    // directly from the type of the expression used to initialize the variable.
    
    // The auto storage duration class specifier has similar behavior to C++ in 
    // that it allows the type to be inferred from the type of the assignment value.
    
    // __auto_type -> auto
    static __auto_type a = 3;
    __auto_type p = &a;
    // because the integer literal 3 has an implicit type of int, these 
    // declaration are interpreted as if they had been written as:
    static int a = 3;
    int *p = &a;
    // effectively, a is an int, and p is an int *. type inference is exteremely
    // useful when implementing or invoking type-generic macros.

    // Before C23
    auto int x; // meant "Automatic storage duration" but local variables 
    // already have automatic storage. so nobody wrote it.
    // C23 changed it. now
    auto y = 5;
    // compiler infers y is int. equivalent to:
    int y = 5;
}