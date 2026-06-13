#include <stdio.h>

int main(void){
    float income, tax;

    printf("Enter the amount of taxable income: ");
    scanf("%f", &income);

    if (income < 750.0f){
        tax = income * 0.1f;
    } else if (income >= 750.0f && income < 2250.0f) {
        tax = 7.50f + 0.02f * (income - 750.0f);
    } else if (income >= 2250.0f && income < 3750.0f) {
        tax = 37.50f + 0.03f * (income - 2250.0f);
    }
    else if (income >= 3750.0f && income < 5250.0f) {
        tax = 82.50f + 0.04f * (income - 3750.0f);
    } else if (income >= 5250.0f && income < 7000.0f) {
        tax = 142.50f + 0.05f * (income - 5250.0f);
    } else {
        tax = 247.50f + 0.07f * (income - 7000.0f);
    }
    printf("The amount of tax is: %.2f\n", tax);
    return 0;
}

