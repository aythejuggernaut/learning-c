#include <stdio.h>

int main(void)
{
    // Derived types are constructed from other types. These include function 
    // types, pointer types, array types, type definitions, structure types, and
    // union types.
    // A function type is derived from the return type and the number and types 
    // of its parameter. A function can return any complete object type (int, 
    // char, float, double, struct, union, enum, pointer) except for an array 
    // type or a function type.

    // int add(int a, int b); -> (int, int) -> int
    // double square(double x); -> (double) -> double
    // void swap(int *a, int *b); -> (int *, int *) -> void

    // A function type can't have an array type as its return type, but it can
    // return a pointer to an array type, or an array of pointers to function
    // types, or a function type that returns an array of a type. 

    // int getNumbers()[10];   // ❌ Invalid
    // Arrays in C cannot be copied or returned directly. Instead, you return a pointer.
    // int (*getNumbers())[10]; // ✅ Correct
    // getNumbers is a function that returns a pointer to an array of 10 
    // integers. Without them, the meaning changes.

    // int add(int, int);
    // int (*chooseFunction(void))(int, int);
    //chooseFunction is a function that returns a pointer to a function that
    // returns an int and takes two ints as parameters.

    // int (*func())[5];
    // func is a function that returns a pointer to an array of 5 integers.
    // A function cannot be a parameter to a function, but an array can be a 
    // parameter to a function.
    // void processArray(int arr[10]);
    // void processArray(int arr[]);
    // void processArray(int *arr);
}