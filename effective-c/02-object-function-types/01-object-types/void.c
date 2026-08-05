#include <stdio.h>

int main(void)
{
    // The void type is a rather strange type. The keyword void (by itself) 
    // means "cannot hold any value." For example, you can use it to indicate 
    // that a function doesn't return a value or as the sole parameter of a 
    // function to indicate that it takes no arguments. On the other hand, 
    // the derived type void * means that the pointer can reference any object.

    // when used to specify the type of a pointer, it means "can point to 
    // anything." For example, the pointer void *p can point to an int, float, 
    // struct, or any other type of object.
    // For example, here is a function that accepts any kind of pointer and prints it as a string:
    // #include <stdio.h>
    // void printany(void *p)
    // {
    //     puts((char *) p);
    // }
    
    // In this function, the pointer parameter p has the type void *, so it can 
    // accept any kind of pointer. Inside the function, however, p is treated as 
    // a pointer to char. This works because any object can be viewed as a 
    // sequence of bytes, and a char * is a pointer to a byte. This is a common 
    // idiom in C: when you need to treat arbitrary data in a uniform way, 
    // cast it to (or use it as) a pointer to char.

    // The void type has several uses:
    // 1. As the return type of a function that does not return a value:
    // 2. As the return type of main:
    // 3. As the parameter type of a function that takes no arguments:
    // 4. To indicate that a pointer has no type:
    // void func(void);
    // void *ptr;

    // Array Type
    // │
    // ├── Array of a value type
    // │     ├── Array of a basic type
    // │     ├── Array of an enum type
    // │     ├── Array of a struct type
    // │     └── Array of a union type
    // │
    // ├── Array of a pointer type
    // ├── Array of a function type
    // └── Array of a void type
 
    // double arr1[5];
    // double *arr2[5];
    // double (*arr3[5])(void);
    // double arr4[5][5];
    
}