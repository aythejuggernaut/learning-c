#include <stdio.h>

#define N 10

int find_largest(int [], int);

int main(void)
{
    // when passed to a function, an array
    int b[10];

    int largest = find_largest(b, N);
    // this call causes a pointer to the first element of b to be assigned t 
    // a; the array itself isn't copied.
    // the fact that an array argument is treated as a pointer has some 
    // important consequences:
    
    // - when an ordinary variable is passed to a function (pass by value), its 
    // value is copied; any changes to the corresponding parameter don't affect 
    // the variable. in contrast, an array used as an argument isn't protected 
    // against change since no copy is made of the array itself. for example, 
    // void store_zeros(int a[], int n) {
    //     int i;
    //     for (i = 0; i < n; i++)
    //         a[i] = 0;
    // }
    // to indicate that an array parameter won't be changed, we can include the 
    // word **const** in its declaration:
    
    // int find_largest(const int a[], int n) { ... }

    // if const is present, the compiler will check that no assignment to an 
    // element of a appears in the body of find_largest.
    
    // - the time required to pass an array to a function doesn't depend on the 
    // size of the array. there's no penalty for passing a large array, since 
    // no copy of the array is made.
    
    // - an array parameter can be declared as a pointer if desired. For 
    // example, 
    // int find_largest(int *a, int n) { ... }
    // will compile identically to the original declaration. declaring a to be 
    // a pointer is equivalent to declaring it to be an array; the compiler treats the declarations as though they were identical.

    // although declaring a parameter to be an array is the same as declaring 
    // it to be a pointer, the same isn't true for a variable. the declaration:
    int a[10];
    // causes the compiler to set aside space for 10 integers. in contrast, the declaration
    int *c;
    // causes the compiler to allocate space for a pointer variable. in the 
    // latter case, c is not an array; attempting to use it as an arrray can 
    // have disastrous results. for example, the assignment
    *c = 0; /* WRONG */
    // will store 0 where c is pointing. since we don't know where c is 
    // pointing, the effect of the program is undefined.

    // - a function with an array parameter can be passed an array "slice" - a 
    // sequence of consecutive elements. suppose we want find_largest to locate 
    // the largest element in some portion of an array b, say elements 
    // b[5]...b[14]. when we call find_largest, we'll pass it the address 
    // of b[5] and the number 10, indicating that we want find_largest to 
    // examine 10 array elements, starting at b[5]:
    // largest = find_largest(&b[5], 10)

    // Using a pointer as an array name
    // if we can use an array name as a pointer, will C allow us to subscript 
    // a pointer as though it were an array? yes, it will.
    int d[N], i, sum = 0, *p = d;
    for (i = 0; i < N; i++)
        sum += p[i];

    printf("Sum of elements of array d: %d\n", sum);
    // the compiler treats p[i] as *(p + i), which is a perfectly legal use of 
    // pointer arithmetic. although the ability to subscript a pointer may seem
    // less intuitive than using the dereference operator, it's a convenience
    // that many C programmers appreciate.

    return 0;
}

int find_largest(int a[], int n)
{
    int i, max;
    max = a[0];
    for (i = 1; i < n; i++) 
        if (a[i] > max)
            max = a[i];
    return max;
}
