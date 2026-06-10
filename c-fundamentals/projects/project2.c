#include <stdio.h>

#define FRACTION (4.0f / 3.0f)
#define PI 3.142

int main (void) {
    float volume;
    volume = FRACTION * PI * (10 * 10 * 10);

    printf("Result: %f\n", volume);
}

