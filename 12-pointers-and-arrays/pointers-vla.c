#include <stdio.h>

int main(void)
{
    // pointers are allowed to point to elements of variable-length arrays 
    // (VLAs), a feature of C99. an ordinary pointer variable would be used to 
    // point to an element of a one-dimensional VLA:
    // void f(int n) {
    //     int a[n], *p;
    //     p = a;
    // }
    // when the VLA has more than one dimension, the type of the pointer 
    // depends on the length of each dimension except for the first.
    // void f(int m, int n) {
    //     int a[m][n], (*p)[n];
    //     p = a;
    // }
    // since the type of p depends on n, which isn't constant, p is said to 
    // have a variably modified type. Note that the validity of an assignment 
    // such as p = a can't always be determined by the compiler. For example, 
    // the following code will compile but is correct only if m and n are equal:
    // int a[m][n], (*p)[m];
    // p = a;

    // if m # n, any subsequent use of p will cause undefined behavior. 
    // variably modified types are subject to certain restrictions, just as 
    // variable-length arrays are. The most important restriction is that the 
    // declaration of a variably modified type must be inside the body of a 
    // function or in a function prototype. Pointer arithmetic works with VLAs 
    // just as it does for ordinary arrays.


    // Q&A
    // Q: I don't understand pointer arithmetic. If a pointer is an address, does that mean that an expression like p + j adds j to the address stored in p? 
    // A: No. Integers used in pointer arithmetic are scaled depending on the type of the pointer. If p is of type i n t *, for example, then p + j typically adds 4 x j to p, assuming that int values are stored using 4 bytes. But if p has type double *, then p + j will probably add 8 x j to p, since double values are usually 8 bytes long.

    // Q: When writing a loop to process an array, is it better to use array subscripting or pointer arithmetic? 
    // A: There's no easy answer to this question, since it depends on the machine you're using and the compiler itself. In the early days of C on the PDP-11, pointer arithmetic yielded a faster program. On today's machines, using today's compilers, array subseripting is often just as good, and sometimes even better. The bottom line: Learn both ways and then use whichever is more natural for the kind of program you're writing.

    // Q: I read somewhere that i[a] is the same as a[i]. Is this true?
    // A: Yes, as long as a is a pointer. This is because the subscript operator
    // [] is symmetric. In other words, the expression a[i] is shorthand for
    // the expression (a + i), and because the subscript operator is symmetric,
    // i[a] is just shorthand for (i + a), which evaluates to the same thing
    // Yes, it is, oddly enough. The compiler treats i[a] as *(i+a), which is the same as *(a+i). (Pointer addition, like ordinary addition, is commutative.) But *(a+i) is equivalent to a[i]. Q.E.D. But please don't use i[a] in programs unless you're planning to enter the next Obfuscated C contest.

    // Q: Why is *a the same as a[] in a parameter declaration?
    // A: Both indicate that the argument is expected to be a pointer. The same operations on a are possible in both cases (pointer arithmetic and array subscripting, in particular). And, in both cases, a itself can be assigned a new value within the function. (Although C allows us to use the name of an array variable only as a "constant pointer," there's no such restriction on the name of an array parameter.)

    // Q: Is it better style to declare an array parameter as *a or a[]?
    // A: That's a tough one. From one standpoint, a [] is the obvious choice, since *a is ambiguous (does the function want an array of objects or a pointer to a single object?). On the other hand, many programmers argue that declaring the parameter as *a is more accurate, since it reminds us that only a pointer is passed, not a copy of the array. Others switch between *a and a[], depending on whether the funetion uses pointer arithmetic or subscripting to access the elements of the array. (That's the approach I'll use.) In practice, *a is more common than a[], so you'd better get used to it. For what it's worth, Dennis Ritchie now refers to the a[] notation as "a living fossil" that "serves as much to confuse the learner as to alert the reader."

    // Q: We've seen that arrays and pointers are closely related in C. Would it be accurate to say that they're interchangeable?
    // A: No. It's true that array parameters are interchangeable with pointer parameters, but array variables aren't the same as pointer variables. Technically, the name of an array isn't a pointer; rather, the C compiler converts it to a pointer when necessary. To see this difference more clearly, consider what happens when we apply the sizeof operator to an array a. The value of sizeof (a) is the total number of bytes in the array-the size of each element multiplied by the number of elements. But if p is a pointer variable, sizeof (p) is the number of bytes required to store a pointer value.

    // Q: You said that treating a two-dimensional array as one-dimensional works with "most" C compilers. Doesn't it work with all compilers?
    // A: No. Some modern "bounds-checking" compilers track not only the type of a pointer, but when it points to an array also the length of the array. For example, suppose that p is assigned a pointer to a[0][0]. Technically, p points to the first element of a[0], a one-dimensional array. If we increment p repeatedly in an effort to visit all the elements of a, we'll go out of bounds once p goes past the last element of a[0]. A compiler that performs bounds-checking may insert code to check that p is used only to access elements in the array pointed to by a[0]: an attempt to increment p past the end of this array would be detected as an error.

    // Q: If a is a two-dimensional array, why can we pass a[0] but not a itself to find_largest? Don't both a and a[0] point to the same place (the beginning of the array)?
    // A: They do, as a matter of fact-both point to element a [0] [0]. The problem is that a has the wrong type. When used as an argument, it's a pointer to an array, but find_largest is expecting a pointer to an integer. However, a [0] has type int*, so it's an acceptable argument for find largest. This concern about types is actually good; if C weren't so picky, we could make all kinds of horrible pointer mistakes without the compiler noticing.

    // Q: Do C compilers check for array bounds errors automatically?
    // A: Mostly no. The C standard does not require the compiler to check array bounds, nor does the C runtime typically include bounds checking code. As a result, accessing an array element outside its defined range is simply undefined behavior—a bug that might not manifest for months or years, or ever. (There are, however, compiler extensions and separate static or dynamic analysis tools that can detect these bugs, but they’re used less often than we’d like.)
}