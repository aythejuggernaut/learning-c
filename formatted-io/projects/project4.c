#include <stdio.h>

int main(void) {
    int first_part, second_part, third_part;
    
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &first_part, &second_part, &third_part);
    printf("%d.%d.%d\n", first_part, second_part, third_part);
    
    return 0;
}
