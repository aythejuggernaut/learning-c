#include <stdio.h>

int main(void) {
    // C places no restrictions on the three expressions that control its
    // behavior. Although these expressions usually initialize, test, and 
    // update the same variable, there's no requirement that they be related in
    // any way.

    int i, n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    i = 1;
    odd = 3;
    for (square = 1; i <= n; odd += 2) {
        printf("%10d%10d\n", i, square);
        i++;
        square += odd;
    }

    // The for statement in this program initializes one variable (square),
    // tests another (i), and increments a third (odd). i is the number to be
    // squared, square is the square of i, and odd is the odd number that must
    // be added to the current square to get the next square (allowing the
    // program to compute consecutive squares without performing any
    // multiplications).

    // The tremendous flexibility of the for statement can sometimes be useful;
    // we'll find it to be a great help when working with linked lists. The for
    // statement can easily be misused, though, so don't go overboard. The for
    // loop in square3.c would be a lot clearer if we rearranged its pieces so
    // that the loop is clearly controlled by i.

    return 0;
}