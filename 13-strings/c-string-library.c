#include <stddef.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    // some programming languages provide operators that can copy strings, 
    // compare strings, concatenate strings, select substrings, and the like. 
    // C's operators, in contrast, are essentially useless for working with 
    // strings. strings are treated as arrays in C, so they're restricted in 
    // the same ways as arrays - in particular, they can't be copied or 
    // compared using operators.

    // direct attempts to copy or compare strings will fail.
    char str1[10], str2[10];
    // copying a string into a character array using the = operator is not 
    // possible:
    // str1 = "abc"; /* WRONG */
    // str2 = str1; /* WRONG */
    // using an array name as the left operand of = is illegal, initializing a 
    // character array using = is legal, though:
    char str3[10] = "abc";

    // attempting to compare strings using a relational or equality operator is 
    // legal but won't produce the desired result:
    // if (str1 == str2) /* WRONG */
    // this statement compares str1 and str2 as pointers; it doesn't compare 
    // the contents of the two arrays. since str1 and str2 have different 
    // addresses, the expression str1 == str2 must have the value 0.
 
    // most of the functions declared in <string.h> require at least one string 
    // as an argument. string parameters are declared to have type char *, 
    // allowing the argument to be a character array, a variable of type 
    // char *, or a string literal - all suitable as strings. 
    // watch out for string parameters that aren't declared const, however, 
    // such a parameter may be modified when the function is called, so the 
    // corresponding argument shouldn't be a string literal.


    // The strcpy (String Copy) Function
    
    strcpy(str2, "abc");
    strcpy(str1, str2);
    // Most of the time, we'll discard the value that strcpy returns. on 
    // occasion, though, it can be useful to call strcpy as part of a 
    // larger expression in order to use its return value. For example, we 
    // could chain together a series of strcpy calls:
    strcpy(str1, strcpy(str2, "abcd"));

    // in the call strcpy(str1, str2), strcpy has no way to check that the 
    // string pointed to by str2 will actually fit in the array pointed to by 
    // str1. suppose that str1 points to an array of length n. if the string 
    // that str2 points to has no more than n - 1 characters, then the copy 
    // will succeed. but if str2 points to a longer string, undefined behavior 
    // occurs. (since strcpy always copies up to the first null character, it 
    // will continue copying, it will continue past the end of the array that str1 points to.)
    
    // calling strncpy function is a safer, albeit slower, way to copy string. 
    // strncpy is similar to strcpy but has a third argument that limits the 
    // number of characters that will be copied.
    strncpy(str1, str2, sizeof(str1));
    // as long as str1 is large enough to hold the string stored in str2 
    // (including the null character), the copy will be done correctly. 
    // strncpy itself isn't without danger. for one thing, it will leave the 
    // string in str1 without a terminating null character if the length of the 
    // string stored in str2 is greater than or equal to the size of the str1 
    // array. here's a safer way to use strncpy:
    strncpy(str1, str2, sizeof(str1) - 1);
    str1[sizeof(str1) - 1] = '\0';
    // the second statement guarantees that str1 is always null-terminated, 
    // even if strncpy fails to copy a null character from str2.


    // The strlen (String Length) Function

    // size_t strlen(const char *s);
    // size_t, which is defined in the C library, is a typedef name that
    // represents one of C's unsigned integer types. unless we're dealing with 
    // extremely long strings, this technically need not concern us - we can 
    // simply treat the return value of strlen as an integer.
    // strlen returns the length of a string s: the number of characters in 
    // s up to, but not including, the first null character.
    int len;
    len = strlen("abc"); /* len is now 3 */
    len = strlen(""); /* len is now 0 */
    strcpy(str1, "abc");
    len = strlen(str1); /* len is now 3 */
    // the last example illustrates an important point. when given an array as 
    // its argument, strlen doesn't measure the length of the array itself; 
    // instead, it returns the length of the string stored in the array.


    // The strcat (String Concatenation) Function

    // the strcat function has the following prototype:
    // char *strcat(char *s1, const char *s2);
    // strcat appends the contents of the string s2 to the end of the string 
    // s1; it returns s1 (a pointer to the resulting string).
    strcpy(str1, "abc");
    strcat(str1, "def"); /* str1 now contains "abcdef", followed by 
    a null character */ 
    strcpy(str1, "abc");
    strcpy(str2, "def");
    strcat(str1, str2); /* str1 now contains "abcdef", followed by 
    a null character */
    
    // as with strcpy, the value returned by strcat is normally discarded. the 
    // following example shows how the return value might be used:
    strcpy(str1, "abc");
    strcpy(str2, "def");
    strcat(str1, strcat(str2, "ghi")); /* str1 now contains "abcdefghi", str2 contains "defghi" */
    
    // like strcpy, strcat has no way to determine if the array that str1 
    // points to is large enough to hold the concatenated string. as a result, 
    // calling strcat with an str1 that's too small will trigger undefined 
    // behavior.
    // the effect of the call strcat(str1, str2) is undefined if the array 
    // pointed to by str1 isn't long enough to accomodate the additional 
    // characters from str2. 
    char str4[6] = "abc";
    strcat(str4, "def"); /* WRONG */
    // strcat will attempt to add d,e,f, and '\0' to the end of the string
    // already stored in str4. unfortunately, str1 is limited to six characters,
    // causing strcat to write past the end of the array.

    // the strncat function is a safer but slower version of strcat. like 
    // strncpy, it has a third argument that limits the number of characters it 
    // will copy.
    strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
    // strncat will terminate str1 with a null character, which isn't included 
    // in the third argument (the number of characters to be copied). In the 
    // example, the third argument calculates the amount of space remaining in 
    // str1 (given by the expression sizeof(str1) - strlen(str1)) and then 
    // subtracts 1 to ensure that there will be room for the null character.

    
    // The strcmp (String Comparison) Function
    // the strcmp function has the following prototype:
    // int strcmp(const char *s1, const char *s2);
    // strcmp compares the strings s1 andd s2, return a value less than, equal 
    // to, or greater than 0, depending on whether s1 is less than, equal to, 
    // or greater than s2.
    // for example, to see if str1 is less than str2, we'd write
    if (strcmp(str1, str2) < 0) { // is str1 < str2?
        printf("str1 is lexicographically smaller than str2\n");
    }

    // by choosing the proper relational operator (<,<=,>,>=) or equality 
    // operator (==, !=), we can test any possible relationship between str1 
    // and str2.
    
    // strcmp compares strings based on their lexicographic ordering, which 
    // resembles the way words are arranged in a dictionary. more precisely, 
    // strcmp considers s1 to be less than s2 if either one of the following 
    // conditions is satisfied:
    // - the first i characters of s1 and s2 match, but the (i+1)st character 
    // of s1 is less than (i+1)st character of s2. for example, "abc" is less 
    // than "bcd", and "abd" is less than "abe".
    // - all characters of s1 match s2, but s1 is shorter than s2. for example,
    // "abc" is less than "abcd".
    // some knowledge of the underlying character set is helpful in order to 
    // predict what strcmp will do. for example, here are a few important 
    // properties of the ASCII character set:
    // - the characters in each of the sequence A-Z, a-z, and 0-9 have 
    // consecutive codes
    /// - all upper-case letters are less than all lower-case letters. 
    // (in ASCII, codes between 65 and 90 represent upper-case letters; codes 
    // between 97 and 122 represent lower-case letters.)
    // - digits are less than letters. (codes between 48 and 57 represent 
    // digits.)
    // - spaces are less than all printing characters. (the space character has 
    // the value 32 in ASCII)

}
