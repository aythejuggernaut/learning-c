#include <stdio.h>

int main(void)
{
    // A pointer type is derived from a function or object type called the 
    // "referenced type". A pointer type derived from the referenced type T is 
    // called "pointer to T". A pointer provides a reference to an entity of 
    // the referenced type.
    int *ip = 0; // compliant
    char *cp = NULL; // good
    void *vp = nullptr; // better

    // NULL is implementation-defined based on the compiler, while nullptr
    // is a null pointer constant that is portable and type-safe.
    /*
    Definition	Type
    0	        int
    0L	        long
    (void *)0	void *
    */
    printf("%p\n", NULL);
    // Different types can produce different behavior and can lead to undefined behavior
    /*
    If NULL is 0, the compiler sees an int.

If NULL is

(void *)0

it sees a pointer.

These are different types.
    */

    // Example of NULL being used as an int
    int *ip1 = NULL;
    int *ip2 = 0;
    int *ip3 = (void *)0;
    int *ip4 = nullptr;

    // Example of NULL being used as a pointer
    char *cp1 = NULL;
    char *cp2 = 0;
    char *cp3 = (void *)0;
    char *cp4 = nullptr;

    // Variadic functions problem
    // Variadic functions accept a variable number of arguments.
    // printf(...) or execl(...)
    // If you pass NULL to these functions, the compiler
    // may not know what type of pointer it is, leading to undefined behavior.
    // In C11, you can use _Generic to determine the type of NULL.

    // suppose NULL is 0. On a 64-bit machine int = 4 bytes pointer = 8 bytes
    // passing NULL actually passes a 4-byte integer. But the function expects 
    // an 8-byte pointer. That mismatch can cause incorrect behavior because 
    // variadic functions do not automatically know the types of the extra 
    // arguments. Using nullptr avoids this ambiguity.

    // printf("sizeof(int) = %zu\n", sizeof(int));
    // printf("sizeof(void*) = %zu\n", sizeof(void *));
    // printf("sizeof(NULL) = %zu\n", sizeof(NULL));

    // The address-of operator (&) and the dereference operator (*)
    // The & operator yields the address of an object or function. The * 
    // operator yields the value of an object or function.
    int i = 10;
    int *ip = &i;
    printf("The address of i is %p\n", &i);
    printf("The value of *ip is %d\n", *ip);

    // Why does this work? ip = &*ip;
    //
    // &*ip means take the address of the value of ip.
    // Since ip is a pointer to i, the value of ip is the address of i.
    // So &*ip is the address of the address of i.
    // The & operator has higher precedence than the * operator, but & is a 
    // unary operator that takes an operand of type T * and produces an 
    // operand of type T ** , while * is a unary operator that takes an operand 
    // of type T ** and produces an operand of type T *
    int i = 10;
    int *ip = &i;
    int **ipp = &ip;
    printf("The address of i is %p\n", &i);
    printf("The value of *ip is %d\n", *ip);
    printf("The address of ip is %p\n", &ip);
    printf("The value of **ipp is %d\n", **ipp);

    ip = &*ip;
    // ip = 10000
    // *ip means the object at address 1000 which is i
    // &(*ip) means the address of i which is 1000
    // So ip = &*ip; means ip = 10000 which is the same as before
    // so *ip -> i     &i -> 1000
    // result: &*ip == ip 
    // The operation cancels each other out
    /*
        Pointer
            |
            v
        1000

        *  ---> object
        &  ---> address again
    */

    // what does * actually mean ?
    int x = 50;
    int *p = &x;
    // then *p has type int because it gives you the object being pointed to.
    *p = 99;
    // changes x to 99

    // What if the pointer is invalid?
    int *p = NULL;
    printf("%d", *p);
    // or
    int *p;
    printf("%d", *p);
    // Both are undefined behavior because * tries to access memory that isn't 
    // a valid object. A pointer must point to a valid object (or function, when using function pointers) before you dereference it.


    // Summary
    // A pointer stores a memory address.
    // A null pointer stores "no valid address."
    // 0, NULL, and nullptr (C23) can represent a null pointer, but nullptr is the safest and clearest because it has a dedicated null-pointer type.
    // & means "give me the address of this object."
    // * means "follow this pointer to access the object."
    // &*p is equivalent to p (for a valid pointer), because dereferencing and then taking the address gets you back to the original pointer.
    // Dereferencing (*p) a null, uninitialized, or otherwise invalid pointer results in undefined behavior.

    return 0;
}