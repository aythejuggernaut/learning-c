#include <stdio.h>

#define FRACTION (4.0f / 3.0f)
#define PI 3.142

int main (void) {
    float volume, radius;
    printf("Enter radius: ");
    scanf("%f", &radius);
    volume = FRACTION * PI * (radius * radius * radius);

    printf("Result: %f\n", volume);
}

