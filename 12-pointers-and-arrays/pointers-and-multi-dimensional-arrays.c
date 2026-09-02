#include <stdio.h>

#define NUM_ROWS 10
#define NUM_COLS 10

int main(void)
{
    // C stores two-dimensional arrrays in row-major order; in other words, the 
    // elements of row 0 come first, followed by the elements of row 1, and so 
    // forth.
    // we can take advantage of this layouut when working with pointerrs. if we 
    // make a pointer p point to the first element in a two-dimensional array 
    // (the element in row 0, column 0), we can visit every element in the 
    // array by incrementing p repeatedly.

    int a[NUM_ROWS][NUM_COLS], row, col, i;

    // for (row = 0; row < NUM_ROWS; row++)
    //     for (col = 0; col < NUM_COLS; col++)
    //         a[row][col] = 0;

    // if we view a as a one-dimensional array of integers (which is how it's 
    // stored), we can replace the pair of loops by a single loop:
    int *p;
    for (p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++)
        *p = 0;

    // the loop begins with p pointing to a[0][0]. successivee increments of p 
    // make it point to a[0][1], a[0][2] ... and so on. when p reaches 
    // a[0][NUM_COLS -1] (the last element in row 0), incrementing it again 
    // makes p point to a[1][0] (the first element in row 1), and so forth. the 
    // process continue until p goes past a[NUM_ROWS - 1][NUM_COLS - 1], 
    // the last element in the array.

    // although treating a two-dimensional array as one-dimensional may seem 
    // like cheating, it works with most C compilers. Whether it's a good idea 
    // to do so is another matter. techniques like this one definitely hurt 
    // program readability, but at least with some older compilers produce a 
    // compensating increase in efficiency. With many modern compilers, though, 
    // there's often little or no speed advantage.

    // note that the expression &a[0][0] can be written simply as a.
    // the value of this expression is the same as &a[0][0], since a is an
    // abbreviation for &a[0]
    printf("%p\n", a);
    printf("%p\n", &a[0][0]);

    // Processing the Rows of a Multi-dimensional Array
    // what about processing the elements in just one row of a two-dimensional 
    // array? we have the option of using a pointer variable p. to visit the 
    // elements of row i, we'd initialize p to point to element 0 in row i in 
    // the array a:
    p = &a[i][0];
    // or, we could simply write
    p = a[i];

    // since, for any two-dimensional array a, the expression a [i] is a 
    // pointer to the first element in row i. To see why this works, recall the 
    // magic formula that relates array subscripting to pointer arithmetic: for 
    // any array a, the expression a[i] is equivalent to *(a + i). Thus,
    // &a[i][0] is the same as & (* (a[i] + 0)), which is equivalent to 
    // &*a[i], which is the same as a[i], since the & and * operators cancel. 
    // We'll use this simplification in the following loop, which clears row
    // i of the array a:
    for (p = a[i]; p < a[i] + NUM_COLS; p++)
        *p = 0;

    // since a[i] is a pointer to row i of the array a, we can pass a[i] to a 
    // function that's expecting a one-dimensional array as its argument. in 
    // other words, a function that's designed to work with one-dimensional 
    // arrays will also work with a row belonging to a two-dimensional array.
    // we can just as easily use find_largest to determine the largest element 
    // in row i of the two-dimensional array a:
    // largest = find_largest(a[i], NUM_COLS)

    // Processing the Columns of a Multidimensional Array
    int (*q)[NUM_COLS];

    for (int row = 0; row < NUM_ROWS; row++)
        a[row][i] = 0;

    for (q = &a[0]; q < &a[NUM_COLS]; q++)
        (*q)[i] = 0;
    // They are doing essentially the same thing.
    // normal version -> a[row][i]
    // pointer version -> (*p)[i]
    // in both cases: the row changes, i stays the same

    // What does &a[NUM_ROWS] mean?
    // p < &a[NUM_ROWS]
    // if there are 4 rows, a[4] doesn't contain a real rrow.
    // but C allows us to form a pointer to the position just after the last 
    // element. so &a[NUM_ROWS] means the adddress immediately after the last 
    // row. 

    // int a[NUM_ROWS][NUM_COLS], (*p)[NUM_COLS], i;
    // a -> 2D array ; p -> pointer to one row ; i - column number

    // for (p = &a[0]; p < &a[NUM_ROWS]; p++)
    //     (*p)[i] = 0;
    // start p at the first row -> go through each row -> 
    // for each row, access column i -> set that element to 0

    // i've declared p to be a pointer to an array of length NUM_ COLS whose 
    // elements are integers. The parentheses around *p in (*p) [NUM COLS] are 
    // required; without them, the compiler would treat p as an array of 
    // pointers instead of a pointer to an array. The expression p++ advances p 
    // to the beginning of the next row. In the expression (*p) [i], *p 
    // represents an entire row of a, so (*p) [i] selects the element in column 
    // i of that row. The parentheses in (*p) [ i ] are essential, because the compiler would interpret *p [il as * (p [i]).

    // Using the Name of a Multidimensional Array as a Pointer
    // just as the name of one-dimensional array can be used as a pointer, so 
    // can the name of any array, regardless of how many dimensions it has. 
    // some care is required, though.
    int d[NUM_ROWS][NUM_COLS];
    // d is not a pointer to a[0][0]; instead, it's a pointer to a[0]. this 
    // makes more sense if we look at it from the standpoint of C, which 
    // regards a not as a two-dimensional array but as a one-dimensional array 
    // whose element are one-dimensional arrays. when used as a pointer, a has 
    // type int (*)[NUM_COLS] (pointer to an integer array of length NUM_COLS).
    // knowing that a points a[0] is useful for simplifying loops that process 
    // the elements of a two-dimensional array. for example, instead of writing
    // for (p = &a[0]; p < &a[NUM_ROWS]; p++)
    //     (*p)[i] = 0;
    // to clear column i of the array a, we can write
    // for (p = a; p < a + NUM_ROWS; p++)
    //     (*p)[i] = 0;

    // another situation in which this knowledge comes in handy is when we want 
    // to "trick" a function into thinking that a multidimensional array is 
    // really one dimensional. For example, consider how we might use 
    // find_largest to find the largest element in a. As the first argument to 
    // find_largest, let's try passing a (the address of the array); as the second, we'll pass NUM_ROWS * NUM_COLS (the total number of elements in a):
    // largest = find_largest(a , NUM_ROWS * NUM_COLS); /* WRONG */
    // Unfortunately, the compiler will object to this statement, because the 
    // type of a is int (*) [NUM_COLS] but find_largest is expecting a argument 
    // of type int *. The correct call is
    // largest = find_largest(a[0], NUM_ROWS * NUM_COLS);
    // a[0] points to element 0 in row 0, and it has type int * (after 
    // conversion by the compiler), so the latter call will work correctly.

    return 0;
}
