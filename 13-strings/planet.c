#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    // Our next program, planet.c, illustrates how to access 
    // command-line arguments. The program is designed to check a series of 
    // strings to see which ones are names of planets. When the program is run, 
    // the user will put the strings to be tested on the command line:
    //
    // $ planet Jupiter venus Earth fred

    // The program will indicate whether or not each string is a planet name; 
    // if it is, the program will also display the planet's number (with planet 
    // 1 being the one closest to the Sun).
    //
    // $ planet Jupiter venus Earth fred
    // Jupiter is planet 5
    // venus is not a planet
    // Earth is planet 3
    // fred is not a planet

    // Notice that the program doesn't recognize a string as a planet name 
    // unless its first letter is upper-case and its remaining letters are 
    // lower-case.

    // Array of planet names.
    char *planets[] = {
        "Mercury", "Venus", "Earth", "Mars", 
        "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"
    };

    int i, j;

    // Loop through each command-line argument.
    for (i = 1; i < argc; i++) {
        // Loop through each planet in the array.
        for (j = 0; j < NUM_PLANETS; j++) {
            // If the command-line argument matches a planet name, print it and break the inner loop.
            if (strcmp(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }

        // If the inner loop completes without finding a match, the value of j 
        // will be equal to NUM_PLANETS. We can use this fact to determine if 
        // the string is a planet name.
        if (j == NUM_PLANETS) {
            printf("%s is not a planet\n", argv[i]);
        }
    }

    // The program visits each command-line argument in turn, comparing it with 
    // the strings in the planets array until it finds a match or reaches 
    // the end of the array. The most interesting part of the program is the 
    // call of strcmp, in which the arguments are argv[i] (a pointer to a 
    // command-line argument) and planets[j] (a pointer to a planet name).

    // The strcmp function compares two strings. It returns 0 if the 
    // strings are identical, a negative value if the first string is 
    // lexicographically smaller than the second, and a positive value if 
    // the first string is lexicographically larger than the second.

    return 0;
}