#include <stdio.h>

#define MAX_LINES 5

int main(void) {
    int line_num = MAX_LINES + 1;

    if (line_num <= MAX_LINES) printf("Line number: %d\n", line_num);
    else printf("Max lines reached\n");

    return 0;
}

