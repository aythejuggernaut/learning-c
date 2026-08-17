#include <stdio.h>

#define N 10

int main(void)
{
    // pointer arithmetic is one way in which arrays and pointerrs are related, 
    // but it's not the only connection between the two. here's another key 
    // relationship: the name of the array can be used as a pointer to the 
    // first element in the array. this relationship simplifies pointer 
    // arithmetic and makes both arrays and pointers more versatile.
    int a[10], *p, sum = 0;
    // using a as a pointer to the first element in the array, we can modify 
    // a[0]:
    *a = 7; /* stores 7 in a[0] */
    // we can modify a[1] through the pointer a + 1:
    *(a + 1) = 12; /* stores 12 in a[1] */
    // in general, a + i is the same as &a[i] (both represent a pointer to 
    // element i of a) and *(a+i) is equivalent to a[i] (both represent element 
    // i itself). in other words, array subscripting can be viewed as a form of 
    // pointer arithmetic. the fact that an array name can serve as a pointer 
    // makes it easier to write loops that step through an array.
    for (p = &a[0]; p < &a[N]; p++)
        sum += *p;
    // to simplify the loop, we can replace &a[0] by a and &a[N] by a + N:
    for (p = a; p < a + N; p++)
        sum += *p;

    // although an array name can be used as a pointer, it's not possible to 
    // assign it a new value. attempting to make it point elsewhere is an error
    while (*a != 0)
        a++; /* WRONG */

    // this is no great loss; we can always copy a into a pointer variable, 
    // then change the pointer variable:
    p = a;
    while (*p != 0)
        p++;
}