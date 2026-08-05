#include <stdio.h>

int main(void)
{
    // when people say "pointer decay", they almost always mean 
    // array-to-pointer decay.
    // an array is not a pointer, but in most expressions, the array name is 
    // automatically converted ("decays") into a pointer to its first element.

    int numbers[5] = {10, 20, 30, 40, 50};
    // Memory
    // Address

    // 1000    10
    // 1004    20
    // 1008    30
    // 1012    40
    // 1016    50
    // the variable numbers is the entire array, its type is int[5]

    // WHEN DECAY HAPENS
    // In an expression, when an array name appears, it is converted 
    // to a pointer to the first element.
    // suppose you write  printf("%d\n", numbers[2]);
    // before evaluating numbers[2], the compiler treats numbers as 
    // &numbers[0] whose type is int *
    // then numbers[2] becomes *(numbers + 2)
    
    // FUNCTION CALLS
    // void print(int arr[])
    // this is not receiving an array, it receives a pointer to the first element. the compiler changes it to
    void print(int *arr);
    // so
    int number[5];
    print(number);
    // becomes number (int[5])  -> decays -> int *
    // the function receives only a pointer. it does not know the size of the array. it just knows that the memory address. that's why you usually write
    void print_new(int arr[], size_t size);

    // WHEN DECAY DOES NOT HAPPEN
    // 1. sizeof
    // sizeof(numbers); -> returns 5 * sizeof(int)
    // it yields size of the array, not size of pointer.
    // if it decayed to a pointer, sizeof would return 8 on a 64-bit system
    // or 4 on a 32-bit system

    // 2. Address-of operator
    // &numbers does not decay. its type is "pointer to int[5]" -> int (*)[5]

    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;  // arr decays to pointer to first element
    // After decay, numbers is treated as if it was: int *ptr = &numbers[0];

    printf("Size of array: %zu\n", sizeof(numbers));  // 20 (bytes)
    printf("Size of pointer: %zu\n", sizeof(ptr));  // 8 (bytes, on 64-bit)

    // array-to-pointer decay happens in almost every expression where 
    // an array name appears.

    // EXCEPTIONS: when array-to-pointer decay does NOT happen.

    // 1. The sizeof operator: sizeof applied to an array yields the 
    // total size of the entire array, not the size of a pointer to its first element.

    // 2. The address-of operator (&): &applied to an array yields a 
    // pointer to the entire array (type "pointer to array"), not a 
    // pointer to its first element.

    // 3. String literals in initialization: When initializing an array 
    // from a string literal, the string literal itself is treated as an array, 
    // not as a pointer to its first element.

    // EXAMPLE
    void printArray(int arr[], size_t size);
}
