#include <stdio.h>

// suppose we need a function that doesn't skip white-space characters, stops 
// reading at the first new-line character (which isn't stored in the string), 
// and discards extra characters. The function might have the following 
// prototype:
int read_line(char str[], int n);

int main(void)
{
    // Reading Strings Character by Character
    // since both scanf and gets are risky and insufficiently flexible for 
    // many applications, C programmers often write their own input functions.
    // By reading strings one character at a time, these functions provide a 
    // greater degree of control than the standard input functions.
    // if we decide to design our own input, we'll need to consider the following issues:
    // - shouldd the function skip whitespace before beginning to store the string?
    // - what character causes the function to stop reading: a new-line 
    // character, any white-space character, or some other character? Is this 
    // character stored in the string or discarded? 
    // - what should the function do if the input string is too long to store: 
    // discard the extra characters or leave them for the next input operation?

    // str represents the array into which we'll store the input, and n is the 
    // maximum number of characters to be read. If the input line contains more 
    // than n characters, readline will discard the additional characters. 
    // we'll have readline return the number of characters it actually stores 
    // in str (a number anywhere from 0 to n). We may not always need 
    // read_line's return value, but it doesn't hurt to have it available. 
    // read_line consists primarily of a loop that calls getchar to read 
    // a character and then stores the character in str, provided that 
    // there's room left. The loop terminates when the new-line character is 
    // read. (Strictly speaking, we should also have the loop terminate if 
    // getchar should fail to read a character, but we'll ignore that complication for now.)


    // note that ch has int type rather than char type, because getchar returns 
    // the character that it reads as an int value.

    // before returning, readline puts a null character at the end of the 
    // string. standard functions such as s c a n and g e t s automatically put 
    // a null character at the end of an input string; if we're writing our own 
    // input function, however, we must take on that responsibility.
}

// here's the complete definition of read_line:
int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    
    str[i] = '\0'; /* terminates string */
    
    return i; /* number of characters stored */
}