#include <stdio.h>

// It's usually best not to omit parameter names, since they help document the 
// purpose of each parameter and remind the programmer of the order in which 
// arguments must appear when the function is called. However, there are 
// legitimate reasons for omitting parameter names, and some programmers prefer 
// to do so. C99 has adopted the rule that either a declaration or a definition 
// of a function must be present prior to any call of the function. Calling a 
// function for which the compiler has not yet seen a declaration or definition is an error.
double average(double a, double b);

int main() {
    // When the compiler encounters the first call of average in main, it has 
    // no information about average: it doesn't know how many parameters 
    // average has, what the types of these parameters are, or what kind of 
    // value average returns. Instead of producing an error message, though, 
    // the compiler assumes that average returns an int value.

    // We say that the compiler has created an implicit declaration of the 
    // function. The compiler is unable to check that we're passing
    // average the right number of arguments and that the arguments have the 
    // proper type. Instead, it performs the default argument promotions and 
    // hopes for the best. When it encounters the definition of average later 
    // in the program, the compiler notices that the function's return type is 
    // actually double, not int, and so we get an error message. 
    // One way to avoid the problem of call-before-definition is to arrange the 
    // program so that the definition of each function precedes all its calls. 
    // Unfortunately, such an arrangement doesn't always exist, and even when 
    // it does, it may make the program harder to understand by putting its 
    // function definitions in an unnatural order. Fortunately, C offers a 
    // better solution: declare each function before calling it. A function 
    // declaration provides the compiler with a brief glimpse at a function 
    // whose full definition will appear later. A function declaration 
    // resembles the first line of a function definition with a semicolon added at the end:

  double x, y, z;

  printf("Enter three numbers: ");
  scanf("%lf %lf %lf", &x, &y, &z);

  printf("Avergae of %f and %f is %f\n", x, y, average(x, y));
  printf("Average of %f and %f is %f\n", y, z, average(y, z));
  printf("Average of %f and %f is %f\n", x, z, average(x, z));

  return 0;
}

double average(double a, double b) {
  return (a + b) / 2;
}
