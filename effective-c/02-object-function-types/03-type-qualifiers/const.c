#include <stdio.h>

int main(void)
{
    // type qualifiers don't create new data types, they add rules and
    // guarantees about how an object can be accessed.
    // the three main type qualifiers are: const, volatile, and restrict

    // 1. const: object cannot or should not be modified after it is
    // 2. volatile: the object's value can change unexpectedly, i.e. at any
    // time without warning and the compiler should not optimize away reads and
    // writes to the object
    // 3. restrict: the programmer guarantees that the object will only be
    // accessed through a single pointer. a pointer is the only way to access 
    // an object (optimization hint)

    const int x = 1;
    // x = 2; // error: assignment of read-only variable 'x'
    // This is a constant integer. Its value cannot be changed.

    // we use const to tell both the compiler and other programmers
    // that this object is a constant and should not be modified.
    // a common error among beginners is to think that const makes a pointer
    // into a constant pointer, when in fact const makes an object into a
    // constant object

    // 1. What is casting away const ?
    const int i = 1;
    int *ip = (int *)&i; // this means pretent this is an int *, not a const int *. this is called casting away const.
    *ip = 2; // this is undefined behavior but might appear to work
    // Although the compiler lets you write this cast, the C standard says the behavior is undefined because the original object was declared const.
    // why might it appear to work ? because the object is const but not necessarily in read only memory. so the memory location might not be protected.
    // However, the language guarantees that const objects are stored in read only memory, but this does not apply to the memory location of a variable.
    // Although, the only exception is when a const object is declared without register keyword, which is not the case here. even in that case , it is implementation defined. so, it is undefined behavior. even if *ip prints 2 on your computer, the program is still incorrect.
    // the rule is that a const object can only be modified through a pointer to a const object.

    // undefine behavior means C standard gives no guarantees about what happens. possible outcome include: it appears to work, the program crashes, memory corruption, different behavior on another compiler/machine.
    // it is as if we are telling the compiler 'trust me, i know what i'm doing'. but the compiler can't verify our claim.

    // 2. when is casting away cost allowed ?
    // case 1: the original object is not const in the first place
    int y = 10;
    const int *ip2 = &y;
    int *ip3 = (int *)ip2;
    *ip3 = 20; // *(int *)ip2 = 20. this is allowed.
    // Here y is not const, so we can cast away const.
    // the above code is valid. y = 20
    printf("%d\n", y);
    
    // case 2: the original object is const
    const int j = 12;
    const int *jp = &j;
    *(int *)jp = 42; // j = 42; // behavior is undefined
    printf("%d\n", j); // this might print 12 or 42 or crash
    // the object itself was declared const int, changing it is undefinedd behavior. the cast doesn't magically remove the fact that j is constant.

    // 3. why have const int * at all ?
    // void printNumber(const int *p) {
    //     printf("%d\n", *p);
    // } 
    // the function promises: i will read the integer but won't change it.
    // we can call it with either:
    // int xi = 10;
    // printNumber(&xi); or:
    // const int y = 20
    // printNumber(&y); // because readidng is safe in both cases.
    
    // 4. why shouldn't you pass a const object to a function that modifies it?
    // void change(int *p) {
    //     *p = 100; // tries to modify a const object. this is undefined 
    // behavior. Don't pass a const object to code that modifies it.
    // }
    // const int xc = 5;
    // change((int *)&x);

    // const int x = 5; ==> x cannot be modified ==> safe? ✅
    // x = 10  ==> direct modification ==> safe? ❌ Compiler error
    // int *p = (int *)&x; *p = 10 ==> modify a const object through a cast. ==> safe? ❌ undefined behavior
    // *(int *)p = 10  => modify the original non-const object ==> safe? ✅
    // const int z = 5; const int *p = &z; *(int *)p = 10  ==> modify an originally const object ==> safe? ❌ undefined behavior
    
    // The key idea is that const applies to the object itself, not just the pointer. Casting away const is only safe if the original object was never declared const.

    // CONSTANT DECLARATION
    // for example:
    const int *p1; // pointer to a constant int
    int *const p2; // constant pointer to an int
    const int *const p3; // constant pointer to a constant int

    // in all three cases, p is a pointer. 
    // CASE 1: const int *x1 pointer to a constant int: which means the object it points to cannot be modified 
    int a = 10;
    int b = 20;
    const int *x1 = &a; // x1 points to a, but can't modify a through x1
    printf("%d\n", *x1); // OK: read the value
    *x1 = 15; // ERROR: cannot modify the value through x1
    x1 = &b; // OK: x1 can point somewhere else
    printf("%d\n", *p1); // prints 20
    // What is constant?
    // The integer being pointed to is treated as constant
    // ✅ Can change where p1 points. ❌ Cannot modify *p1.

    // CASE 2: int *const x2 -> constant pointer to an integer: which means the object it points to can be modified but cannot point somewhere else.
    int *const x2 = &a; // x2 points to a
    *x2 = 15; // OK: modifies a
    printf("%d\n", a); // prints 15
    x2 = &b // ERROR: x2 cannot point somewhere else. this is illegal because the pointer itself is constant.
    // What is constant ?
    // ✅ can modify the value ❌ cannot change the address stored in x2.

    // CASE 3: const int *const x3 -> constant pointer to a contand integer, which means the object it points to cannot be modified and cannot point somewhere else.
    const int *const x3 = &a;
    *x3 = 15; // ERROR: cannot modify a through x3
    x3 = &b; // ERROR: cannot point somewhere else
    printf("%d\n", *x3); // OK
    // What is constant ?
    // ❌ cannot modify *x3 ❌ cannot make x3 point elsewhere

    // Compare them side by sided
    // Declaration           can change value(*p)?   can change pointer(p)?
    // const int *x1         ❌ No                    ✅ yes   
    // int *const x1         ✅ yes                   ❌ No
    // const int *const x3   ❌ No                    ❌ No

    // A useful mnemonic is:
    // const before the base type (int) -> the data is constant.
    // const after the * -> the pointer is constant.

    
    // FOUR POSSIBLE COMBINATIONS OF POINTER MUTABILITY AND OBJECT MUTABILITY
    // 1. Constant pointer to a constant object
    const int *const p = &a; /* or */ int const *const z = &a;
    *p = 20; // ❌ cannot modify the object
    p = &b;  // ❌ cannot point somewhere else
    // what is constant? pointer => constant; object => constant;

    // 2. Constant pointer to a mutable object
    int *const l = &a;
    *l = 50; // ✅ modify a 
    l = &b;  // ❌ cannot point to b
    // what is constand?
    // pointer (*l = ...) => ✅
    // object (l = ...).  => ❌

    // 3. Mutable pointer to a constant object
    const int *o = &a;
    *o = 30; // ❌ cannot modify a through o
    o = &b;  // ✅ can point somewhere else
    // What is constant?
    // pointer (*o = ...)  => ❌
    // object (o = ...)    => ✅

    // Note: if a itself is not declared const, it can still be modified through
    // another non- const pointer or directly.
    const int *h = &a;
    a = 40; // ✅
    // const int * only promises that this pointer won't be used to modify the 
    // object

    // 4. Mutable pointer to a mutable object
    int *q = &a;
    *q = 100; // ✅ modify a
    q = &b;   // ✅ point to b
    *q = 200; // ✅ modify b
    // What is constant ? nothing

    // Summary Table
    // Declaration          Pointer Mutable?   Object Mutable (through pointer)?
    // const int *const p   ❌ No              ❌ No
    // int *const p         ❌ No              ✅ Yes
    // const int *p         ✅ Yes             ❌ No
    // int *p               ✅ Yes             ✅ Yes

    // An easy way to remember
    // Think of two independent questions:
    // 1. can pointer change to point somewhere else? 
    //      ==> *const p -> No
    //      ==> *p -> Yes
    // 2. Can the pointed-to object be modified through this pointer?
    //      ==> const int * -> No
    //      ==> int * -> Yes

    return 0;
}