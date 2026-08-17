#include <stdio.h>

int main(void) {
    // C allows the use of assignment operator to copy pointers, provided that 
    // they have the same type.
    int i, j, *p, *q;
    p = &i; // is an example of pointer assignment; the address of i is copied  into p.
    // this statement copies the content of p (the address of i) into q, in 
    // effect making q point to the same place as p:
    q = p;
    // both p and q now point to i, so we can change i by assigning a new value 
    // to either *p or *q
    // any number of pointer variables may point to the same object.
    // be careful not to confuse 
    q = p;
    // with 
    *q = *p;
    // the first statement is a pointer assignment, the second isn't

    p = &i;
    q = &j;
    i = 1;
    *q = *p;// this assignement copies the value that p points to (the value of i) into the object that q points to (the variable j).
}

// int main(void) {
//     int i = 10, *p, *q;
//     p = &i;
//     q = p;
//     // printf("i=%d, p=%p, q=%p\n", i, p, q);
//     // *q = 20;
//     i = 20;
//     printf("i=%d, p=%p, q=%p\ni=%d, *p=%d, *q=%d\n", i, p, q, i, *p, *q);
//     return 0;
// }