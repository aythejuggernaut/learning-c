#include <stdio.h>
#include <limits.h>

int main(void)
{
    // The minimum and maximum values of integer types are defined in 
    // the <limits.h> header file.
    printf("INT_MAX: %d\n", INT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("LONG_MIN: %ld\n", LONG_MIN);
    printf("LLONG_MAX: %lld\n", LLONG_MAX);
    printf("LLONG_MIN: %lld\n", LLONG_MIN);
    printf("SHRT_MAX: %hd\n", SHRT_MAX);
    printf("SHRT_MIN: %hd\n", SHRT_MIN);
    printf("UCHAR_MAX: %hhu\n", UCHAR_MAX);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("UCHAR_MAX: %hhu\n", UCHAR_MAX);

    // Signed integers store negative numbers, zero, and positive numbers. 
    // Standard signed integer types: signed char, short int, int, long int, long long int.
    // Every signed integer type has a corresponding unsigned integer type.
    // Unsigned integers store zero and positive numbers only.
    // The keyword int may be omitted in declarations such as short, long, and long long.
    // Integer type sizes are implementation-defined (depend on the compiler and platform).
    // The guaranteed size order is: char ≤ short ≤ int ≤ long ≤ long long
    // Wider integer types can represent all values of narrower integer types.
    // Integer limits are defined in <limits.h> (e.g., INT_MAX, INT_MIN, LONG_MAX).
    // Some compilers provide extended integer types (e.g., __int128).
    // C23 introduces bit-precise integer types using _BitInt(n) and unsigned _BitInt(n), where n specifies the exact bit width.
    // The maximum supported _BitInt width is given by BITINT_MAXWIDTH.
    // The int type usually matches the processor's natural word size.
    // Use <stdint.h> or <inttypes.h> for fixed-width integer types, such as int32_t and uint64_t.
    // intmax_t and uintmax_t are the largest standard signed and unsigned integer types, capable of representing any standard integer value.
}