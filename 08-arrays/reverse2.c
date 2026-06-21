#include <stdio.h>

int main(void) {
    int i, n;

    printf("How many numbers do you want to reverse? ");
    scanf("%d", &n);

    // the array a in this program is an example of a variable-length array 
    // (or VLA for short). the length of a VLA is computed when the program 
    // is executed, not when the program is compiled. the chief advantage of a 
    // VLA is that the programmer doesn't have to pick an arbitrary length when
    // declaring an array; instead, the program itself can calculate exactly how
    // many elements are needed. if the programmer makes the chioce, it's lkely 
    // that the array will be too long (wasting memory) or too short (causing 
    // the program to fail). 
    int a[n]; /* C99 only - length of array depends on n */

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");
    for (i = n - 1; i >= 0 ; i--) 
        printf("  %d", a[i]);
    printf("\n");

    // the length of a VLA doesn't have to be specified by a single variable. 
    // Arbitrary expressions, possibly containing operators, are also legal.
    int b[3 * n + 5]; // legal, provided that 3*n + 5 is positive.
    // int c[j + k];

    // like other arrays, VLAs can be multidimensional:
    int d[n][n];
    // the primary restriction on VLAs is that they can't have static storage 
    // duration. another restriction is that the type of a VLA can't be 
    // used in the definition of a typedef name. another restriction is that
    // VLAs may not have an initializers.
    // VLAs are most often seen in functions other than main. One big advantage 
    // of a VLA that belongs to a function f is that it can have a different 
    // length each time f is called.

    return 0;
}

