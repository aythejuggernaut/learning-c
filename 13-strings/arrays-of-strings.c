#include <stdio.h>

int main(void)
{
    // what's the best way to store an array of strings? the obvious solution 
    // is to create a two-dimensional array of characters, then store the 
    // strings in the array, one per row.

    char planets[][8] = {
        "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus",
        "Neptune", "Pluto"
    };
    // note that we're allowed to omit the number of rows in the planets 
    // array––since that's obvious from the number of elments in the 
    // initializer––but C requires that we specify the number of columns.
    // not all our strings were long enough to fill an entire row of the array, 
    // so C padded them with null characters. There's a bit of wasted space in 
    // this array, since only three planets have names long enough to require 
    // eight characters (including the terminating null character).
//        0    1    2    3    4    5    6    7 
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    0 │ M  │ e  │ r  │ c  │ u  │ r  │ y  │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    1 │ V  │ e  │ n  │ u  │ s  │ \0 │ \0 │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    2 │ E  │ a  │ r  │ t  │ h  │ \0 │ \0 │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    3 │ M  │ a  │ r  │ s  │ \0 │ \0 │ \0 │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    4 │ J  │ u  │ p  │ i  │ t  │ e  │ r  │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    5 │ S  │ a  │ t  │ u  │ r  │ n  │ \0 │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    6 │ U  │ r  │ a  │ n  │ u  │ s  │ \0 │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    7 │ N  │ e  │ p  │ t  │ u  │ n  │ e  │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    8 │ P  │ l  │ u  │ t  │ o  │ \0 │ \0 │ \0 │
//      └────┴────┴────┴────┴────┴────┴────┴────┘

    // the inefficiency that's apparent in these examples is common when 
    // working with strings, since most collections of strings will have a 
    // mixture of long strings and short strings. when we need is a ragged 
    // array: a two dimensional whose rows can have different lengths. C 
    // doesn't provide a "ragged array type," but it does give us the tools 
    // to simulate one. the secret is to create an array wholes elements are 
    // pointers to strings.
    char *planets1[] = {
        "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus",
        "Neptune", "Pluto"
    };
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    0 │    │-> │ M  │ e  │ r  │ c  │ u  │ r  │ y  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┐
//    1 │    │-> │ V  │ e  │ n  │ u  │ s  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┐
//    2 │    │-> │ E  │ a  │ r  │ t  │ h  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┐
//    3 │    │-> │ M  │ a  │ r  │ s  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    4 │    │-> │ J  │ u  │ p  │ i  │ t  │ e  │ r  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┬────┐
//    5 │    │-> │ S  │ a  │ t  │ u  │ r  │ n  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┬────┐
//    6 │    │-> │ U  │ r  │ a  │ n  │ u  │ s  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┬────┬────┐
//    7 │    │-> │ N  │ e  │ p  │ t  │ u  │ n  │ e  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┴────┴────┘
//      ┌────┐   ┌────┬────┬────┬────┬────┬────┐
//    8 │    │-> │ P  │ l  │ u  │ t  │ o  │ \0 │
//      └────┘   └────┴────┴────┴────┴────┴────┘

    // each element of planets is a pointer to a null-terminated string.
    // there are no longer any wasted characters in the strings, although 
    // we've had to allocate space for the pointers in the planets array.
    // to access one of the planet names, all we need to do is subscript the 
    // planets array. because of the relationship between pointers and arrays, 
    // accessing a character in a planet name is done in the same way as 
    // accessing an element of a two dimensional array.
    // To search the planets array for strings beginning with the 
    // letter M, for example, we could use the following loop:
    for (int i = 0; i < 9; i++) {
        if (planets[i][0] == 'M') {
            printf("%s begins with M\n", planets[i]);
        }
    }

    // Command-Line Arguments
    // Command-line information is available to all programs, not just 
    // operating system commands. To obtain access to these command-line 
    // arguments (called program parameters in the C standard), we must define 
    // main as a function with two parameters, which are customarily named 
    // argc and argv:
    // int main(int argc, char *argv[]){}

    // argc ("argument count") is the number of command-line argumentsv
    // (including the name of the program itself). argv ("argument vector") is 
    // an array of pointers to the command-line arguments, which are stored in 
    // string form. argv [0] points to the name of the program, while argv [1] 
    // through argv [argc-1] point to the remaining command-line arguments. 
    // argv has one additional element, argv [argel, which is always a null 
    // pointer—a special pointer that points to nothing. the macro NULL 
    // represents a null pointer.

    // if the user enters the command line
    // ls -l remind.c
    // then argc will be 3, argv[0] will point to a string containing the 
    // program name, argv[1] will point to the string "-l", and argv [2] will 
    // point to the string "remind.c", and argv[3] will be a null pointerr.
    // since argv is an array of pointers, accessing command-line arguments is 
    // easy. typically, a program that expects command-line arguments will set 
    // up a loop that examines each argument in turn. One way to write such a 
    // loop is to use an integer variable as an index into the argv array. 
    
    // for (int i = 0; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }

    // another technique is to set up a pointer to argv [1], then increment the 
    // pointer repeatedly to step through the rest of the array. since the last 
    // element of argv is always a null pointer, the loop can terminate when it 
    // finds a null pointer in the array:
    char **p;
    // for (p = &argv[1]; p != NULL; p++) {
    //     printf("%s\n", *p);
    // }
    // since p is a pointer to a pointer to a character, we've got to use it 
    // carefully. Setting p equal to sargv [1] makes sense; argv [1] is a 
    // pointer to a character, so &argv [1] will be a pointer to a pointer. The 
    // test *p ! = NULL is OK, since *p and NULL are both pointers. 
    // Incrementing p looks good; p points to an array element, so incrementing 
    // it will advance it to the next element. Printing *p is fine, since *p points to the first character in a string.
}
