#include <stdio.h>

int main(void) {
    int item_number, month, day, year;
    float unit_price;
    printf("Enter item number: ");
    scanf("%d", &item_number);

    printf("Enter unit price: ");
    scanf("%f", &unit_price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    // printf("Item Number: %d\n", item_number);
    // printf("Unit price: $%.2f\n", unit_price);
    // printf("Purchase date: %.2d/%.2d/%.4d\n", month, day, year);

    printf("Item\t\tUnit price\t\tPurchase date\n");
    printf("%d\t\t$%7.2f\t\t%.2d/%.2d/%.4d\n", item_number, unit_price, month, day, year);

    return 0;
}