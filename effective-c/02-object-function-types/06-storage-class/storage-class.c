#include <stdio.h>

int main(void) {
    // a storage-class specifier tells the compiler additional information 
    // about an identifier, such as:
    // - how long it lives (storage duration)
    // - who can see it (linkage)
    // - whether it is a compile-time constant
    // - whether it's a type alias

    // every variable has several independent properties. for example:
    int x = 10;
    // the compiler knows:
    // - the type is int
    // - scope -> depends on where it's declared
    // - storage duration -> automatic or static
    // - linkage -> internal or external or none
    // - value -> 10
    // - it is not a type alias
    // - it is not a compile-time constant
    // this information doesn't all come from the type declaration, 
    // some of it comes from keywords and context. a storage-class specifier 
    // changes one or more of these properties.

    // modern C (C23) has: 
    // auto, static, extern, thread_local, register, typedef, constexpr
    // each has a different purpose.

    // Summary
    // SPECIFIER ==> Static
    // MAIN PURPOSE => Gives static storage duration to local variables; gives internal linkage to file-scope objects/functions
    // EXAMPLE ==> static int counter;

    // SPECIFIER ==> extern	
    // MAIN PURPOSE => Refers to an object or function defined elsewhere; typically provides external linkage	
    // EXAMPLE ==> extern int counter;

    // SPECIFIER ==> thread_local	
    // MAIN PURPOSE => One instance of the object per thread	
    // EXAMPLE ==> thread_local int id;

    // SPECIFIER ==> constexpr (C23)
    // MAIN PURPOSE => Compile-time constant value	
    // EXAMPLE ==> constexpr int SIZE = 100;

    // SPECIFIER ==> register
    // MAIN PURPOSE => Historical hint to keep a variable in a CPU register; cannot take its address	
    // EXAMPLE ==> register int i;

    // SPECIFIER ==> typedef
    // MAIN PURPOSE => Creates a type alias	
    // EXAMPLE ==> typedef unsigned long ulong;

    // SPECIFIER ==> auto (C23)
    // MAIN PURPOSE => Infers the variable's type from its initializer	
    // EXAMPLE ==> auto x = 5;

    // The most important one in practice
    // For most C programmers, you'll encounter these far more often than the others:
    // static — Changes a local variable's lifetime or makes a file-scope name private to its source file. 
    // extern — Declares that a variable or function is defined in another translation unit.
    // typedef — Creates a more convenient or descriptive name for an existing type.

    // The remaining specifiers (thread_local, constexpr, register, and the new C23 meaning of auto) are either specialized, newer language features, or largely obsolete in modern code.
}