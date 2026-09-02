#include <stdio.h>

int main() {
    // a string literal is a sequence of characters enclosed within double quotes.
    // char *s = "Hello, World!";
    // printf("%s\n", s);

    // if we find that a string literal is too long to fit conveniently on a 
    // single line, C allows us to continue it on the next line, provided that 
    // we end the first line with a backslash character (\). No other 
    // characters may follow \ on the same line, other than the (invisible) 
    // new-line character at the end: 
    printf("When you come to a fork in the road, take it. \
        --Yogi Berra\n");
    // In general, the \ character can be used to join two or more lines of a 
    // program into a single line (a process that the C standard refers to as 
    // "splicing")
    // the \ technique has one drawback: the string must continue at the 
    // beginning of the next line, thereby wrecking the program's indented 
    // structure. There's a better way to deal with long string literals, 
    // thanks to the following rule: when two or more string literals are 
    // adjacent (separated only by white space), the compiler will join them 
    // into a single string. This rule allows us to split a string literal over 
    // two or more lines:
    printf("When you come to a fork in the road, take it."
        "--Yogi Berra\n");
    printf("It is a truth universally acknowledged, that a single man in\n"
           "possession of a good fortune, must be in want of a wife.\n"
           "\t--Pride and Prejudice");

    // How String Literals Are Stored
    // C treats string literals as character arrays. when a C compilers
    // encounters a string literal of length n in a program, it sets aside 
    // n + 1 bytes of memory for the string. this area of memory will contain 
    // the characters in the string, plus one extra character - the null 
    // character (\0) - to mark the end of the string. the null character is a 
    // byte whose bits are all zero, so it's represented by the \0 escape 
    // sequence.

    // don't confuse the null character ('\0') with the zero character 
    // ('0'). The null character has the code 0; the zero character has a 
    // different code (48 in ASCII).

    // for example, the string literal "abc" is stored as an array of four 
    // characters: 'a', 'b', 'c' and '\0'. string literals may be empty: the 
    // string "" is stored as a single null character/one-character array containing only '\0'.
    
    // since a string literal is stored as an array, the compiler treats it a 
    // a pointer of type char *. both printf and scanf, for example, expect a 
    // value of type char * as their first argument. consider the following example:
    printf("abc");
    // when printf is called, it's passed the address of "abc" (a pointer to 
    // where the letter a is stored in memory). printf then prints characters 
    // one by one until it encounters a null character.

    // Operations on String Literals
    // in general, we can use a string literal wherever C allows a char * 
    // pointer. for example, a string literal can appear on the right side of 
    // an assignment:
    char *p;
    p = "abc";

    // this assignment doesn't copy the characterrs in "abc"; it merely makes p 
    // point to the first character of the string. C allows pointers to be 
    // subscripter, so we can subscript string literals:
    char ch;
    ch = "abc"[1];

    // attempting to modify a string literal causes undefined behavior:
    // *p = "d"; /* WRONG */ 
    // a program that tries to change a string literal may crash or behave erratically.
    
    // String Literals versus Character Constants
    // a string literal containing a single character isn't the same as a 
    // character constant. the string literal "a" is represented by a pointer 
    // to a memory location that contains the character a (followed by a null 
    // characterr). the character constant 'a' is represented by an integer 
    // (the numerical code for the character.
    
    // character constant => 
    char d = 'A'; // written in single quotes
    // 'A' represent the character A. in C, a character constant actually has 
    // type int (although it is commonly assigned to a char).
    printf("%c", 'A'); // A -> %c is for a character 

    // string literal =>
    char str[] = "A"; // written in double quotes
    // it represents a string containing A followed by a null character 'A' '\0'
    // so "A" needs space for 2 characters when stored as an array.
    printf("%s", "A"); // A -> %s is for a null-terminated string.

    // don't ever use a character when a string is required (or vice versa), the call
    printf("\n");
    // is legal, because printf expects a pointer as its first argument. the following call isn't legal, however:
    printf('\n'); /* WRONG */
    
    return 0;
}