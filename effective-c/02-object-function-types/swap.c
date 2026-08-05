#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b) {
    // This would not change the original variables. That's because a and b inside the function are copies of the caller's variables.
    int t = a;
    a = b;

    b = t;
    printf("swap: a = %d, b = %d\n", a, b);
}

void swap_pointer(int *pa, int *pb) {
    // the function receives the addresses of the original variables, so *pa = ... and *pb = ... modify the actual a and b in the caller.
    // The important idea is that pa and pb themselves are local pointer 
    // variables (copies of the addresses), but they point to the caller's 
    // integers. Dereferencing them with * lets the function read and write those original integers directly.
    int t = *pa;
    *pa = *pb;

    *pb = t;
    printf("swap: a = %d, b = %d\n", *pa, *pb);
}


int main(void) {
    // Each object has a storage duration that determines its lifetime, which 
    // is the time during program execution for which the object exists, has 
    // storage, has a constant address, and retains its last-stored value. 
    // Objects must not be ref-erenced outside their lifetime.

    int a = 21;
    int b = 17;
    swap(a, b);
    printf("main: a = %d, b = %d\n", a, b);

    // C is a call-by-value (also called a pass-by-value) language, which means 
    // that when you provide an argument to a function, the value of that 
    // argument is copied into a distinct variable for use within the function. 
    // The swap function assigns the values of the objects you pass as 
    // arguments to their respective parameters. When the parameter values in 
    // the function are changed, the argument values in the caller are 
    // unaffected because they are distinct objects. Consequently, the 
    // variables a and b retain their original values in main during the second 
    // call to printf. The goal of the program was to swap the values of these 
    // two objects. By testing the program, we’ve discovered it has a bug, or defect.

    // To repair this bug, we can use pointers to rewrite the swap function. We 
    // use the indirection (*) operator to both declare pointers and dereference them,

    // The unary & (address-of) operator generates a pointer to its operand.
    swap_pointer(&a, &b);
    printf("main: a = %d, b = %d\n", a, b);
    // Within the swap function, the parameters pa and pb are now both declared 
    // as type pointer to int and contain copies of the arguments passed to 
    // swap from the calling function (in this case, main). These address 
    // copies still refer to the exact same objects, so when the values of 
    // their referenced objects are swapped in the swap function, the contents 
    // of the original objects declared in main are also swapped. This approach 
    // simulates call by reference (also known as pass by reference) by 
    // generating object addresses, passing those by value, and then 
    // dereferencing the copied addresses to access the original objects.

    return EXIT_SUCCESS;
}

// If you want a pointer to an integer:

// int value = 10;
// int *x = &value;

// If you want a null pointer (a pointer that points to nothing yet):

// int *x = NULL;

// This is safe because NULL is a special pointer value that means "no valid object." You should check it before dereferencing:

// if (x != NULL) {
//   printf("%d\n", *x);
// }