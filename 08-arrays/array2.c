#include <stdio.h>

#define N 10

int main(void) {
    // C doesn't require that subscript bounds be checked; if a subscript goes 
    // out of range, the program's behavior is undefined. One cause of a 
    // subscript going out of bounds: forgetting that an array with n elements 
    // is indexed from 0 to n - 1, not 1 to n.
    
    int a[N], i;
    
    for (int i = 0; i < N; i++) a[i] = 0;

    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i);
    }

    // This loop will go out of bounds by 1 index. It will try to access a[10]
    // when the array is only indexed from 0 to 9. It may cause a crash
    // or corrupted data. It is a bug. Don't do this in real life.
    // With some compilers, this innocent-looking for statement causes an 
    // infinite loop! When i reaches 10, the program stores 0 into a[10]. 
    // But a[10] doesn't exist, so 0 goes into memory immediately after a[9].
    // If the variable i happens to follow a[9] in memory - as might be the
    // case - then i will be reset to 0, causing the loop to start over.
    for (i = 0; i <= N; i++)
        a[i] = 0;

    // gcc -fsanitize=address -g test.c -o test
    // when you compile the code with this flag, it will add
    // extra code to check for memory errors
    // when you run the code, it will print the runtime error
    // (address-out-of-bounds) or other memory-related errors

    // The -g flag means "add debug information".
    // The -fsanitize=address flag means "instrument the code to detect
    // memory errors at runtime".

    // gcc -fsanitize=undefined -g test.c -o test does the same thing
    // but it checks for undefined behavior instead of memory errors.

    // valgrind ./test
    // runs your program in a virtual CPU. It tracks every memory read/write
    // and maintains a "validity map" of memory.
    // It is slower than the compiled code but it is more thorough.
    // A "validity map" is a data structure that keeps track of which memory
    // addresses are valid and which are not.

    return 0;
}

