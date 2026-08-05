#include <stdio.h>

int main(void)
{
    // an array is a contiguously allocated sequence of objects that all
    // have the same element type. array types are characterized by their 
    // element types and the number of elements in the array. This means that
    // a variable of type "array of 10 integers" has both a size 
    // (10 * sizeof(int)) and an address, just like any other object.
    
    int a[10];
    int b[10] = { 0 };
    int c[10] = { 1, 2, 3, };
    int d[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int e[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // extra elements are ignored
    int f[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // size is 13 (inferred from initializer)

    // array indexing uses [ ]
    // for a valid array object, a[i] is equivalent to * (a + i) when i 
    // is in the range 0 <= i < n (where n is the number of elements).

    // why is '\0' necessary?
    // c has no built-in way to know how long a string is. instead, it keeps 
    // reading characters until it finds '\0' (the null character).
    // without the terminating null character, it would continue reading random 
    // memory until it accidentally encountered a zero byte, resulting in 
    // undefined behavior.

    char str[11];
    // str is automatically converted to a pointer to the first member of the 
    // array. this is called array-to-pointer decay.
    // the array lives in memory like
    /*
        1000  '0'
        1001  '1'
        1002  '2'
        1003  '3'
        ...
        1010  '\0'
    */
    // whenever you write str in most expressions, it automatically becomes 
    // &str[0] or pointer to address 1000; So str really means 1000 

    // str[i] is identical to *(str + i)
    // str = address 1000 then str + 0. is 1000
    // dereference it *(1000) gives '0' exactly same as str[0]
    // str + 3 = address 1003
    // dereference it *(1003) gives '3' exactly same as str[3]
    // this is why str is called a "pointer to char" 

    // why does str + i move one character?
    // because str is a pointer to char (char *), so when you add i to it,
    // the compiler knows that sizeof(char) is 1, so it moves i * 1 bytes from 
    // the current address.
    // pointer arithmetic uses the size of the pointed-to type. char = 1 byte
    // so,
    // str + 1 moves 1 byte 1000 -> 1001
    // str + 5 moves 5 bytes 1000 -> 1005
    // str + i moves i * sizeof(char) bytes from the current address
    // on 64-bit system int = 4 bytes then int * ptr; ptr + 1 = 4 bytes from ptr
    // ptr = 1000; ptr + 1 = 1004
    // ptr = 1000; ptr + 2 = 1008

    char s[] = "abc";
    // s is an array of 4 characters: 'a', 'b', 'c', and '\0'.
    // s decays to a pointer to 'a' in expressions like &s[0] or s
    // &s[0] is address of first element ('a') which is same as str
    // s is address of first element ('a') which is same as str
    // str[i] is exactly the same as *(str + i).
    // &str[i] is exactly the same as str + i.
}
