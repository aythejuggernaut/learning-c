#include <stdio.h>

int main (void){
    char grade;
    printf("Enter grade: ");
    scanf("%c", &grade);

    switch (grade){
        case 'A': case 'a':
            printf("Excellent\n");
            break;
        case 'B': 
        case 'b':
            printf("Good\n");
            break;
        case 'C':
            printf("Average\n");
            break;
        case 'D':
            printf("Poor\n");
            break;
        case 'F':
            printf("Fail\n");
            break;
        default:
            printf("Invalid grade\n");
    }

    return 0;
}