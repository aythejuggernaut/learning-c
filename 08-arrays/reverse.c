#include <stdio.h>

#define N 10

int main (void) {
    /* 
     * This program shows just how useful macros can be in conjunction with
     * arrays. The macro N is used four times in the program: in the
     * declaration of a, in the print that displays a prompt, and in both for
     * loops. Should we later decide to change the size of the array, we need
     * only edit the definition of N and recompile the program. Nothing else
     * will need to be altered; even the prompt will still be correct.
     */
    int a[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("In reverse order:");
    for (int i = N - 1; i >= 0; i--)
        printf(" %d ", a[i]);

    printf("\n");

    return 0;
}

