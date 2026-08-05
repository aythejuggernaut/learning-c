#include <stdio.h>

int main(void)
{
    // the key idea behind volatile is this:
    // volatile tells the compiler: "don't assume this value stays the same.
    // always read it from memroy, and always perform every write.
    // normally, compilers aggressively optimize code. volatile tells the 
    // compiler not to optimize accesses to a particular object.

    // why is volatile needed?
    // suppose you write:
    int x = 10;
    printf("%d\n", x);
    printf("%d\n", x);

    // the compiler sees that x never changes. instead of loading x from memory 
    // twice, it may do something like:
    /*
        Load x once
        Keep it in a CPU register
        Use that register twice
    */
    // this is perfectly safe for normal variables.
    
    // now imagine x is actuall a hardware register:
    volatile int y;
    // every time you read it, the hardware might produce a different value.
    /*
        Example: First read -> 10   Second read -> 11    Third read -> 12
    */
    // if the compiler cached the first value, your program would be wrong.
    // that's why volatile exists.

    // Example 1: Real-time clock
    // imagine a clock stored in memory
    volatile int clock;
    printf("%d\n", clock);
    printf("%d\n", clock);
    // the compiler must generate two memory reads.
    // Runtime: First read  -> 10:30:01    Second read -> 10:30:02
    // without volatile, it might read only once:
    
    // First read -> 10:30:01
    // Use cached value, output:
    // 10:30:01
    // 10:30:01
    // which is wrong

    // Example 2: Memory-mapped I/O
    // many embedded system control hardware by reading and writing memory
    // addresses.

    // Address       Device
    // 0x40001000 -> LED
    // 0x40001004 -> Button
    // 0x40001008 -> Temperature sensor
    volatile unsigned int *LED = (volatile unsigned int*)0x40001000;
    // turning on the LED:
    *LED = 1;
    // turning it off:
    *LED = 0;
    // each write actually sends a signal to the hardware. if the compiler 
    // optimized away the writes, the LED would never change.\

    // Example 3: Why port = port; matters
    volatile int port;
    port = port;
    // at first glance, this seems pointless. for an ordinary variable:
    int a; a = a;
    // the compiler says: reading x and writing it back changes nothing.
    // so it removes the statement completely.

    // for a volatile object:
    port = port; // the compiler must perform: read port, write port.
    // because reading may trigger hardware, writing may trigger hardware
    // even though the value doesn't change, the side effects matter.

    // Example 4: Waiting for hardware
    // a common embedded programming pattern:
    volatile int ready;
    while (ready == 0){
        // wait
    }
    // suppose another device eventually changes ready to 1.
    // without volatile, the compiler might optimize this into:
    int temp = ready;
    while (temp == 0) {} // since temp never changes, the loop becomes infinite.
    // with volatile, the compiler must generate:
    /*
        Read ready, is it zero?
        Read ready, is it zero?
        Read ready, is it zero?
    */
    // until it changes

    // What does "external to the compiler" mean?
    // the compiler only understands your C code. it does not know about:
    // hardware, sensors, operating system signals, DMA controllers, interrupt handlers
    // these things can change memory without the comiler knowing.
    // Example:
    /* 
    CPU
    |
    | reads
    V
    volatile int sensor;

    Meanwhile...

    Sensor hardware updates sensor.
    */
    // from the compiler's point of view: "nobody changed sensor."
    // but in reality, the hardware did.

    // What optimizations does volatile prevent?
    volatile int v;
    int j = v;
    int k = v;
    // compiler must generate 
    // Read v -> Store into j
    // Read v -> Store into k
    // it cannot do:
    // Read v once
    // Reuse cached value
    // because the value might changed between the two reads.

    // Similarly,
    volatile int s;
    s = 1;
    s = 2;
    // compiler must generate ==> Write 1. Write 2
    // it cannot remove the first write

    // What does "exactly once" mean?
    // Reads and writes of volatile memory are touched exactly once.
    // the compiler must perform exactly one read.
    // Not ==> Read x.  Read x
    // and not: Don't read x
    // exactly one read.

    // Likewise,
    x = 5; // must perform exactly one write.

    // Why not use volatile for threads?
    // many beginners think:
    volatile int done; // is enough for thread communication. it is not.
    // volatile only prevents compiler optimizations. it does not:
    // - make operations atomic   - prevents race conditions
    // synchronize CPU caches.  - guarantee memory ordering between threads.
    
    // For multithreading, C provides:
    _Atomic int completed; // or synchronization primitives like mutexes
    
    // What is const volatile?
    const volatile int clockk; // means:
    // const -> your program cannot modify it.
    // volatile -> something else may modify it.
    printf("%d\n", clockk);
    // Your code cannot do:
    clockk = 5;     // ❌
    // but the hardware can change it every second:
    // 12:00:01
    // 12:00:02
    // 12:00:03

    // This is exactly how a hardware clock or read-only status register is 
    // modeled: your program can only read it, but the hardware keeps updating it.

    // Declaration      Meaning
    // int x                Normal variable. compiler may optimize reads/writes
    // volatile int x       Value may change unexpectedly. Every read/write must    actually happen 
    // const int x          Your program cannot modify x.
    //const volatile int x  Your program cannot modify x, but external hardware or another execution context may.

    // A useful way to remember the qualifiers is:
    // const answers: "Can my code write to this object?"
    // volatile answers: "Can something outside my code change this object, or does accessing it have important side effects?"


    // Objects are given a volatile-qualified type to allow for processes that 
    // are extrinsic to the compiler. The values stored in these objects may 
    // change without the knowledge of the compiler, or a write may synchronize 
    // externally. For example, every time the value from a real-time clock is 
    // read, it may change, even if the value has not been written to by the C 
    // program. Using a volatile-qualified type lets the compiler know that the 
    // value may change without its knowledge and ensures that every access to 
    // the real-time clock occurs. Otherwise, an access to the real-time clock 
    // may be optimized away or replaced by a previously read and cached value.
    // Declaring an object as volatile ensures that each read or write of that 
    // object at runtime occurs the same number of times and in the same order 
    // as indicated by the source code. For example, if port is defined as a 
    // volatile-qualified int, the compiler must generate instructions to read 
    // the value from port and then write this value back to port in the 
    // assignment. 
    port = port;

    // Without the volatile qualification, the compiler would see this as a 
    // no-op (a programming statement that does nothing) and might elimi- 
    // nate both the read and the write. Reads and writes of volatile memory 
    // are touched exactly once. A volatile operation cannot be eliminated or 
    // fused with a subsequent one, even if the compiler believes it’s useless. 
    // A volatile operation cannot be speculated, even if the compiler can undo 
    // or otherwise make that speculation benign. Objects with 
    // volatile-qualified types are used when a compiler is not aware of 
    // external interactions. For example, volatile-qualified types can be used 
    // for memory shared with untrusted code to avoid time-of-check to 
    // time-of-use (ToCToU) vulnerabilities. Such types are used to access 
    // objects from a signal handler and with setjmp/longjmp (refer to the C 
    // standard for information on signal handlers and setjmp/longjmp). 

    return 0;
}

