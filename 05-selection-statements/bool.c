#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define BOOL int

int main (void){
    BOOL is_completed;
    is_completed = TRUE;

    if (is_completed)
        printf("completed\n");
    else 
        printf("Not completed\n");

    return 0;
}

