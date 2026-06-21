#include <stdio.h>

#define N 10

int main(void)
{
    // an array subscript may be any integer expression: 
    // a[i+j*10] = 0;
    // The expression can even have side effects:
    // i = 0;
    // while (i < 10) {
    //     a[i++] = 0;
    // }

    // Let's trace this code. After i is set to 0, the while statement 
    // checks whether i is less than N. If it is, 0 is assigned to a[0],
    // i is incremented, and the loop repeats.
    // Note that a[++i] wouldn't be right, because 0 would be assigned to a[1] 
    // during the first loop iteration.

    // Be careful when an array subscript has a side effect. For example, the 
    // following loop is supposed to copy the elements of the array b into 
    // the array a, but it may not work properly:
    // i = 0;
    // while (i < N) {
    //     a[i] = b[i++];
    // }
    // The expression a [ i ] = b [i++] accesses the value of i and also 
    // modifies i else-where in the expression, which  causes undefined 
    // behavior. Of course, we can easily avoid the problem by removing the
    // increment from the subscript:
    // for (i = 0; i < N; i++) {
    //     a[i] = b[i];
    // }
    // Note that if we had incremented i after the assignment,
    //      a[i++] = b[i];
    // there would have been no problem, since i would have been incremented
    // only after the subscript i had been evaluated.

}