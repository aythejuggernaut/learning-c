#include <stdio.h>

#define N 10

int main(void)
{
    int a[N], *p;
    printf("Enter %d dnumbers: ", N);
    
    for (p = a; p < a + N; p++)
        scanf("%d", p);

    printf("In reverse order:");
    for (p = a + N - 1; p >= a; p--)
        printf(" %d", *p);

    printf("\n");

    // in the original program, an integer variable i kept track of the current 
    // position within the array. the new version replaces i with p, a pointer 
    // variable. the numbers are still stored in an array; we're simply using a 
    // different technique to keep track of where we are in the array.
    // note that the second argument to scanf is p, not &p, since p points to 
    // an array element, it's a satisfactory argument for scanf; &p, on the 
    // other hand, would be a pointer to a pointer to an array element.

    return 0;
}
