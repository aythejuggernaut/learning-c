#include <stdio.h>

int main(void) {
    // it's often the case that relatively few elements of an array need to be 
    // initialized explicitly; the other elements can be given default values.
    int a[15] = {0, 0, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 48};
    // We want element 2 of the array to be 29, element 9 to be 7, and element 
    // 14 to be 48, but the other values are just zero. For a large array 
    // writing an initializer in this fashion is tedious and error-prone (what 
    // if there were 200 zeros between two of the nonzero values?).


    // C99's designated initializers can be used to solve this problem.
    // Each number in brackets is said to be a designator.
    int b[15] = { [2] = 29, [9] = 7, [14] = 48 };

    // Besides being shorter and easier to read (at least for some arrays), 
    // designated initializers have another advantage: the order in which the 
    // elements are listed no longer matters.
    int c[15] = { [14] = 48, [9] = 7, [2] = 29 };

    // Designators must be integer constant expressions. If the array being 
    // initialized has length n, each designator must be between 0 and n - 1. 
    // However, if the length of the array is omitted, a designator can be any
    // nonnegative integer. In the latter case, the compiler will deduce the
    // length of the array from the largest designator.
    int d[] = { [5] = 10, [23] = 13, [11] = 36, [15] = 29 };

    // An initializer may use both the older (element-by-element) technique and
    // the newer (designated) technique:
    // All elements for which no value is speci-fied will default to zero.
    int e[10] = {5, 1, 9, [4] = 3, 7, 2, [8] = 6 };

    return 0;
}