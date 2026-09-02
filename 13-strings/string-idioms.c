#include <stddef.h>
#include <stdio.h>

int main(void)
{
    // Searching for the End of a String
    // many string operations require searching for the end of a string. the 
    // strlen function is a prime example. the following version of strlen 
    // searches its string argument to find the end, using a variable to 
    // keep track of the string's length:
    // size_t strlen(const char *s)
    // {
    //     size_t n;
    //     for (n = 0; *s != '\0'; s++)
    //         n++;
    //     return n;
    // }

    // as the pointers moves across the string from left to right, the variable 
    // n keeps track of how many characters have been seen so far: When s 
    // finally points to a null character, n contains the length of the string.

    // size_t strlen(const char *s)
    // {
    //     size_t n = 0;
    //     for (; *s != '\0'; s++)
    //         n++;
    //     return n;
    // }

    // next, we notice that the condition *s != '\0' is the same as *s != 0, 
    // because the integer valuue of the null character is 0. but testing 
    // *s != 0 is the same as testing *;  both are true if *s isn't equal to 0.
    size_t strlen(const char *s)
    {
        size_t n = 0;
        for (; *s; s++)
            n++;
        return n;
    }

    // it's possible to increment s and test *s in the same expression:
    size_t strlen(const char *s)
    {
        size_t n = 0;
        for (; *s++ ;)
            n++;
        return n;
    }

    // replacing the for statement with a while statement:
    size_t strlen(const char *s)
    {
        size_t n = 0;
        while (*s++)
            n++;
        return n;
    }

    // although we've condensed strlen quite a bit, it's likely that we haven't
    // increased its speed. here's a version that does run faster, at least 
    // with some compilers:
    size_t strlen(const char *s)
    {
        const char *p = s;
        while (*s)
            s++;
        return s - p;
    }
    // this version of strlen computes the length of the string by locating the 
    // position of the null character, then subtracting from it the position of 
    // the first character in the string. The improvement in speed comes from 
    // not having to increment n inside the while loop. Note the appearance of 
    // the word const in the declaration of p. by the way; without it, the 
    // compiler would notice that assigning s to p places the string that s points to at risk.
    // the statement:
    // while (*s)
    //     s++;
    // and the related
    // while (*s++);
    // are idioms meaning "search for the null character at the end of a string"
    // the first version leaves s pointing to the null character. the second
    // version is more concise, but leaves s pointing just pass the null character.
    
    
    // on many machines, fetching the value of *s twice is slower than fetching 
    // the value once and storing it in a register:
    size_t strlen(const char *s)
    {
        const char *p = s;
        while (*s++)
            ;
        return s - p - 1;
    }
    // the loop simply advances p until it points to the character just after
    // the null terminator. the length of the string is the number of
    // characters p advanced - which is the difference between the final and
    // initial values of p.

    
    // Searching for a Character in a String.
    // another common string operation is searching for the first occurence of
    // a specified character.
    char *find(const char *s, int c)
    {
        while (*s != c)
            s++;
        return s;
    }
    // this function returns the address of the first occurrence of c in s, or
    // the address of the null terminator if c is not found.
    char *find(const char *s, int c)
    {
        while (*s++)
            ;
        return s;
    }
    // this version of find uses the same idiom as the final version of strlen.


    // Copying Strings.
    // another common string operation is to copy a string from one location 
    // in memory to another.
    void copy(char *dst, const char *src)
    {
        while (*dst++ = *src++)
            ;
    }
    // this function copies the characters from src to dst, including the null
    // terminator. the loop condition *

    // Copying a string is another common operation. To introduce C's "string 
    // copy" idiom, we'll develop two versions of the strcat function. 
    char *strcat(char *s1, const char *s2)
    {
        char *p = s1;
        while (*p != '\0')
            p++;
        while (*s2 != '\0') {
            *p = *s2;
            p++;
            s2++;
        }
        *p = '\0';
        return s1;
    }

    // this version of strcat uses a two-step algorithm: (1) Locate the null 
    // character at the end of the string s1 and make p point to it. (2) Copy 
    // characters one by one from s2 to where p is pointing. the first while 
    // statement in the function implements step (1). p is set to point to the 
    // first character in the s1 string. Assuming that s1 points to the string 
    // "abe". p is then incremented as long as it doesn't point to a null 
    // character. When the loop terminates, p must be pointing to the null 
    // character. The second while statement implements step (2). The loop body 
    // copies one character from where s 2 points to where p points, then 
    // increments both p and s2, If s2 originally points to the string "def",
    // The loop terminates when s2 points to the null character. After putting 
    // a null character where p is pointing, streat returns.

    // By a process similar to the one we used for strlen , we can condense the
    // definition of strcat, arriving at the following version:
    char *strcat(char *s1, const char *s2)
    {
        char *p = s1;
        while (*p)
            p++;
        while (*p++ = *s2++)
            ;
        return s1;
    }
    // The heart of our streamlined strcat function is the "string copy" idiom:
    // while (*p++ = *s2++)
    //     ;
    // If we ignore the two ++ operators, the expression inside the parentheses 
    // simplifies to an ordinary assignment:
    // *p = *s2;
    
    // this expression copies a character from where s2 points to where p 
    // points. After the assignment, both p and s2 are incremented, thanks to 
    // the ++ operators. Repeatedly executing this expression has the effect of 
    // copying a series of characters from where s 2 points to where p points. 
    // But what causes the loop to terminate? Since the primary operator inside 
    // the parentheses is assignment, the while statement tests the value of 
    // the assignment - the character that was copied. All characters except 
    // the null character test true, so the loop won't terminate until the null 
    // character has been copied. And since the loop terminates after the 
    // assignment, we don't need a separate statement to put a null character at the end of the new string.
}
