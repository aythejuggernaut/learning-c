#include <stdio.h>

int main(void) {
    int height = 8, length = 12, width = 10, volume;
    
    // scanf("%d", &height);
    // scanf("%d", &length);
    // scanf("%d", &width);
    volume = height * length * width;
    // weight = (volume + 165) / 166;

    printf("Dimensions: %d x %d x %d\n", height, length, width);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);
    // printf("Dimensional weight (pounds): %d\n", weight);
    return 0;
}

