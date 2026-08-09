#include <stdio.h>

unsigned long int
average(double a, double b)
{
    double avg = (a + b) / 2;
    return (unsigned long int) avg;
}

void print_pun(void)
{
    printf("To C, or not to C: that is the question. \n");
}

int main(void)
{
    print_pun();

    // What we're doing is casting (converting) the return value of printf 
    // to type void. (In C, "casting to void" is a polite way of saying 
    // "throwing away.") Using (void) makes it clear to others that you 
    // deliberately discarded the return value. not just forgot that there was 
    // one. Unfortunately, there are a great many functions in the C library 
    // whose values are routinely ignored; using ( v o i d ) when calling them 
    // all can get tiresome,
    (void) printf("Hi, Mom!\n");
    return 0;
}