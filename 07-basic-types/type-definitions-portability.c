#include <stdio.h>

int main(void) {
    // Type definitions are an important tool for writing portable programs. 
    // One of the problems with moving a program from one computer to another
    // is that types may have different ranges on different machines. 
    // For greater portability, consider using typedef to define new names 
    // for integer types.

    // Suppose that we're writing a program that needs variables capable of
    // storing product quantities in the range 0-50,000. We could use long
    // variables for this purpose (since they're guaranteed to be able to
    // hold numbers up to at least 2,147,483,647), but we'd rather use int
    // variables, since arithmetic on int values may be faster than operations
    // on long values; also, int variables may take up less space.
    // Instead of using the int type to declare quantity variables, we can
    // define our own "quantity" type:

    typedef int Quantity;
    // Note: This declaration must appear before the first use of the new
    // name. The compiler treats Quantity as a synonym for int; thus,
    // Quantity variables are really ordinary int variables.

    Quantity q;

    // when we transport the program to a machine with short integers, we'll
    // change the definition of Quantity to short instead of int; as a result,
    // all variables of type Quantity will become short variables, without our
    // needing to modify the rest of the program.

    // This technique doesn't solve all our problems, unfortunately, since
    // changing the definition of Quantity may affect the way Quantity variables
    // are used. At the very least, calls of printf and scanf that use Quantity
    // variables will need to be changed, with % conversion specifications
    // replaced by % ld.

    // In C99, the <stdint.h> header uses typedef to define names
    // for integer types with a particular number of bits. For example,
    // int32_t is a signed integer type with exactly 32 bits. Using these
    // types is an effective way to make programs more portable.

    return 0;
}