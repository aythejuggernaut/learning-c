#include <stdio.h>

int sum_array(int a[], int n) {

}

int main(void)
{
    // int numbers[] = {10, 20, 30, 40, 50};
    // total = sum_array(numbers, 5)

    // The only problem with this arrangement is that b must be declared as a 
    // variable and then initialized prior to the call. If b isn't needed for 
    // any other purpose, it can be mildly annoying to create it solely for the 
    // purpose of calling sum_array. 
    // In C99, we can avoid this annoyance by using a compound literal: an 
    // unnamed array that's created "on the fly" by simply specifying which 
    // elements it contains. The following call of sum_array has a compound 
    // literal (shown in bold) as its first argument:
    int total = sum_array((int[]){10, 20, 30, 40, 50}, 5);

    // In general, a compound literal consists of a type name within 
    // parentheses, fol-lowed by a set of values enclosed by braces.
    // A compound literal resembles a cast applied to an initializer. In fact,
    // compound literals and initializers obey the same rules. A compound 
    // literal may contain designators, just like a designated initializer, 
    // and it may fail to provide full initialization (in which case any 
    // uninitialized elements default to zero).

    // Compound literals created inside a function may contain arbitrary 
    // expressions, not just constants. For example, we could write
    // total = sum_array((int[]){2 * i, i + j, j * k}, 3);
    // where i, j, and k are variables. This aspect of compound literals 
    // greatly enhances their usefulness. A compound literal is an Ivalue, so 
    // the values of its elements can be changed. If desired, a compound 
    // literal can be made "read-only" by adding the word const to its type:
    // total = sum_array((const int []){5, 4}, 5);
    
}