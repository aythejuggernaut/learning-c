#include <stdio.h>

int main(void){
    // each inner initializer provides values for one row of the matrix.  
    // initializers for higher-dimensional arrays are constructed in a similar 
    // fashion.
    int m[5][9] = {
        {1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1},
    };

    // if an initializer isn't large enough to fill a multi-dimensional array, 
    // the remaining elements are given the value 0. for example, the following
    // initializer fills only the first three rows of m; the last two rows will
    // contain zeros:
    int nums[5][9] = {
        {1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1},
    };

    // if an inner list isn't long enough to fill a row, the remaining elements 
    // in the row are initialized to zero. (similarly, unused outer-dimension 
    // lists cause the remaining rows to be initialized to zero.)
    int other[5][9] = {
        {1, 1},
        {0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    // we can even omit the inner braces. once the compiler has seen enough 
    // values to fill one row, it begins filling the next.
    // omitting the inner braces in a multi-dimensional array initializer can 
    // be risky, since an extra element (or even worse, a missing element) will 
    // affect the rest of the initializers. leaving out the braces causes some 
    // compilers to produce a warning message such as "missing braces around initializer"
    int yetAnother[5][9] = {
        1, 1, 1, 1, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 0, 1, 1, 1, 1,
        1, 1, 1, 0, 1, 1, 1, 1, 1,
        1, 0, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1,
    };

    // If the first dimension is omitted, the compiler can deduce the 
    // number of rows from the number of initializers
    int matrix[][9] = {
        {1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    // c99's designated initializers work with multi-dimensional
    // arrays as well. the following example creates a matrix of
    // the same dimensions as the previous examples, but the order
    // of the initializer elements doesn't matter.
    double ident[2][2] = {
        [0][0] = 1.0,
        [1][1] = 1.0,
    };

    return 0;
}