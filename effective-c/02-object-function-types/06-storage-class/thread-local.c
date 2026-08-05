#include <stdio.h>
// #include <threads.h> // Required for C11/C17 thread_local macro

// Each thread gets its own isolated copy of this counter
// thread_local int thread_counter = 0; 

// int increment_counter(void* arg) {
//     char* thread_name = (char*)arg;
//     for (int i = 0; i < 3; i++) {
//         thread_counter++;
//         printf("%s: counter address = %p, value = %d\n", 
//                thread_name, (void*)&thread_counter, thread_counter);
//     }
//     return 0;
// }

int main(void) {
    // thread_local objects are local to each thread.
    // normally,
    // int counter;
    // there is one object.. counter.
    // with,
    // _Thread_local int counter;
    // each thread gets its own object. this is useful for things like request
    // counters, session IDs, etc.
    // changing A's counter doesn't affect B's. useful in multithreaded programming.

    // Syntax Across C Versions
    // The implementation syntax depends on the version of the C standard you are targeting:
    // C23 and Newer: The thread_local keyword is built directly into the language as a core keyword.
    // C11 to C17: The built-in keyword is _Thread_local. To use the cleaner
    // thread_local spelling, you must include the standard header <threads.h>.
    // Pre-C11 / Older Compilers: You must rely on compiler-specific extensions like __thread (GCC/Clang) or __declspec(thread) (MSVC)

    // Key Characteristics
    // Independent Lifetimes: The variable is initialized when the thread starts and destroyed when that specific thread terminates.
    // Implicitly Static: When used inside a function, thread_local forces the variable to behave like a static variable, but isolated per thread.
    // No Synchronization Needed: Because threads do not share this memory, you can read and write to a thread-local variable without using mutexes or locks, avoiding data races.
    // thrd_t t1, t2;

    // thrd_create(&t1, increment_counter, "Thread A");
    // thrd_create(&t2, increment_counter, "Thread B");

    // thrd_join(t1, NULL);
    // thrd_join(t2, NULL);

    // Common Use Cases
    // - Thread-Safe State: Fixing legacy, non-thread-safe functions (like the classic strtok) by making the internal tracking pointer thread-local instead of global static.
    // Global Error Tracking: The standard library errno variable is commonly implemented as a thread-local variable so one thread's error doesn't overwrite another's.
    // Performance Buffers: Creating high-speed, per-thread memory pools or scratchpads to completely eliminate memory allocation overhead in concurrent multi-threaded applications.
    
    return 0;
}
