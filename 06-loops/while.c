#include <stdio.h>

int main(void) {
    int i = 6;
    // while (i > 0) {
    //     printf("T minus %d and counting\n", i);
    //     i--;
    // }
    // printf("Blastoff!\n");

    // More concise syntax
    while (i > 0) printf("T minus %d and counting\n", i--);
    printf("Blastoff!\n");

    return 0;
}

