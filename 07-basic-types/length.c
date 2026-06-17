#include <stdio.h>

int main(void) {
    char message;
    int i = 0;

    printf("Enter your message: ");
    do {
        message = getchar();
        i++;
    } while (message != '\n');

    printf("Your message was %d character(s) long.\n", i - 1);    
    
    return 0;
}

