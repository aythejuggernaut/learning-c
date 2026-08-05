#include <stdio.h>

int main(void) {
    // extern has the opposite effect of static. it makes a variable
    // visible to other files. it means "this object exists somewhere else."
    // File 1:
    int counter = 0;
    
    // File 2:
    // extern int counter;
    // void f(void) {
    //     counter++;
    // }
    // now we can access counter from file 1. the compiler knows:
    // don't create another counter here; instead, use the one from file 1.
    // This is how we share variables between files. It gives them global 
    // linkage.
    
    // Note: extern can also be used inside a file to refer to something
    // defined in the same file but later, or in another file
    // declaring a function is also an extern declaration by default.
    // void f(void);
    // is the same as:
    // extern void f(void);
    // This means f exists elsewhere.
    // If we want internal linkage (only visible in this file), we say static.
    
    // If we want to force internal linkage for a function defined in the same
    // file, we say:
    // static void f(void) { ... }
    
    // Functions have external linkage by default.
    // Global variables have external linkage by default.
    // Static functions have internal linkage.
    // Static global variables have internal linkage.
    // Typedefs and enums always have internal linkage.
    
    // The main function must have external linkage.
    // main is the entry point. The system loader needs to find it.

    return 0;
}