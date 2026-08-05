#include <stdio.h>

int main(void) {
    // A restrict-qualified pointer is used to promote optimization. Objects 
    // indirectly accessed through a pointer frequently cannot be fully 
    // optimized because of potential aliasing, which occurs when more than one
    // pointer refers to the same object. Aliasing can inhibit optimizations 
    // because the compiler can’t tell whether an object can change values 
    // when another apparently unrelated object is modified

    // restrict does not change what your program does. instead, it makes a 
    // promise a to the compiler, allowing it to generate faster code.
    // the promise is:
    // "for the lifetime of this pointer, the object it points to will only be 
    // accessed through this pointer (or a value derived from it).""

    // Why does restrict exist?
    void add (int *a, int *b) {
        *a = *a + *b;
    }
    // the compiler has to consider the possibility that a and b point to the 
    // same integer.
    int x = 10;
    add(&x, &x); // both pointers refer to the same object. this is aliasing.

    // What is aliasing?
    // it means two or more pointers refer to the same object. example:
    int *p = &x;
    int *q = &x;
    *p = 20; // also changes *q because both point to the same object.

    // Why is aliasing a problem?
    // suppose the compiler sees 
    // *a = *a + *b;
    // if a and b might alias, the compiler has to be conservative.
    // it cannot assume:
    // - changing *a won't affect *b
    // - reading *b twice gives the same value
    // it must generate safer (sometimes slower) code.

    // Example without restrict
    void copy(int *p, int *q) {
        *p = *q;
        int x = *q;
    }

    // the compiler thinks: "maybe p and q point to the same object."
    // if then do then: 
    *p = *q; // changes the same object that q points to.
    // so the compiler cannot freely reorder or optimize accesses.

    // Now introduce restrict
    void copy_restrict(int *restrict p, int *restrict q) {
       *p = *q;
        int x = *q;
    }
    // Now you're promising: "p and q refer to different objects."
    // Memory:
    // p -----> Object A
    // q -----> Object B

    // the compiler now knows: changing object A cannot affect object B.
    // this enables many optimizations.
    // restrict does not make pointers non-overlapping, it merely says:
    // "i promise they don't overlap."
    // the compiler trusts you. if you lie, your program has undefined behavior.
    // The programmer's responsibility
    // - dst must not overlap src
    // - distance between dst and src must be >= n
    // - once you use restrict, you cannot violate that promise.
    // A safe use case: copying between two different arrays.


    // A real optimization
    // without restrict:
    // 1. for (int i = 0; i < n; i++)
    //     a[i] += b[i];
    // 2. void vector_add_naive(unsigned n, int *a, int *b) {
    //     while (n-- > 0) {
    //         *a = *a + *b;
    //         a++;
    //         b++;
    //     }
    // }
    
    // with restrict:
    // 1. void add(int n,
    //      int *restrict a,
    //      int *restrict b)
    // {
    //     for (int i = 0; i < n; i++)
    //         a[i] += b[i];
    // }
    // 2. void vector_add_opt(unsigned n, int *restrict a, int *restrict b) {
    //     while (n-- > 0) {
    //         *a = *a + *b;
    //         a++;
    //         b++;
    //     }
    // }
    // the compiler a and b are independent so it's safe to optimize.
    
    // Why is vector_add_opt faster?
    // The compiler knows:
    // - a and b do not overlap
    // - Each iteration touches independent memory.
    // - No read-after-write dependency between iterations.
    // This allows:
    // 1. Instruction-level parallelism (ILP)
    //    - issue load (*b) in same cycle as store (*a)
    // 2. Vectorization (SIMD)
    //    - load 4 elements at once, add 4 elements at once
    // 3. Out-of-order execution
    //    - reorder instructions for better pipeline filling
    // 4. Better branch prediction
    //    - loop structure is simpler


    void f(unsigned int n, int *restrict p,  int *restrict q) {
        while (n-- > 0) {
            *p++ = *q++;
        }
    }
    // this copies an array.
    int src[4] = {1,2,3,4};
    int dst[4];
    f(4, dst, src);
    // Memory:
    // src -> 1 2 3 4
    // dst -> ? ? ? ?

    // each iteration copies one element.
    // dst[0] = src[0];
    // dst[1] = src[1];
    // dst[2] = src[2];
    // dst[3] = src[3];
    // because of restrict, the compiler knows src and dst never overlap.
    // it therefore can read ahead, vectorize, pipeline, reorder ops safely.    
    // restrict is a promise you make to the compiler, not something the 
    // compiler checks: 
    // so it says, during the lifetime of these pointers inside f, the objects 
    // accessed through p will not be accessed through q, and vice versa.
    // In other words:
        // p is the only way the function accesses the destination array.
        // q is the only way the function accesses the source array.
        // They do not overlap.
    // Because of this promise, the compiler is free to assume that reading through q can never be affected by writing through p.

    // The loop
    while (n-- > 0) {
       *p++ = *q++;
    }
    // without worrying about optimization, this is equivalent to
    // p[0] = q[0];
    // p[1] = q[1];
    // p[2] = q[2];
    // ...
    // if the arrays don't overlap, this is perfectly fine.

    // The overlapping call
    int a[6] = {1,2,3,4,5,6};
    f(4, &a[1], &a[0]);
    // Initially:
    // index: 0 1 2 3 4 5
    // value: 1 2 3 4 5 6
    //        ^
    //        q

    //           ^
    //           p
    // q points to a[0]
    // p points to a[1]
    // the regions overlap: 
    // source:      a[0] a[1] a[2] a[3]
    // destination:      a[1] a[2] a[3] a[4]

    // What would happen without restrict
    // Iteration 1: a[1] = a[0]  ==> Array: 1 1 3 4 5 6
    // Iteration 2: a[2] = a[1]  ==> Array: 1 1 1 4 5 6
    // Iteration 3: a[3] = a[2]  ==> Array: 1 1 1 1 5 6
    // Iteration 4: a[4] = a[3]  ==> Array: 1 1 1 1 1 6
    // Final Array: 1 1 1 1 1 6

    // What happens with restrict
    // The compiler assumes no overlap and optimizes aggressively.
    // It might:
    // 1. Load 4 elements into SIMD registers
    // 2. Move data between registers
    // 3. Write 4 elements back
    // But because of the overlap, the data it loads might already be corrupted.
    // The actual result is undefined behavior.
    // The compiler doesn't know it's undefined; it trusted you.
    
    // Why restrict changes things
    // The compiler can perform "forward substitution" when it knows pointers 
    // don't overlap.
    // Consider:  
    // void set_to_zero(unsigned n, int *restrict p) {
    //     while (n-- > 0)
    //         *p++ = 0;
    // }
    
    // set_to_zero(8, &a[i]);
    // Without restrict: compiler must write: load, store, increment.
    // With restrict: compiler knows p is the only way to access the array.
    // It can then optimize the loop to a single block-store.

    // because you promised there is no overlap, the compiler can reason differently. it sees
    // p[0] = q[0];
    // p[1] = q[1];
    // p[2] = q[2];
    // p[3] = q[3];
    
    // and thinks: "Writing through p cannot possibly change anything read 
    // through q, because restrict quarantees they refer to different objects."
    // therefore, it can load values from q early, reorder ops, vectorize the 
    // loops, and aggressively optimize in ways it never could without restrict.
    // restrict is the compiler's license to optimize aggressively, but it
    // relies entirely on the programmer not lying.
    // For example, it might transform the code conceptually into
    // int t0 = q[0];
    // int t1 = q[1];
    // int t2 = q[2];
    // int t3 = q[3];

    // p[0] = t0;
    // p[1] = t1;
    // p[2] = t2;
    // p[3] = t3;
    // or even use SIMD instructions to copy several integers at once.
    // With overlapping pointers, those transformations produce different 
    // results from the simple loop.

    // Why it's undefined behavior
    // the C standard says that if you violate the restrict contract, the 
    // behavior is undefined. that means anything can happen:
    // - it may appear to work
    // - it may produce the cascading 1 1 1 1 1 6,
    // - it may produce 1 1 2 3 4 6,
    // - it may produce some other result,
    // - future compiler versions may behave differently.
    // The compiler is allowed to optimize assuming your promise was true.

    // When to use restrict?

    // 1. Large array operations
    // void vector_add(int *restrict a, int *restrict b, int *restrict c, size_t n)
    // 2. Memory copying
    // void memcpy_safe(int *restrict dst, const int *restrict src, size_t n);
    // 3. Aliasing-sensitive algorithms
    // (e.g., image processing, signal processing)

    // When NOT to use
    // - When you're not sure about overlap
    // - When performance gain is not critical
    // - When the function is small or simple

    // Distance >= n rule
    // if the arrays have at least 'n' elements between them,
    // they cannot overlap. suppose:
    // dst = &a[5];
    // src = &a[0];
    // n = 4
    // then 
    // source:      a[0] a[1] a[2] a[3]
    // destination: a[5] a[6] a[7] a[8]
    // there are 5 elements between a[0] and a[5]. since n=4, 
    // the distance is >= n, so these don't overlap.

    // In general, for forward copying, you need
    // dst >= src + n OR src >= dst + n
    // that is, the two ranges: [src, src+n] and [dst, dst+n] must be completely disjoint.
    // If they overlap at all, passing them to a function whose parameters are declared restrict violates the promise and results in undefined behavior.

    // The most important thing to remember about restrict is that it is a promise about aliasing. When you declare a pointer as restrict, you're telling the compiler: "No other pointer used in this context will access the same object." In return, the compiler is free to generate more aggressive optimizations. If that promise is broken—for example, by passing overlapping memory regions to two restrict pointers—the program has undefined behavior.

    // size_t dst = p - a;
    // size_t src = q - a;
    // if(dst < src) {
    //     if(dst + n > src) {
    //         /* overlap detected */
    //     }
    // }
    // size_t dst = p - a;
    // size_t src = q - a;
    // if(src < dst) {
    //     if(src + n > dst) {
    //         /* overlap detected */
    //     }
    // }

    // The distance between dst and src must be at least n
    // In other words: dst >= src + n OR src >= dst + n
    // which is equivalent to:
    // dst - src >= n OR src - dst >= n

    // For dst = &a[5] and src = &a[0] and n = 4
    // dst - src = 5
    // src - dst = -5
    // 5 >= 4 OR -5 >= 4
    // true OR false
    // true

    return 0;
}
