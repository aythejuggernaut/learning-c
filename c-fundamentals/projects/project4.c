#include <stdio.h>

#define VALUE_ADDED_TAX 0.05

int main (void) {
  float amount;
  printf("Enter an amount: ");
  scanf("%f", &amount);

  printf("With tax added: $%.2f\n", amount + (amount * VALUE_ADDED_TAX));
}

