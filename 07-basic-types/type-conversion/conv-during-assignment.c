#include <stdio.h>

int main(void) {
    // the usual arithmetic conversions don't apply to assignment. instead, C 
    // follows the simple rule that the expression on the right side of the 
    // assignment is converted to the type of the variable on the left side. 
    // if the variable's type is at least as "wide" as the expression's, this
    // will work without problems. however if the variable on the left side
    // is "narrower" than the expression on the right, then the expression
    // will be truncated.

    char c;
    int i;
    float f;
    double d;
    
    i = c; /* c is converted to int       */
    f = i; /* i is converted to float     */
    d = f; /* f is converted to double    */
    c = d; /* d is converted to char      */
    
    // other cases are problematic, as they can lead to the loss of information.
    // (which is why we generally avoid assigning, say, a floating-point value
    // to an integer variable). assigning a floating-point number to an integer
    // variable drops the fractional part of the number:

    i = 842.97;   /* i is now 842 */
    i = -842.97;  /* i is now -842 */

    // moreover, assigning a value to a variable of a narrower type can also
    // result in the loss of information. specifically, if the assigned value
    // lies outside the range of the variable's type, the result will be
    // mathematically incorrect .
    c = 1000;     /* WRONG: on 8-bit chars, c becomes 1000 mod 256 = 232 */
    i = 1.0e20;   /* WRONG: out of range for int on most machines */
    f = 1.0e100;  /* WRONG: out of range for float on most machines */

    // A "narrowing" assignment may elicit a warning from the compiler or from 
    // tools such as lint. It's a good idea to append the f suffix to a 
    // floating-point constant if it will be assigned to a float variable,
    f = 3.14159f;
    
    // without the suffix, the constant 3.14159 would have type double, possibly causing a warning message.

    return 0;
}