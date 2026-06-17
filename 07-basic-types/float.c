#include <stdio.h>

int main(void) {
    // the conversion specifications %e, %f, and %g are used for
    // reading and writing single-precision floating-point numbers.
    // Values of types double and long double require slightly different conversions: When reading a value of type double, put the letter l in front of e, f, or g:

    double d;
    scanf("%lf", &d);
    printf("You entered: %lf\n", d);

    // Note: Use l only in a scanf format string, not a printf string.
    // In a printf format string, the e, f, and g conversions can be used
    // to write either fl o a t or double values.
    // (C99 legalizes the use of &le, %1f, and &1g in calls of printf , 
    // although the 1 has no effect.)

    // When reading or writing a value of type l o n g double, put the letter L in front of e, f, or g:

    long double ld;
    scanf("%Lf", &ld);
    printf("You entered: %Lf\n", ld);
    
    return 0;
}