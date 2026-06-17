#include <stdio.h>

int main(void) {
    // The sizeof operator allows a program to determine how much memory
    // is required to store values of a particular type. The sizeof operator
    // can determine the size of any type or variable. sizeof returns a
    // value of type size_t (an unsigned integer type defined in <stddef.h>)
    // and the %zd conversion specification is used to print size_t values.

    // The %zu conversion specifier is used to print an object of
    // type size_t. The size_t type is an unsigned integer type that
    // is used to represent the size of objects in memory. The %zd
    // conversion specifier is used to print an object of type size_t in
    // a signed decimal format.
    
    printf("%zu\n", sizeof(int));

    // sizeof(char) is always 1, but the sizes of the other types may vary.
    // On a 32-bit machine, sizeof(int) is normally 4. Note that sizeof is a
    // rather unusual operator, since the compiler itself can usually determine
    // the value of a sizeof expression. The sizeof operator can also be
    // applied to constants, variables, and expressions in general. If i and j
    // are int variables, then sizeof(i) is 4 on a 32-bit machine, as is
    // sizeof(i + j). When applied to an expression—as opposed to a type-sizeof
    // doesn't require parentheses; we could write sizeof i instead of sizeof(i).
    // However, parentheses may be needed anyway because of operator precedence.
    // The compiler would interpret sizeof i + j as (sizeof i) + j because
    // sizeof - a unary operator-takes precedence over the binary +
    // operator. To avoid problems, I always use parentheses in sizeof expressions.

    // Printing a sizeof value requires care, because the type of a sizeof
    // expression is an implementation-defined type named size_t. In C89, it's
    // best to convert the value of the expression to a known type before
    // printing it. size_t is guaranteed to be an unsigned integer type, so it's
    // safest to cast a sizeof expression to unsigned long (the largest of
    // C89's unsigned types) and then print it using the %lu conversion.

    // In C99, the size_t type can be larger than unsigned long. However, the
    // printf function in C99 is capable of displaying size_t values directly,
    // without needing a cast. The trick is to use the letter z in the
    // conversion specification, followed by one of the usual integer codes
    // (typically u).
    
    printf("%lu\n", (unsigned long)sizeof(int)); // This is the C89 way
    printf("%zu\n", sizeof(int)); // This is the C99 way

    return 0;
}


