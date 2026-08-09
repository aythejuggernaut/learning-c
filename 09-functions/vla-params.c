// C99 adds several new twists to array arguments. The first has to do with 
// variable-length arrays (VLAs), a feature of C99 that allows the length of an 
// array to be specified using a non-constant expression. Variable-length 
// arrays can also be parameters, as it turns out.


int sum_array(int a[], int n);
// As it stands now, there's no direct link between n and the length of the 
// array a. Although the function body treats n as a's length, the actual 
// length of the array could in fact be larger than n (or smaller, in which 
// case the function won't work correctly). 
// Using a variable-length array parameter, we can explicitly state that a's 
// length is n:

int sum_array2(int n, int a[n]);
// The value of the first parameter (n) specifies the length of the second 
// parameter (a). Note that the order of the parameters has been switched; 
// order is important when variable-length array parameters are used.

// The following version of sum_array is illegal:
int sum_array3(int a[n], int n);
// The declaration of n comes too late for it to be used as the size of the
// array. The compiler will issue an error message at i n t a [n], because it hasn't yet seen n.

// There are several ways to write the prototype for our new version of 
// sum_array. One possibility is to make it look exactly like the function definition:
int sum_array4(int n, int a[n]); /* Version 1 */
// Another possibility is to replace the array length by an asterisk (*):
int sum_array5(int n, int a[*]); /* Version 2a */
// The reason for using the * notation is that parameter names are optional in
// function declarations. If the name of the first parameter is omitted, it 
// wouldn't be possible to specify that the length of the array is n, but the * 
// provides a clue that the length of the array is related to parameters that come earlier in the list:
int sum_array6(int , int [*]); /* Version 2b */
// It's also legal to leave the brackets empty, as we normally do when 
// declaring an array parameter:
int sum_array7(int n, int a[]); /* Version 3a */
int sum_array8(int, int []); /* Version 3b */
// Leaving the brackets empty isn't a good choice, because it doesn't expose 
// the relationship between n and a.

// Variable-length array parameters with a single dimension have limited 
// usefulness. They make a function declaration or definition more descriptive 
// by stating the desired length of an array argument. However, no additional 
// error-checking is performed; it's still possible for an array argument to be 
// too long or too short.
// It turns out that variable-length array parameters are most useful for 
// multi-dimensional arrays.

// The value of n specifies the number of rows, while m specifies the 
// number of columns.
int sum_two_dimensional_array(int n, int m, int a[n][m]) {
    int i, j, sum = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}
// Prototypes for this function include the following:
int sum_two_dimensional_array(int n, int m, int a[n][m]);
int sum_two_dimensional_array(int n, int m, int a[*][*]);
int sum_two_dimensional_array(int n, int m, int a[][m]);
int sum_two_dimensional_array(int n, int m, int a[][*]);

// Unlike a one-dimensional array, a multi-dimensional array argument can't be
// fully "flattened" into a pointer to a single type. As a result, the 
// compiler needs more information to determine how to access elements in
// the array.
// To see why this is the case, recall that a two-dimensional array is an 
// array of arrays. For instance, a 3-by-4 array of integers is an array
// of three 4-element integer arrays.