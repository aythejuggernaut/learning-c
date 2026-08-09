#include <stdio.h>

// Parameters appear in function definitions; they're dummy names that 
// represent values to be supplied when the function is called. Arguments 
// are expressions that appear in function calls.
// In C, arguments are passed by value: when a function is called, each 
// argument is evaluated and its value assigned to the corresponding 
// parameter. Since the parameter contains a copy of the argument's value, 
// any changes made to the parameter during the execution of the function 
// don't affect the argument. In effect, each parameter behaves like a 
// variable that's been initialized to the value of the matching argument. 
// The fact that arguments are passed by value has both advantages and 
// disadvantages. Since a parameter can be modified without affecting the 
// corresponding argument, we can use parameters as variables within the 
// function, thereby reducing the number of genuine variables needed. 
int power(int x, int n)
{
    int i, result = 1;
    for (i = 1; i < n; i++)
        result *= x;
    return result;
}

// Since n is a copy of the original exponent, we can modify it inside the 
// function, thus removing the need for i:
int power2(int x, int n)
{
    int result = 1;
    while (n-- > 0)
        result *= x;
    return result;

    // for (i = 1; i < n; i++)
    //     result *= x;
    return result;
}

void decompose(double x, long int_part, double frac_part){
    int_part = (long) x; /* drops the fractional part of x */
    frac_part = x - int_part;
}