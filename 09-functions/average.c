#include <stdio.h>

double average(double a, double b) {
  return (a + b) / 2;
}

int main() {

  // The effect of the call average (x, y) is to copy the values of x and y
  // into the parameters a and b, and then execute the body of average.
  //   printf("%g\n", average(10.5, 20.5));

  double x, y, z;

  printf("Enter three numbers: ");
  scanf("%lf %lf %lf", &x, &y, &z);

  printf("Avergae of %f and %f is %f\n", x, y, average(x, y));
  printf("Average of %f and %f is %f\n", y, z, average(y, z));
  printf("Average of %f and %f is %f\n", x, z, average(x, z));

  return 0;
}