#include <stdio.h>

#define ARRAY_SIZE(a) ((int) (sizeof(a) / sizeof(a[0])))

int main (void) {
    int a[10];

    printf("Enter %d numbers: ", ARRAY_SIZE(a));
    for (int i = 0; i < ARRAY_SIZE(a); i++) {
        scanf("%d", &a[i]);
    }
    
    printf("In reverse order:");
    for (int i = ARRAY_SIZE(a) - 1; i >= 0; i--)
        printf(" %d ", a[i]);

    printf("\n");

    return 0;
}
