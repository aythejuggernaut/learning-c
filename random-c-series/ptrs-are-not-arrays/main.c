#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    int *array;
    size_t size;
} array_t;

array_t* array_init(size_t size) {
    array_t* newArray = malloc(sizeof(array_t));
    
    newArray->size = size;
    newArray->array = malloc(size * sizeof(int));

    return newArray;
}

void printArray(array_t* myArray) {
    for (int i = 0; i < myArray->size; i++) {
        printf("%d ", myArray->array[i]);
    }
}

int main() {
    array_t* someData = array_init(10);

    printArray(someData);
    
    return 0;
}