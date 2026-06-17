#include <stdio.h>

int main(void) {
    float amount, interest_rate, monthly_payment;
    printf("Enter amount of loan: ");
    scanf("%f", &amount);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float monthly_interest_rate = (interest_rate / 100) / 12;
    float balance = amount;

    balance += balance * monthly_interest_rate;
    balance -= monthly_payment;
    printf("Balance remaining after first payment: $%.2f\n", balance);
    
    balance += balance * monthly_interest_rate;
    balance -= monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", balance);

    balance += balance * monthly_interest_rate;
    balance -= monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", balance);

    return 0;
}