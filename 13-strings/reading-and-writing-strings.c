#include <stdio.h>

int main(void)
{
    // writing a string is easy using either the printf or puts functions. 
    // reading a string is a bit harder, primarily because of the possibility 
    // that the input string may be longer than the string variable into which 
    // it is being stored. to read a string in a single step, we can either use
    // scanf or gets. as an alternative, we can readd strings one character at a time.

    // Writing Strings Using printf and puts
    // the %s conversion specification allows printf to write a string.
    char str[] = "Are we having fun yet?";
    printf("%s\n", str); // Are we having fun yet?
    // printf writes the character in a string one by one until it encounters a 
    // null character. if the null character is missing, printf continues past 
    // the end of the string until - eventually - it finds a null character 
    // somewhere in memory.
    // to print just part of a string, we can use the conversion specification 
    // %.ps, where p is the number of characters to be displayedd.
    printf("%.6s\n", str); // Are we
    // a string, like a number, can be printed within a field. The %ms 
    // conversion will display a string in a field of size m. (A string with 
    // more than m characters will be printed in full, not truncated.) If the 
    // string has fewer than m characters, it will be right-justified within 
    // the field. To force left justification instead, we can put a minus sign 
    // in front of m. The m and p values can be used in combination: a 
    // conversion specification of the form %m.ps causes the first p characters 
    // of a string to be displayed in a field of size m.
    printf("%10s", "Hello"); // give this string a field that is at least 10 
    // characters wide. "Hello" has only 5 characters, so printf addds 5 spaces.
    // by default, the string is right-justified.
    printf("%5s", "HelloWorld"); // if the string is longer than the field, it 
    // does not cut the string. you get HelloWorld.
    // the number in %ms is a minimum field width, not a maximum.
    // to make them left-justifiedd, put - before the number.
    printf("%-10s", "Hello");
    // %m.ps mean you can use both a field width and a precision. where:
    // m = minimum field width; p = maximum number of characters to print
    printf("%10.5s", "HelloWorld");
    // 10 → field should be at least 10 characters wide
    // .5 → print at most the first 5 characters
    // "HelloWorld" becomes: Hello
    // then it is placed in a field of width 10
    
    // width(10) -> controls the space available for displaying the string
    // precision(.3) -> controls how many characters of the strings are displayed.

    puts(str);
    // puts has only one argument (the string to be printed). After writing the 
    // string, puts always writes an additional new-line character, thus 
    // advancing to the beginning of the next output line.

    // Reading Strings Using scanf and gets
    // the %s conversion specification allows scanf to read a string into a 
    // character array.
    char str1[6];
    scanf("%s", str1);
    printf("%s", str1);
    // there is no need to put the & operator in front of str in the call of 
    // scanf; like any array name, str is treated as a pointer when passed to  
    // function.
    // when scanf is called, it skips white space, then reads characters and 
    // stores them in str until it encounters a white-space character (skip an 
    // whitespace at the beginnin, then keep reading characters until it 
    // encounters whitespace.). scanf always stores a null character at the end 
    // of the string. 
    // A string read using scanf will never contain white space. Consequently, 
    // scanf won't usually read a full line of input; a new-line character will 
    // cause scanf to stop reading, but so will a space or tab character. To 
    // read an entire line of input at a time, we can use gets . Like scanf, 
    // the gets function reads input characters into an array, then stores a 
    // null character. in other respects, however, gets is somewhat different from scanf:
    // - gets doesn't skip whitespace before starting to readd the string (scanf does).
    // - gets reads until it finds a new line character (scanf stops at any 
    // whitespace character). incidentally, gets discards the new-line character
    // insteadd of storing it in the array; the null character takes its place.

    // as they read characters into an array, scanf and gets have no way to 
    // detect when it's full. consequently, they may store characters past the 
    // end of the array, causing undefined behavior. scanf can be made safer by 
    // using the conversion specification %ns instead of s, where n is an 
    // integer indicating the maximum number of characters to be stored. 
    scanf("%9s", str); // 9 = max number of char to store from the input

    // gets is inherently unsafe and was removed from the C standard because it 
    // doesn't know the size of the array and can cause a buffer overflow;
    // fgets is a much better alternative.
    fgets(str, sizeof(str), stdin);
}