#include <stdio.h>

int main(void) {
    char c;
    short int s;
    int i;
    unsigned int u;
    long int l;
    unsigned long int ul;
    float f;
    double d;
    long double ld;
    
    // printf("size of char: %lu\n", sizeof(c));
    // printf("size of short int: %lu\n", sizeof(s));
    // printf("size of int: %lu\n", sizeof(i));
    // printf("size of unsigned int: %lu\n", sizeof(u));
    // printf("size of long int: %lu\n", sizeof(l));
    // printf("size of unsigned long int: %lu\n", sizeof(ul));
    // printf("size of float: %lu\n", sizeof(f));
    // printf("size of double: %lu\n", sizeof(d));
    // printf("size of long double: %lu\n", sizeof(ld));

    i = i + c;   /* c is converted to int        */
    i = i + s;   /* s is converted to int        */
    u = u + i;   /* i is converted to unsigned int */
    l = l + u;   /* u is converted to long int   */
    ul = ul + l; /* l is converted to unsigned long int */
    f = f + ul;  /* ul is converted to float     */
    d = d + f;   /* f is converted to double     */
    ld = ld + d; /* d is converted to long double */
    s = s + c;   /* c is converted to short int  */
    
    return 0;
}