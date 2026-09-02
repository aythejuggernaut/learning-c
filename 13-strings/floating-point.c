#include<stdio.h>
#include<math.h>/* for fabs() */
#include<float.h>

int main(void) {
    /* Demonstrate that 0.1 + 0.2 != 0.3 */
    double a = 0.1, b = 0.2, c = 0.3;
    double sum = a + b;

    printf("0.1 + 0.2 =%.20f\n", sum);
    printf("0.3       =%.20f\n", c);
    printf("Equal (==):%s\n", (sum == c) ? "YES" : "NO");
    printf("Equal (tolerance):%s\n", (fabs(sum - c) < 1e-10) ? "YES" : "NO");

    /* Float vs double precision */
    float  f = 1.0f / 3.0f;
    double d = 1.0  / 3.0;
    printf("\n1/3 as float:%.20f\n", (double)f);
    printf("1/3 as double:%.20f\n", d);

    /* Integer conversion truncates, not rounds */
    printf("\n(int)3.9  =%d\n", (int)3.9);
    printf("(int)-3.9 =%d\n", (int)-3.9);
    printf("(int)3.1  =%d\n", (int)3.1);

    return 0;
}