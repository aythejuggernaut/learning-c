#include <stdio.h>
#include <stdlib.h>

int* allocateOnHeap(int size)
{
    int* array = malloc(sizeof(int)*size);
    printf("heap memory address %p\n", array);
    printf("stack memory of a local %p\n", &array);

    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    return array;
}

int main(void)
{
    int size = 10;
    int* heapData = allocateOnHeap(size);
    printf("heap memory address %p\n", heapData);
    printf("stack memory of a local %p\n", &heapData);
 
    for (int i = 0; i < size; i++) {
        printf("heapData[%d]=%d\n", i, heapData[i]);
    }

    free(heapData);

    return 0;
}