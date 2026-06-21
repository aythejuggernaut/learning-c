#include <stdio.h>

int main(void) {
    int a[6] = {0};
    // the sizeof operator can determine the size of an array (in) 
    // bytes. If a is an array of 10 integers, then sizeof(a) is typically 
    // 40 (assuming that each integer requires 4 bytes). we can use the sizeof 
    // to measure the size of an array element, such as a[0]. dividing the 
    // array size by the element size gives the lenght of the array.

    int length = sizeof(a) / sizeof(a[0]);
    for (int i = 0; length; i++) {
        a[i] = i;
    }

    for (int i = 0; length; i++) {
        printf("%d\n", a[i]);
    }

    // with this technique, the loop doesn't have to be modified if the array 
    // length should change at a later date. using a macro to represent the 
    // array length has the same advantage, of course, but the sizeof technique 
    // is slightly better, since there's no macro name to remember (and 
    // possibly get wrong).

    // One minor annoyance is that some compilers produce a warning message for 
    // the expression i ‹ sizeof (a) / sizeof (a [0]). The variable i probably
    // has the type int (a signed type), whereas sizeof produces a value of 
    // type size_t (an unsigned type). comparing a signed integer with an 
    // unsigned integer is a dangerous practice, although in this case it's 
    // safe because both i and sizeof(a) / sizeof(a[0]) have nonnegative values.
    // to avoid warning, we can add a cast that converts sizeof(a) / sizeof(a[0]) to a signed integer.

    for (int i = 0; i < (int) (sizeof(a) / sizeof(a[0])); i++)
        a[i] = 0;


    // writing (int) (sizeof(a) / sizeof(a[0])) is a bit unwieldy; defining 
    // a macro that represents it is often helpful:
    #define SIZE (int) (sizeof(a) / sizeof(a[0]))
    for (int i = 0; i < SIZE; i++)
        a[i] = 0;

    return 0;
}

// gcc -Wall -Wextra -fsanitize=undefined -g -pedantic -o sizeof-arrays sizeof-arrays.c