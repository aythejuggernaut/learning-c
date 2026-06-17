#include <stdio.h>

int main(void){
    // casts are sometimes necessary to avoid overflow or loss of precision
    // but on the other hand, they're sometimes used to deliberately 
    // accept overflow or loss of precision.

    // For example, if we want to compute the integer part of a float, we can
    // use a cast:
    float f = 3.14;
    int i = (int) f; // i will be 3

    //Conversely, we can convert an int to a float:
    int i = 3;
    float f = (float) i; // f will be 3.0

    // One pitfall with this is that the order in which you cast matters.
    // Consider this example:
    int i = 1;
    int j = 2;

    // In the first case, we add i and j as integers, then cast the result to a 
    // float. In the second case, we cast i and j to floats, then add them. 
    // The second case is what we want!
    float x = (float) (i + j);
    float y = (float) i + (float) j;
    // x and y may not be the same!

    // Here's an example of deliberate overflow:
    int i = 2000000;
    int j = 2000000;
    float f = (float) (i + j); // f will be 4000000.0

    // At first glance, this statement looks fine. The value of j * j is 
    // 1,000,000, and i is a long, so it can easily store values of this size,
    // right? The problem is that when two i n t values are multiplied, the 
    // result will have i n t type. But j * j is too large to represent as an
    // int on some machines, causing an overflow. Fortunately, using a cast 
    // avoids the problem:
    long i;
    int j = 1000;
    i = (long) j * j; // no overflow here

    // Since the cast operator takes precedence over *, the first j is 
    // converted to long type, forcing the second j to be converted as well.
    // Note that the statement wouldn't work, since the overflow would already 
    // have occurred by the time of the cast.
    i = (long) (j * j); // no overflow here either
    
    return 0;
}