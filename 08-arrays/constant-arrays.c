#include <stdatomic.h>
#include <stdio.h>

int main(void) {
    // an array, whether one-dimensional or multi-dimensional, can be made
    // "constant"
    // an array that's been declared const should not be modified by the 
    // program; the compiler will detect direct attempts to modify an element.
    // declaring an array to be const has a couple of primary advantages. it 
    // documents the program won't change the array, which can help
    // other programmers understand what the array's intended role is. the 
    // other advantage is that it allows the compiler to perform additional
    // optimizations and reliability checks. it also helps the compiler catch
    // errors by informing it that we don't intend to modify the array.
    
    const char hex_chars[] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    };

    // const isn't limited to arrays; it works with any variable. however, 
    // const is particularly useful in array declarations, because arrays may 
    // contain reference information that won't change during program execution.

    return 0;
}