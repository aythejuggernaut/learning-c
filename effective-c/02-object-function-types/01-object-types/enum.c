#include <stdio.h>

int main(void)
{
    // Enum is a user-defined type that consists of a set of named integer 
    // constants. It allows you to define a type that assigns names 
    // (enumerators) to integer values in cases with an enumerable set of 
    // constant values.
    // By default, the first enumerator is assigned the value 0, and each 
    // subsequent enumerator is assigned the value of the previous one plus 1.
    // You can also assign explicit integer values to the enumerators.

    // enum Color { RED, GREEN, BLUE };
    // enum Color color = BLUE;
    // printf("color = %d\n", color);

    // enum a: unsigned long long {
    //     a0 = 0xFFFFFFFFFFFFFFFFULL
    // };
    // printf("a0 = %lld\n", a0);

    // Specifying the underlying type is better for portability, that means 
    // your program behaves consistently on different compilers and platforms.

    // Benefits include:
    // 1. You know exactly how much storage the enum uses.
    // 2. You know the range of values it can hold.
    // 3. Large values won't accidentally overflow.
    // 4. Different compilers won't choose different underlying types.

    // Without specifying the type:
    // enum Numbers {
    //     BIG = 5000000000
    // };
    // This may fail or behave differently because the compiler might use int,
    // which usually cannot hold 5,000,000,000.

    // With C23:
    // enum Numbers : unsigned long long {
    //     BIG = 5000000000ULL
    // };
    // This is valid because unsigned long long is large enough.
    // It's always safer to specify the underlying type for your enum.

    // C23 allows programmers to specify the underlying type of an enum.
    // Syntax:
    // enum Name : type {
    //     ...
    // };
    // Before C23, the compiler chose the underlying integer type automatically.
    // Specifying the underlying type improves portability, predictability, and control over storage and value range.
    // The underlying type determines the size and range of values an enumeration can store.
    // In the example:
    // enum a : unsigned long long {
    //     a0 = 0xFFFFFFFFFFFFFFFFULL
    // };
    // The underlying type is unsigned long long, allowing the enum constant a0 
    // to store the maximum 64-bit unsigned integer value (2⁶⁴ − 1 or 18446744073709551615).

    // It is good practice to specify the underlying type for your enum to ensure 
    // portability and predictability.

    // enum a : unsigned long long { a0 = 0xFFFFFFFFFFFFFFFFULL };
    // enum b : signed long { b0 = LLONG_MAX };
    // enum c : unsigned char { c0 = 0xFF };

    return 0;
}