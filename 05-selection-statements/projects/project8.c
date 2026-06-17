#include <stdio.h>

int main(void){
    int hour, minutes, converted_hour;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minutes);

    converted_hour = hour * 60 + minutes;
    printf("Converted hour: %d\n", converted_hour);

    if (converted_hour <= (8 * 60) && converted_hour < (9 * 60 + 43)) {
        printf("Closest departure time is 8:00 am., arriving at 10:16 am\n");
    } else if (converted_hour >= (9 * 60 + 43) && converted_hour < (11 * 60 + 19)) {
        printf("Closest departure time is 9:43 am., arriving at 11:52 am\n");
    } else if (converted_hour >= (11 * 60 + 19) && converted_hour < (12 * 60 + 47)) {
        printf("Closest departure time is 11:19 am., arriving at 1:31 pm\n");
    } else if (converted_hour >= (12 * 60 + 47) && converted_hour < (14 * 60)) {
        printf("Closest departure time is 12:47 pm., arriving at 3:00 pm\n");
    } else if (converted_hour >= (14 * 60) && converted_hour < (15 * 60 + 45)) {
        printf("Closest departure time is 2:00 pm., arriving at 4:08 pm\n");
    } else if (converted_hour >= (15 * 60 + 45) && converted_hour < (19 * 60)) {
        printf("Closest departure time is 3:45 pm., arriving at 5:55 pm\n");
    } else if (converted_hour >= (19 * 60) && converted_hour < (21 * 60 + 45)) {
        printf("Closest departure time is 7:00 pm., arriving at 9:20 pm\n");
    } else if (converted_hour >= (21 * 60 + 45) && converted_hour < (23 * 60 + 59)) {
        printf("Closest departure time is 9:45 pm., arriving at 11:58 pm\n");
    }
    
    return 0;
}

