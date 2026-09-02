#include <stdio.h>

#define STR_LEN 80

int main(void)
{
    // some programming languages provide a special string type for declaring 
    // string variables. C takes a different tack: any one-dimensional array of 
    // characters can be used to store a string, with the understanding that 
    // the string is terminated by a null characterr. this approach is simple, 
    // but has significant difficulties. it's sometimes hard to tell whether an 
    // array of characters is being used as a string. if we write our own 
    // string-handling functions, we've got to be careful that they deal
    // properly with the null character. also, there's no faster way to 
    // determine the length of a string than a character-by-character search 
    // for the null character.
    
    // let's say that we need a variable capable of storing a string of up to 
    // 80 characters. since the string will need a null character at the end, 
    // we'll declare the variable to be an array of 81 characters:
    char str[STR_LEN];
    // we defined STR_LEN to be 80 rather than 81, thus emphasizing the fact 
    // that str can store strings of no more than 80 characters, and then added 
    // 1 to STR_LEN in the declaration of str. this a common practice among C programmers.

    // note: when declaring an array of characters that will be used to hold a 
    // string, always make the array one character longer than the string, 
    // because of the C convention that every string is terminated by a null 
    // character. failing to leave room for the null character may cause 
    // unpredictable results when the program is executed, since functions in 
    // the C library assume that strings are null-terminated.

    // declaring a character array to have length STR_LEN + 1 doesn't mean that 
    // it will always contain a string of STR_EN characters. The length of a 
    // string depends on the position of the terminating null character, not on 
    // the length of the array in which the string is stored. An array of 
    // STR_LEN + 1 characters can hold strings of various lengths, ranging from 
    // the empty string to strings of length STR_LEN.

    // Initializing a String Variable
    // a string variable can be initialized at the same time it's declared:
    char date1[8] = "June 14";
    // the compiler will put the characters from "June 14" in the date1 array, 
    // then add a null character so that date1 can be used as a string. 

    // although "June 14" appears to be a string literal, it's not. instead, C 
    // views it as an abbreviation for an array initializer. in fact, we could 
    // have written:
    char date2[8] = {'J', 'u', 'n', 'e', ' ', '1', '4', '\0'};
    // if the initializer is too short to fill the string variable, in that 
    // case, the compiler adds extra null characters. 
    char date3[9] = "June 14"; // {'J', 'u', 'n', 'e', ' ', '1', '4', '\0', '\0};
    // this behavior is consistent with C's treatment of array initializers in 
    // general. when an array initializer is shorter than the array itself, the 
    // remaining elements are initialized to zero. by initializing the leftover 
    // elements of a character array to \0, the compiler is following the same 
    // rule.

    // if the initializer is longer than the string variable, that's illegal 
    // for strings, just as it's illegal for other arrays. however, C does 
    // allow the initializer (not counting the null character) to have exactly 
    // the same length as the variable:
    char date4[7] = "June 14";
    // there's no room for the null character, so the compiler makes no attenpt 
    // to store one. 
    // note: if you're planning to initialize a character array to contain a 
    // string, be sure that the length of the array is longer than the length 
    // of the initializer. otherwise, the compiler will quietly omit the null 
    // character, making the array unusable as a string.

    // the declaration of a string variable may omit its length, in which cash 
    // the compiler computes it:
    char date5[] = "June 14";
    // the compiler sets aside eight characters for date5, enough to store the 
    // characters in "June 14" plus a null character. (the fact that the length 
    // of date5 isn't specified doesn't mean that the array's length be changed
    // later. once the program is compiled, the length is fixed at eight.)
    // omitting the length of a string variable is especially useful if the 
    // initializer is long, since computing the length by hand is error prone.

    // Character Arrays versus Character Pointers
    char datee[] = "June 14";
    char *datee1 = "June 14";
    // thanks to the close relationship between arrays and pointers, we can use 
    // either version of datee or datee1 as a string. in particular any 
    // function expecting to be passed a character array or character pointer 
    // wil accept either version of datee orr datee1 as an argument. 
    // however, we must be careful not to make the mistake of thinking that the 
    // two versions of datee or datee1 are interchangeable. There are 
    // significant differences between the two:
    // 1. in the array version, the characters stored in datee can be modified, 
    // like the elements of any array. in the pointer version, datee1 points to 
    // a string literal, string literals shouldn't be modified.
    // 2. in the array version, datee is an array name. in the pointer version, 
    // datee1 is a variable that can be made to point to other strings during 
    // program execution.
    // if we need a string that can be modified, it's our responsibility to set 
    // up an array of characters in which to store the string; declaring a 
    // pointer variable isn't enough. the declaration
    char *p;
    // causes the compiler to set aside enough memory for a pointer variable; 
    // unfortunately, it doesn't allocate space for a string. (and how could 
    // it? we haven't indicated how long the string would be.) before we can 
    // use p as a string, it must point to an array of characters. one 
    // possibility is to make p point to a string variable:
    char str1[STR_LEN], *q;
    q = str1;
    // q now points to the first character of str, so we can use p as a string. 
    // another possibility is to make p point to a dynamically allocated string.


    // using an uninitialized pointer variable as a string is a serious error.
    // consider the following example, which attempts to build the string "abc":
    char *r;
    r[0] = 'a'; /* WRONG */
    r[1] = 'b'; /* WRONG */
    r[2] = 'c'; /* WRONG */
    r[3] = '\0'; /* WRONG */
}