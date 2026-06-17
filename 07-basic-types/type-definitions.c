#include <stdio.h>

int main(void){
    // typedef is a keyword that allows you to create a new type name. 
    // It is often used to create a more meaningful name for a type.
    // The structure is as follows: typedef unsigned long int ulong;

    // So instead of typing "unsigned long int", you can just type "ulong".
    // This is especially useful for types that are used frequently or are long.
    typedef unsigned long int ulong;
    ulong i = 1000;

    typedef int Bool;
    // Using typedef to define Bool causes the compiler to add Bool to the list
    // of type names that it recognizes. Bool can now be used in the same way 
    // as the built-in type names in variable declarations, cast expressions, 
    // and elsewhere. Although int might be more readable, it's good to 
    // know that you can create your own type names. However, don't overdo 
    // it; the primary purpose of typedef is to simplify the handling of 
    // complicated declarations.

    // The compiler treats Bool as a synonym for int; thus, flag is really
    // nothing more than an ordinary int variable. The compiler doesn't treat
    // typedef any differently than it would the original type names, 
    Bool flag; /* same as the int flag; */
    
    return 0;
}
