#include <stdio.h>

// CASE 1
void f(void) {
    static int counter = 0;
    counter++;
    printf("%d\n", counter);
}

int main(void) {
    // static has two different meanings, depending on where it appears.
    // CASE 1: inside a function
    f(); // Output: 1
    f(); // Output: 2
    f(); // Output: 3

    // normally, int counter = 0; would be created every call.
    // timeline: call -> create counter -> destroy counter
    // but with static, it's different. timeline becomes:
    // Program starts
    // ↓
    // Create counter
    // ↓
    // Call f
    // ↓
    // Call f
    // ↓
    // Call f
    // ↓
    // Program ends
    // ↓
    // Destroy counter
    // The variable survives between calls.

    // CASE 2: outside a function
    // This means that the variable is hidden from other files.
    static int count = 0; // now count has internal linkage. that means,
    // only this source file can use count, other .c files cannot access it.

    // Why use static ?
    // void increment(void) {
    //     static unsigned counter = 0;
    //     counter++;
    //     printf("%u\n", counter);
    // }
    // It limits the scope, because we could write
    unsigned counter;
    // globally. that works, but now every function can modify it. keeping it 
    // local makes accidental modification impossible.
}