#include <stdio.h>

int count_spaces(const char s[]);
int count_spaces_ptr(const char *s);

int main(void)
{
    // we included const in the declaration of s to indicate that count_spaces 
    // doesn't change the array that s represents. If s were not a string, the 
    // function would need a second argument specifying the length of the 
    // array. Since s is a string, however, count_spaces can determine where it 
    // ends by testing for the null character. 
    // many C programmers wouldn't write count_spaces as we have. Instead. 
    // they'd use a pointer to keep track of the current position within the 
    // string. this technique is always available for processing arrays, but it 
    // proves to be especially convenient for working with strings.

    // note that const doesn't prevent count_spaces from modifying s; it's 
    // there to prevent the function from modifying what s points to. and since 
    // s is a copy of the pointer that's being passed, incrementing s doesn't 
    // affect the original pointerr.

    // the count_spaces examples raises some questions about how to write string
    // function:
    // - is it better to use array operations or pointer operations to access 
    // the characters in a string? we're free to use whichever is mor 
    // convenient; we can even mix the two. in count_spaces_ptr, treating s as 
    // a pointer simplifies the function slightly by removing the need for the 
    // variable i. traditionally, C programmers lean towards using pointer 
    // operations for processing strings.
    
    // - should a string parameter be declared as an array or as a pointer? the 
    // two versions of count_spaces illustrate the options: the count_spaces 
    // declares s to be an array; count_spaces_ptr declares s to be a pointer. 
    // actually, there's no difference between the two declarations, the 
    // compiler treats an array parameter as though it had been declared as a pointer.

    // - does the form of the parameter (s[] or *s) affect what can be supplied 
    // as an argument? No. when count_spaces or count_spaces_ptr is called, the 
    // argument could be an array name, a pointer variable, or a string literal,
    // the function can't tell the difference.
}

int count_spaces(const char s[])
{
    int count = 0, i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
            count++;

    return count;
}

int count_spaces_ptr(const char *s)
{
    int count = 0;
    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;

    return count;
}