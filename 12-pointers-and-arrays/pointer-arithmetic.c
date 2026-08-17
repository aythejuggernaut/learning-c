#include <stdio.h>

int main(void) {
    // int a[10], *p;
    // we can make p point to a[0] by writing
    // p = &a[0];
    // we can now access a[0] through p, for example, we can store value 5 in
    // a[0] by writing
    // *p = 5;
    // by performing pointer arithmetic (or address arithmetic) on p, we can 
    // access the other elements of a.

    // C supports three (and only three) forms of pointer arithmetic:
    // - adding an integer to a pointer
    // - subtracting an integer from a pointer
    // - subtracting one pointer from another

    int a[10], *p, *q, i;
    // 1. Adding an Integer to a Pointer
    // adding an integer j to a pointer p yields a pointer to the element that 
    // j places after the one that p points to. more precisely, if p points to 
    // the array element a[i], then p + j points to a[i + j] (provided, of 
    // course, that a[i + j] exists).

    p = &a[1];
    //        ┌────┐
    //      p │    │
    //        └────┘
    //          │
    //  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐
    //  │    ││    ││    ││    ││    ││    ││    ││    │ 
    //  └────┘└────┘└────┘└────┘└────┘└────┘└────┘└────┘     
    //    0     1     2     3      4     5     6     7 

    q = p + 3;

    //        ┌────┐            ┌────┐
    //      p │    │          q │    │
    //        └────┘            └────┘
    //          │                 │
    //  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐
    //  │    ││    ││    ││    ││    ││    ││    ││    │ 
    //  └────┘└────┘└────┘└────┘└────┘└────┘└────┘└────┘     
    //    0     1     2     3      4     5     6     7 
    
    p += 6;
    //                          ┌────┐            ┌────┐
    //                        q │    │          p │    │
    //                          └────┘            └────┘
    //                            │                 │
    //  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐
    //  │    ││    ││    ││    ││    ││    ││    ││    │ 
    //  └────┘└────┘└────┘└────┘└────┘└────┘└────┘└────┘     
    //    0     1     2     3      4     5     6     7 

    // 2. Subtracting an Integer from a Pointer
    // if p points to the array elements a[i], then p - j points to a[i - j];
    p = &a[7];
    //                                            ┌────┐
    //                                          p │    │
    //                                            └────┘
    //                                              │
    //  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐
    //  │    ││    ││    ││    ││    ││    ││    ││    │ 
    //  └────┘└────┘└────┘└────┘└────┘└────┘└────┘└────┘     
    //    0     1     2     3      4     5     6     7 

    q = p - 3;
    //                          ┌────┐            ┌────┐
    //                        q │    │          p │    │
    //                          └────┘            └────┘
    //                            │                 │
    //  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐
    //  │    ││    ││    ││    ││    ││    ││    ││    │ 
    //  └────┘└────┘└────┘└────┘└────┘└────┘└────┘└────┘     
    //    0     1     2     3      4     5     6     7 

    p -= 6;

    //        ┌────┐            ┌────┐
    //      p │    │          q │    │
    //        └────┘            └────┘
    //          │                 │
    //  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐
    //  │    ││    ││    ││    ││    ││    ││    ││    │ 
    //  └────┘└────┘└────┘└────┘└────┘└────┘└────┘└────┘     
    //    0     1     2     3      4     5     6     7 

    // 3. Subtracting one pointer from another
    // when one pointer is subtracted from another, the result is the distance 
    // (measured in array element) between the pointers. thus, if p points to 
    // a[i] and q points to a[j], then p - q is equal to i - j.
    p = &a[5];
    q = &a[1];
    
    //        ┌────┐            ┌────┐
    //      q │    │          p │    │
    //        └────┘            └────┘
    //          │                 │
    //  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐
    //  │    ││    ││    ││    ││    ││    ││    ││    │ 
    //  └────┘└────┘└────┘└────┘└────┘└────┘└────┘└────┘     
    //    0     1     2     3      4     5     6     7 

    i = p - q; /* i is 4  */
    i = q - p; /* i is -4 */

    // performing arithemtic on a pointer that doesn't point to an array 
    // element causes undefined behavior. futhermore, the effect of 
    // substracting one pointer from another is undefined unless both point to 
    // elements of the same array.

    // Comparing Pointers
    // we can compare pointers using the relational operators (<, <=, >, >=) 
    // and the equality operators (== and !=). using the relational operators 
    // to compare two pointers is meaningful only when both point to elements 
    // of the same array. the outcome of the comparison depends on the relative 
    // positions of the two elements in the array.
    p = &a[5];
    q = &a[1];
    // the value of p <= q is 0 and the value of p >= q is 1.

    // Pointers to Compound Literals
    // it's legal for a pointer to point to an element within an array created 
    // by a compound literal. a compound literal is a C99 feature that can be 
    // used to create an array with no name.
    int *j = (int []){3, 0, 3, 4, 1};
    // j points to the first element of a five-element array containing the 
    // integers 3, 0, 3, 4, 1.   
    j += 2;
    // now j points to the third element of the array (the one containing the 
    // integer 3). 
    printf("%d\n", *j);

    // using a compound literal saves us the trouble of first declaring an 
    // array variable and then making j point to the first element of that array:
    int c[] = {3, 0, 3, 4, 1};
    int *e = &c[0];

    // now e points to the first element of c
    e += 2;
    printf("%d\n", *e);

    return 0;
}

