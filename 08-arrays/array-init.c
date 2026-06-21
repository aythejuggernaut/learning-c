#include <stdio.h>

int main (void) {
    // An array, like any other variable, can be given an initial value at the 
    // time it's declared. The rules are somewhat tricky.

    // If the initializer is shorter than the array, the remaining elements of 
    // the array are given the value 0
    int a[10] = {1, 2, 3, 4, 5, 6}; /* initial value of a is {1, 2, 3, 4, 5, 6, 0, 0, 0, 0} */

    int b[10] = {0}; /* initial value of b is {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} */

    // It's illegal for an initializer to be completely empty, so we've put a 
    // single 0 inside the braces. It's also illegal for an initializer to be 
    // longer than the array it initializes. If an initializer is present, 
    // the length of the array may be omitted:

    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // The compiler uses the length of the initializer to determine how long 
    // the array is. The array still has a fixed number of elements (10, in 
    // this example), just as if we had specified the length explicitly.

    return 0;
}

