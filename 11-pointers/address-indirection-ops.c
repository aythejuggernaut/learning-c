#include <stdio.h>

int main(void) {
    // C provides a pair of operators designed specifically for use with 
    // pointers. To find the address of a variable, we use & (address) 
    // operator. if x is a variable, then &x is the address of x in memory. To 
    // gain access to the object that a pointer points to, we use the * 
    // (indirection) operator. If p is a pointer, then *p represents the object to which p currently points.
    
    int i;
    int *p = &i;
    
    // we can even combine the declaration of i with the declaration of p, 
    // provided that i is declared first:
    // int i, *p = &i;
    
    // Applying & to a variable produces a pointer to the variable; applying * 
    // to the pointer takes us back to the original variable:
    int j = *&i; /* same as j = i; */
    
    // Never apply the indirection operator to an uninitialized pointer 
    // variable.  If a pointer variable hasn't been initialized, attempting to 
    // use the value of q in any way causes undefined behavior. In the 
    // following example, the call of printf may print garbage, cause the 
    // program to crash, or have some other effect:
    int *q;
    printf("%d", *p); /* WRONG */

    // Assigning a value to *q is particularly dangerous. if q happens to 
    // contain a valid memory address, the following assignment will attempt to 
    // modify the data stored at that address:
    *q = 1; /* WRONG */

    // If the location modified by this assignment belongs to the program, it 
    // may behave erratically: if it belongs to the operating system, the 
    // program will most likely crash. Your compiler may issue a warning that p 
    // is uninitialized, so pay close attention to any warning messages you get.
}
