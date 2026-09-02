#include<stdio.h>

int main(void) {
    printf("sizeof(short)     =%zu bytes\n", sizeof(short));
    printf("sizeof(int)       =%zu bytes\n", sizeof(int));
    printf("sizeof(long)      =%zu bytes\n", sizeof(long));
    printf("sizeof(long long) =%zu bytes\n", sizeof(long long));
    printf("sizeof(float)     =%zu bytes\n", sizeof(float));
    printf("sizeof(double)    =%zu bytes\n", sizeof(double));
    printf("sizeof(char)      =%zu bytes\n", sizeof(char));
    return 0;
}