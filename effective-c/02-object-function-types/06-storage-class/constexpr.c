#include <stdio.h>

int main(void) {
    // constexpr (C23), this is new in C23.
    // constexpr means constant expressions.
    // can be applied to functions as well as objects in C23.
    // allows the compiler to evaluate expressions at compile time if the inputs are known at compile time.
    // it allows you to use the same function for both constant and runtime evaluation
    // it is a declaration specifier, similar to static, extern, register, etc.
    // it can be used with the following
    // 1. declarations of variables
    // 2. type specifiers
    // 3. function declarations
    // 4. declarations of anonymous struct/union members

    // constexpr int x = 10; // read-only variable, it exists in memory.
    // this means:
    // - value fixed at compile time
    // - cannot change
    // - memory cannot be allocated
    // - size must be known at compile time
    // - must be of integral type, enumerations, or reference type
    // - can be used in contexts where compile-time constants are required

    // constexpr -> compile-time constant. compiler knows its value while
    // translating the program.
    // Example:
    // constexpr int size = 100;
    // int array[size]; // valid because size is a compile-time constant 
    // compiler already knows size = 100 before the program runs.

    // Why can't static variables use ordinary variables as initializers?
    // int *func(int i) {
    //     const int j = i;
    //     static int k = j; // error
    // }
    // static variables are created before program starts, but j is create 
    // only when func runs. when the compiler initializes k, j doesn't exist yet. therefore, static int k = j; is impossible. 
    static int k = 5; // allowed because 5 is known during compilation.

    return 0;
}