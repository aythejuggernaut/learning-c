#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("argc = %d\n", argc);

    if (argc != 3) {
        printf("usage: ./add 1 2 \n");
        return 1;
    }

    long result = 0;
    for (int i = 1; i < argc; i++) {
        result += strtol(argv[i], NULL, 10);
    }

    printf("Result = %ld\n", result);

    return 0;
}
