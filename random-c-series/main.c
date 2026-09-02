#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* dynamicArray = malloc(sizeof(int)*5);

    dynamicArray[0] = 25;
    dynamicArray[1] = 23;
    dynamicArray[2] = 52;
    dynamicArray[3] = 24;
    dynamicArray[4] = 20;

    free(dynamicArray);
} 