#include <stdio.h>

int main(void) {
    // the typedef storage-class specifier defines an identifier to be a typedef
    // name that denotes the type specified for the identifier.
    // the typedef storage class specifier is most often used with structures and
    // unions.
    typedef struct {
        int a;
        int b;
    } Point;
    // now, Point is a type, and we can use it like any other type.
    Point p;
    p.a = 1;
    p.b = 2;
    printf("%d %d\n", p.a, p.b);

    //Typedef can be used to make the code more readable.
    //For example:
    typedef int *IntPtr;
    IntPtr ptr;
    ptr = &p.a;
    printf("%d\n", *ptr);

    // Typedef can be used to create aliases for types.
    // For example:
    typedef unsigned int uint;
    uint x = 10;
    printf("%u\n", x);

    //Typedef is not a storage-class specifier. it is a type specifier.
    //Typedef does not allocate memory. it just gives a name to a type.
    //Typedef doesn't create storage.
    typedef unsigned long ulong;
    ulong y = 10; // means unsigned long y = 10;
    
    
    return 0;
}