#include <stdio.h>
#include <stdlib.h>

// Storage duration refers to the lifetime of an object. 
// It determines when an object is created and when it is destroyed. 
// It also determines where an object is stored in memory.

int main() {
    // Global variables have static storage duration. They are created when the
    // program starts and destroyed when the program ends.
    static int global_var = 10;

    // Local variables have automatic storage duration. They are created when
    // the function is called and destroyed when the function returns.
    int local_var = 20;

    // Static variables inside a function have static storage duration, but they
    // have local scope. They are created when the function is called and
    // destroyed when the function returns.
    static int static_var = 30;

    // Dynamic variables have dynamic storage duration. They are created when
    // malloc() is called and destroyed when free() is called.
    int *dynamic_var = (int *)malloc(sizeof(int));
    *dynamic_var = 40;

    printf("global_var: %d\n", global_var);
    printf("local_var: %d\n", local_var);
    printf("static_var: %d\n", static_var);
    printf("dynamic_var: %d\n", *dynamic_var);

    free(dynamic_var);
    dynamic_var = NULL;

    
    // Scope -> Where can i use the object's name
    // Storage duration (lifetime) → How long does the object exist?

    // void f(void)
    // {
    //     int x = 10;
    // }
    // Scope: The name x is visible only inside f.
    // void f(void)
    // {
    //     int x = 10;   ← x is in scope here

    //     printf("%d\n", x);
    // }                 ← scope ends

    // Lifetime: The object x doesn't exist before f is called.
    // Program starts
    // ↓
    // x doesn't exist
    // ↓
    // Call f()
    // ↓
    // x is created
    // ↓
    // Use x
    // ↓
    // Return from f()
    // ↓
    // x is destroyed
    // The identifier x has a block scope. The object has automatic storage duration.


    // Storage duration
    // it answers: when is memory allocated and when is it released?
    // C has four storage durations:
    // 1. Automatic storage duration: The object exists for the duration of the function or block in which it is defined. It is created when the function or block is entered and destroyed when the function or block is exited. This is default for local variables, they have automatic storage duration.
    // Example:
    // void f(void) {
    //     int x = 10;
    // }
    
    // Execution:
    // Call f()
    // ↓
    // Memory allocated for x
    // ↓
    // x = 10
    // ↓
    // Return
    // ↓
    // Memory released
    
    // Every function gets a fresh object. Each call creates a brand new x. the previous one was destroyed. So the value of x is not preserved between function calls.

    // 2. Static storage duration: The object exists for the entire execution of the program. It is created when the program starts and destroyed when the program ends. Global variables and static variables have static storage duration.
    // int counter = 0;  this is a global variable
    // timeline:
    // Program starts
    // ↓
    // counter created
    // ↓
    // main()
    // ↓
    // other functions
    // ↓
    // program exits
    // ↓
    // counter destroyed
    // #include <stdio.h>

    // int counter = 0;

    // void f(void)
    // {
    //     counter++;

    //     printf("%d\n", counter);
    // }

    // int main(void)
    // {
    //     f();
    //     f();
    //     f();
    // }
    // output:
    // 1
    // 2
    // 3

    // the object never disappers.

    // Local static variables: even local variables can have static duration.
    // Example:
    // void f(void)
    // {
    //     static int x = 10;   ← x has local scope and static storage duration
    //     x++;
    //     printf("%d\n", x);
    // }
    // x is local to f. It is created once when the program starts
    // and destroyed when the program ends. It retains its value between calls to f. output:
    // 1
    // 2
    // 3
    // Although x has block scope, it has static storage duration. It is created once.

    // Block scope + Static lifetime
    // People often think:
    // Local variable
    // ↓
    // Must disappear
    // Not true. Example:
    // void f(void) {
    //     static int x;
    // }
    // Scope: only inside f
    // Lifetime: entire program
    // scope and lifetime are independent.


    // 3. Thread storage duration: this is used in multithreaded programs. Each
    // thread has its own copy of the object. it is limited to a single thread.
    // The keyword _Thread_local is used to declare a variable with thread storage duration.
    // Imagine two threads. Thread A and Thread B.
    // Each thread gets its own copy.
    
    // Example (C11):
    // _Thread_local int x;
    // thread A: x = 5;
    // thread B: x = 10;
    // They don't share the same object. you won't use this often unless you're 
    // writing multithreaded code.


    // 4. Allocated storage duration: The object exists for the duration of the 
    // program, or until it is explicitly deallocated using free(). It is 
    // created when malloc() is called and destroyed when free() is called. 
    // this is dynamic memory. memory is created when you request it and destroyed when you free it.
    int *p = malloc(sizeof(int));
    // important note:
    // malloc returns void*. we have to cast it to the type we want.
    if (p == NULL) {
        // handle error
    }
    free(p);
    p = NULL;
    
    // Example:
    // int *p = malloc(10 * sizeof(int));
    // The object exists until free(p) is called.
    // Lifetime is controlled by you.
    // You can create an object at any time and destroy it at any time.

    // Timeline:
    // Program
    // ↓
    // malloc()
    // ↓
    // Memory created
    // ↓
    // Use it
    // ↓
    // free()
    // ↓
    // Memory destroyed

    // Unline automatic variables, this memory is not destroyed when the function returns.
    // void f(void) {
    //     int *p = malloc(sizeof(int));

    //     *p = 10;
    // }
    // After f returns:
    // Pointer p
    // ↓
    // Destroyed
    // Allocated memory
    // ↓
    // Still exists
    // This is a memory leak! The memory is leaked. You can't access it anymore.
    // Until: free() is called.
    

    // VISUAL SUMMARY
    // 1. Automatic: function call -> function return
    // Call function
    // ↓
    // Create object
    // ↓
    // Use object
    // ↓
    // Return
    // ↓
    // Destroy object

    // 2. Static: program start -> program end
    // Program starts
    // ↓
    // Create object
    // ↓
    // Entire program
    // ↓
    // Program exits
    // ↓
    // Destroy object

    // 3. Thread: thread start -> thread end
    // Thread starts
    // ↓
    // Create object
    // ↓
    // Thread runs
    // ↓
    // Thread exits
    // ↓
    // Destroy object

    // 4. Allocated: malloc -> free
    // malloc()
    // ↓
    // Create object
    // ↓
    // Use object
    // ↓
    // free()
    // ↓
    // Destroy object


    // Think of every object in C as having three independent properties:
    // Type – What kind of data is it? (int, double, struct, etc.)
    // Scope – Where can its name be used?
    // Storage duration (lifetime) – How long does the object exist in memory?

    // For example: 
    // void f(void) {
    //     static int count = 0;
    // }

    // Type: int
    // Scope: Block scope (only inside f)
    // Storage duration: Static (exists for the entire program)

    // NOTE: a variable can have a very limited scope but still exist for the entire execution of the program.

    return EXIT_SUCCESS;
}