/* gcc -std=c11 -Wall -Wextra -pedantic -o pun pun.c */
#include <stdio.h>

int main(void) {
  int height;
  height = 8;
  printf("height = %d\n", height);
  float profit = 2150.999f;
  printf("profit = $%.1f\n", profit);
  return 0;
}
