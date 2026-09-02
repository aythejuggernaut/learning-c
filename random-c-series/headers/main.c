#include <stdio.h>
#include "mikemath.h"

int foo() {
    return 1;
}

int main(void)
{
    vector_h first;
    first.x = 7.0f;
    first.y = 5.0f;
    
    vector_h second;
    second.x = 1.0f;
    second.y = 1.0f;

    Add(&first, &second);

    printf("first.x = %f\n, first.y = %f\n", first.x, first.y);
    int x = foo();
    printf("x = %d\n", x);

    return 0;
}

