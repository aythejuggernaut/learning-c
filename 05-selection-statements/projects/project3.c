#include <stdio.h>

int main(void) {
    float number_of_shares, price_per_share, commission;

    printf("Enter number of shares: ");
    scanf("%f", &number_of_shares);

    printf("Enter price per share: ");
    scanf("%f", &price_per_share);

    if (number_of_shares < 2000){
        commission = 30.00f + 0.03f * price_per_share;
    } else {
        commission = 33.00f + 0.02f * price_per_share;
    }

    printf("Commission: $%.2f\n", commission);
    
    return 0;
}

