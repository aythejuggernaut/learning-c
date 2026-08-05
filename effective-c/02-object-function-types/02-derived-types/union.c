#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // A union is like a structure except that all members share the same 
    // memory. the memory used by the member objects overlaps. Unions provide 
    // multiple different ways to look at the same memory.
    
    struct Example {
        int x;
        float y;
    };

    // Memory:
    // +--------+--------+
    // |   x    |   y    |
    // +--------+--------+
    // Each member has its own storage space.

    union ExampleU {
        int x;
        float y;
    };
    // +--------+
    // | shared |
    // +--------+
    // Both members occupy the same bytes. Only one member occupy the same
    // at a time.
    // The size of the union is large enough to hold the largest member.
    // All members start at the same memory address.

    // EXAMPLE
    union ExampleU e;
    e.x = 10;
    // memory contains the bit representation of integer 10
    e.y = 10.0f;
    // those same bytes are overwritten. memory contains the bit representation of float 10.0f
    // now e.x no longer contains 10.
    // The memory now contains the binary representation of the floating-point value.

    union { int a; char b; } u;
    u.a = 1;
    u.b = 'A';
    printf("%d\n", u.a);   // prints the bit pattern of 'A'
    printf("%c\n", u.b);   // prints the char A
    
    // OUTPUT ON A SYSTEM WITH 
    // LITTLE ENDIAN BYTE ORDER
    // AND ASCII CHARACTER SET.
    // 41 00 00 00

    // To be safe the bit pattern 
    // MUST be documented
    // and the program shouldnt depend on the bit pattern.
    
    // WHY USE UNIONS?

    // 1. To save memory.
    union Data { 
        char string[100]; 
        int number; 
        double real;
    };
    // If the union is declared as a local variable, only one of the following 
    // declarations will cause an object to be created and storage allocated.
    union Data data;
    // All members share the same memory.
    // size is 100 bytes.
    // Only one member can be stored at a time.
    // instead of storing int, float, double, long double all at once,
    // store only whichever one is currently needed.

    // 2. To implement variant types/ Interpret the same bytes differently
    // For example, network packets, binary file formats, hardware registers, 
    // floating-point representations.

    // Reinterpret the same bytes differently
    // union IP {
    //     struct { unsigned char a, b, c, d; } octets;
    //     unsigned int whole_integer;
    // };
    // union IP ip;
    // ip.octets.a = 192;
    // ip.octets.b = 168;
    // ip.octets.c = 1;
    // ip.octets.d = 1;
    // printf("%d\n", ip.whole_integer);
    
    
    // A variable that can be one of several types.
    // Example:
    union { int type; struct { char *string; } s; } value;
    value.type = 0;
    value.s.string = "hello";
    // This is a variant type.

    // The union occupies enough space for its largest member.

    // WHY DOES IT SAVE MEMORY?
    // A struct would have to allocate space for all the members.
    // data = { "string": "hello", "number": 123, "real": 123.45 }
    // If each of the members is large, then a struct that can hold them all 
    // might use a lot of memory.
    // without a union: 
    struct node {
        int inode;
        float fnode;
        double dnode;
        long double ldnode;
    };

    union {
        float f;
        struct {
            uint32_t significand : 23;
            uint32_t exponent : 8;
            uint32_t sign : 1;
        };
    } float_encoding;

    // Memory:
    // +------+-------+--------+-------------+
    // | int  | float | double | long double |
    // +------+-------+--------+-------------+
    // every node stores all four values, even though only one is used.
    
    // With a union:
    // +-------------+
    // | largest type|
    // +-------------+
    // only one block of memory is allocated.
    // If long double is the largest member, the union is only as large as a 
    // long double, not the sum of all four types. 
    // That's why the book notes that GCC on x86-64 saved 16 bytes per node.

    // Summary
    // Array-to-pointer decay means an array automatically converts to a pointer to its first element in most expressions. The array itself is not a pointer.
    // A union is like a struct, except all members share the same storage. Writing to one member changes the underlying bytes seen by the others.
    // Listing 2-8 uses a union to interpret the same 32 bits either as a float or as its IEEE 754 components (sign, exponent, and significand).
    // Listing 2-9 uses a tagged union: the type field records which member of the union is currently valid, allowing one struct node to hold either an int, float, double, or long double while using only enough space for the largest of those types. This is a common pattern in compilers, interpreters, binary protocols, and operating systems.
  
    return 0;
}