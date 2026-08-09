// If a parameter is a multidimensional array, only the length of the first 
// dimension may be omitted when the parameter is declared. For example, if we 
// revise the sum_array function so that a is a two-dimensional array, we must 
// specify the number of columns in a, although we don't have to indicate the number of rows:
#define LEN 10

int sum_two_dimensional_array(int a[][LEN], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < LEN; j++) {
            sum += a[i][j];
        }
    }

    return sum;
}