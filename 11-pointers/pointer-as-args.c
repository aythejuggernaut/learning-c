#include <stdio.h>

void decompose(double x, long *int_part, double *frac_part);
// void decompose(double, long *, double *);

int main(void)
{
    // A variable supplied to an argument in a function call is protected 
    // against change, because C passes arguments by value. This property of C 
    // can be a nuisance if we want the function to be able to modify the 
    // variable.
    // Pointers offer a solution to this problem: instead of passing a variable 
    // x as the argument to a function, we'll supply &x, a pointer to x.

    // We'll declare the corresponding parameter p to be a pointer. When the 
    // function is called, p will have the value &x, hence *p (the object that 
    // p points to) will be an alias for x. Each appearance of *p in the body 
    // of the function will be an indirect reference to x, allowing the function both to read x and to modify it.

    long i;
    double d;
    decompose(3.14159, &i, &d);
    // because of the & operator in front of i and d, the arguments to 
    // decompose are pointers to i and d, not the values of i and d. when 
    // decompose is called, the value 3.14159 is copied into x, a pointer to i 
    // is stored in int_part, and a pointer to d is stored in frac_part.
    // when decompose returns, i and d will have the values 3 and .14159.

    // we must put the & operator in front of i so that scanf is given a 
    // pointer to i; that pointer tells scanf where to put the value that it 
    // reads. without the &, scanf would be supplied with the value of i.
    // although, scanf's arguments must be pointers, it's not always true that 
    // every argument needs the & operator. 
    int j, *p;
    p = &j;
    scanf("%d", p);

    // since p contains the address of j, scanf will read an integer and store 
    // it in j. using & operator in the call would be wrong:
    // scanf("%d", &p); /* WRONG */
    // scanf would read an integer and store it in p instead of j.

    // failing to pass a pointer to a function when one is expected can have 
    // disastrous results. suppose that we call decompose without the & 
    // operator in front of i and d:
    decompose(3.14159, i, d);
    // decompose is expecting pointers as its second and third arguments, but 
    // it's been given the values of i and d instead. decompose has no way to 
    // tell the difference, so it will use the values of i and d as though they 
    // were pointers. when decompose stores values in *int_part and *frac_part, 
    // it will attempt to change unknown memory locations instead of modifying 
    // i and d.
    // if we've provided a prototype for decompose (as we should always do, of 
    // course), the compiler will let us know that we're attempting to pass 
    // arguments of the wrong type. In the case of scanf, however, failing to 
    // pass pointers often goes undetected by the compiler, making scang an 
    // especially error-prone function.
}

void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long) x;
    *frac_part = x - *int_part;
}