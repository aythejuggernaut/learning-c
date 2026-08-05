#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // C23 introduced the typeof operators typeof and typeof_unqual. The typeof 
    // operators can operate on an expression or a type name and yield the type 
    // of their operand. If the type of the operand is a variably modified 
    // type, the operand is evaluated; otherwise, the operand is not evaluated 
    // The typeof operators and the auto storage duration class specifier both 
    // perform automatic type inference. They can both be used to determine the 
    // type of expression. The auto storage duration class specifier is 
    // commonly used to declare initialized variables where the type can be inferred from the initial value.

    // typeof(42); // int
    // typeof('a'); // char
    // typeof(3.14); // double
    // typeof(3.14f); // float
    // typeof(3.14L); // long double
    
    // typeof(42.0L); // long double
    // typeof((42, 3.14)); // double
    
    // typeof((int[]) {42, 314}); // int[2]
    
    // typeof(sizeof(42)); // size_t
    // typeof(42 + 3.14); // double
    
    // typeof(struct Point { int x, y; }); // struct Point
    // typeof(union U { int x, y; }); // union U
    
    // typeof(enum E { A, B, C }); // enum E
    
    // typeof(int[3] { 42, 314, 314159 }); // int[3]
    // typeof(int[42]); // int[42]


    // typeof and typeof_unqual are almost identical. The only difference i 
    // that typeof_unqual removes the cv-qualifiers (const and volatile) from 
    // the type of its operand. typeof preserves the cv-qualifiers.
    // typeof and typeof_unqual were added in C23 that let the compiler infer a 
    // type from an expression or another type. typeof feels very similar to sizeof - it examines a type without (usually) evaluating the expression.

    // Example
    // typeof_unqual(42); // int
    // typeof_unqual('a'); // char
    // typeof_unqual(3.14); // double
    // typeof_unqual(3.14f); // float
    // typeof_unqual(3.14L); // long double
    // typeof_unqual(42.0L); // long double
    // typeof_unqual((42, 3.14)); // double
    // typeof_unqual((int[]) {42, 314}); // int[2]
    // typeof_unqual(sizeof(42)); // size_t
    // typeof_unqual(42 + 3.14); // double
    // typeof_unqual(struct Point { int x, y; }); // struct Point
    // typeof_unqual(union U { int x, y; }); // union U
    // typeof_unqual(enum E { A, B, C }); // enum E
    // typeof_unqual(int[3] { 42, 314, 314159 }); // int[3]
    // typeof_unqual(int[42]); // int[42]
    
    // 1. typeof
    // typeof(expr) returns the exact type of expr.
    // it preserves: const, volatile, _Atomic, pointers, arrays, function types
    const int x = 5;
    typeof(x) y = 10; // the compiler sees: const int y = 10; y still has const qualifier
    int arr[10] = {0};
    typeof(arr) brr = {0}; // the compiler sees: int arr[10] brr[10] = {0}; brr has array type of length 10
    
    // 2. typeof_unqual
    // typeof_unqual(expr) returns the type without top-level qualifiers. 
    // it removes: const, volatile, _Atomic from the outermost type. not from nested types.
    // const int cx = 5;
    // typeof_unqual(cx) cy = 10; // the compiler sees: int cy = 10; cy does not have const qualifier
    // const int darr[10] = {0};
    // typeof_unqual(darr) drr = {0}; // the compiler sees: int drr[10] = {0}; drr does not have const qualifier

    // 3. Why is this useful?
    // suppose you don't know the exact type of a variable. instead of writing
    // long long copy = original; 
    // you can write:
    // typeof(original) copy = original;
    // this will copy the exact type of original to copy, including any qualifiers.
    // now if original changes type later, copy automatically changes too. this 
    // is particularly useful for generic programming where you want to 
    // preserve the exact type of an argument.

    // 4. Like sizeof
    int j = 5;
    typeof(j + 1);
    // the expression j + 1 is not executed. the compiler simply asks:
    // "what type would this expression have?"
    // exactly like sizeof(x + 1) doesn't perform the addition.
    
    // VARIABLY MODIFIED (VM) TYPE

    return EXIT_SUCCESS;
}
