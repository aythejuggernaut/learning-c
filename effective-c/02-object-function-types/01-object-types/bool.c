#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaration (prototype)
// Why declare first?
// When the compiler reaches this line:

// it needs to know: Does arm_detonator exist? What type does it return? What arguments does it take?
// The prototype provides that information before the function is used.
// In larger programs -> Typically, you put declarations in a header file (.h) and definitions in a source file (.c).
bool arm_detonator(int);

void arm_missile(void) {
    // Identifiers that begin with an underscore and either an uppercase 
    // letter or another underscore are always reserved.
    // The keywords false and true are constants of type bool with a value of 0 
    // for false and 1 for true. If you are using an older version of C, you 
    // can include the header <stdbool.h>, still spell this type as bool, and 
    // assign it the values true and false.

    // bool is the proper type for values that are only true or false 
    // Internally, bool is an integer type (_Bool):
        // false is stored as 0.
        // true is stored as 1.
    // Any non-zero integer assigned to a bool is automatically converted to true. 
    //Although bool can participate in integer operations because of its integer representation, you should use it to express Boolean concepts. It makes your code clearer and ensures that all true values are normalized to the single value true.
    bool armed = arm_detonator(3);
    if (armed) puts("missile armed");
    else puts("missile disarmed");

    // Why does the linker complain instead of the compiler?
    // Building a C program has two main stages: 
        // Compilation (.c → .o) 
            // -> Checks syntax and types.
            // -> Sees the declaration and assumes the function exists.
        // Linking (.o → executable)
            // -> Connects all function calls to their implementations.
            // -> Fails if a referenced function or main() cannot be found.
    // That's why you see linker errors (ld: symbol(s) not found) rather than compiler errors
}

// Definition
bool arm_detonator(int level)
{
    return level >= 3;
}


int main(void)
{
    arm_missile();
    return 0;
}