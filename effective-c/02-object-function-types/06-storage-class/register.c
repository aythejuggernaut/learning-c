#include <stdio.h>

int main(void) {
    // register storage-class specifier suggest that access to an object be as 
    // fast as possible. the extent to which such suggestions are effective is 
    // implementation defined. frequently, compilers can make better decisions 
    // about register allocation and ignore these programmer suggestions.
    // the reister storage class can be used only for an object that never has 
    // its address taken.

    // A compiler can treat any register declaration simply as an auto 
    // declaration. However, whether addressable storage is used, the address 
    // of any part of an object declared with a storage-class specifier 
    // register cannot be computed, either explicitly by use of the unary & 
    // operator or implicitly by converting an array name to a pointer.

    // register is most historical. old CPUs had: Registers, RAM
    // register are much faster.
    register int i;
    // this means, please keep i in a CPU register.
    // modern compilers ignore this because they already know where to put 
    // variables. modern CPUs have many registers, and compilers are very 
    // good at register allocation.
    // if you need to use register, you should use it only for the most 
    // frequently accessed variables.
    // for example, a loop counter:
    for (register int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    // this is not a good example, because the compiler will anyway put i in a
    // register because it is used in a loop.

    // One important rule for register is that you cannot take the address of a
    // register variable. if you try to take the address of a register 
    // variable, you will get a compile-time error.
    &i; // this will not work because register don't necessarily have memory addresses.
    

    return 0;
}