#include <stdio.h>
#include <time.h>
#include <stdlib.h>  /* Provides rand() and srand() */
#include <stdbool.h> /* C99 only: provides _Bool and value true/false */

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    // even though in_hand is a two-dimensional array, we can use a single pair 
    // of braces (at the risk of possibly incurring a warning from the 
    // compiler). also, we've supplied only one value in the initializer, 
    // knowing that the compiler will fill in the remaining values with 0, 
    // which is treated as false in a boolean context.
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int rank, suit, num_cards;

    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'s', 'h', 'd', 'c'};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS; /* picks a random suit */
        rank = rand() % NUM_RANKS; /* picks a random rank */

        if(!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("  %c%c", rank_code[rank], suit_code[suit]);
        }
    }

    printf("\n");

    return 0;
}

