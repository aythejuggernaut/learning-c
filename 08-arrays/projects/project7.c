#include <stdio.h>

#define ROWS 5
#define COLS 5

int main(void) {
    int arr[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Row totals: ");
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            count += arr[i][j];
        }
        printf("%d ", count);
    }
    printf("\n");

    printf("Column totals: ");
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            count += arr[i][j];
        }
        printf("%d ", count);
    }
    printf("\n");
    

    return 0;
}

