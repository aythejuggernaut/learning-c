#include <stdio.h>

// In most modern computers, main memory is divided into bytes, with each byte 
// capable of storing eight bits of information.
// Each byte has a unique address to distinguish it from the other bytes in 
// memory, we can think of addresses as numbers that range from 0 to n - 1.
// An executable program consists of both code (machine instructions 
// corresponding to statments in the original C program) and data (variables in 
// the original program). Each variable in the program occupies one or more 
// bytes of memory.

// When we store the address of a variable i in the pointer variable p, we say 
// that p "points to" i. In other words, a pointer is nothing more than an 
// address, and a pointer variable is just a variable that can store an address.

int *p; // p is a pointer variable capable of pointing to objects of type int.
// C requires that every pointer variable point only to objects of a particular 
// type (the referenced type):
int *p; /* points only to integers */
double *q; /* points only to doubles */
char *r; /* points only to characters */
// there are no restrictions on what the referenced type may be. In fact, a
// pointer variable can even point to another pointer.