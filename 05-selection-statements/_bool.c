#include <stdio.h>
#include <stdbool.h>

int main (void){
    bool is_admin = true;

    if (is_admin)
        printf("admin\n");
    else
        printf("not admin\n");
    
    return 0;
}
