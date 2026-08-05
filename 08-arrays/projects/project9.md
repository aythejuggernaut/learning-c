// rand()

    // steps:
    // start at some position (row, col) = (0, 0) = A
    // generate a random number
    // compute random % 4
    // interpret each number as a direction:
    //         0 -> up, 1 -> right, 2 -> down, 3 -> left
    // update either row or column accordingly
    // repeat from the new position
    // factor in what would happen when a randomly choosen direction
    // would leave the grid? and would happen when you move to an already
    // visited cell.

    // note: at no point should you iterate through all cells; maintain only a
    // single "current location" and move it.

// So if you’re at (5,5) and get:
// • remainder 1 → (5,6)
// • remainder 1 → (5,7)
// • remainder 0 → (4,7)
// • remainder 3 → (4,6)

// Direction // Row // Column
// Up // decreases // unchanged
// Right // unchanged // increases
// Down // increases // unchanged
// Left // unchanged // decrease

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define BOARD_LENGTH_SIZE 10
#define BOARD_BREADTH_SIZE 10
#define VALID_DIRECTIONS_COUNT 4
// possible moves
#define MOVE_UP 0
#define MOVE_RIGHT 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3

int main(void) {
int row = 0, col = 0;
int remainder;
char walk_board[BOARD_LENGTH_SIZE][BOARD_BREADTH_SIZE] = {"."};
char markers[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int valid_directions[VALID_DIRECTIONS_COUNT] = {};
int valid_directions_length = (int) sizeof(valid_directions) / sizeof(valid_directions[0]);

    int marker_length = (int) sizeof(markers) / sizeof(markers[0]);

    srand((unsigned) time(NULL));

    // fill the board with "."
    memset(walk_board, '.', sizeof(walk_board));

    walk_board[row][col] = markers[0];

    for (int i = 0; i < marker_length; i++) {
        // compute marker mover
        remainder = rand() % 4;

        // compute four possible directions
        for (int j = 0; j < VALID_DIRECTIONS_COUNT; j++) {

            // Up → (row - 1, col)
            // Right → (row, col + 1)
            // Down → (row + 1, col)
            // Left → (row, col - 1)
            // valid_directions[j] = (remainder + j) % 4;
        }

        // direction coordinate changes
        switch (remainder) {
            case MOVE_UP:
                row -= remainder;
            case MOVE_RIGHT:
                col += remainder;
            case MOVE_DOWN:
                row += remainder;
            case MOVE_LEFT:
                col -= remainder;
        }

        if (row == 9 || col == 9) break;
        if (row < 0) {
            row = 1;
            i--;
            continue;
        };

        if (col < 0) {
            col = 1;
            i--;
            continue;
        };

        walk_board[row][col] = markers[i + 1];
    }

    for (int i = 0; i < BOARD_LENGTH_SIZE; i++) {
        for (int j = 0; j < BOARD_BREADTH_SIZE; j++) {
            printf("%c", walk_board[i][j]);
        }
        printf("\n");
    }

    // printf("row - %d; col - %d; remainder - %d\n", row, col, remainder);
    return 0;

}

// go through the program, what could cause the row to go above 9
// answer: we never check for that in the switch statement. e.g. if row = 9
// and remainder = 1, it will compute possible_row = 10, and then print
// row = 10, which is out of bounds.
// for a 10 x 10 board, the valid indices are 0 - 9
// if the next possible position is >= 10 or <= -1, it is out of bounds
// so i have to do 2 checks:
// 1. check if the next possible position is within bounds
// 2. check if the next possible position is already visited
// how about check the row or col?
// answer:
// - check the previous position that the marker was at
// - if the previous position was up, then the next position can't be down
// - if the previous position was right, then the next position can't be left
// - if the previous position was down, then the next position can't be up
// - if the previous position was left, then the next position can't be right
// - if the previous position was up, then the next position can't be up
// - if the previous position was right, then the next position can't be right
// - if the previous position was down, then the next position can't be down
// - if the previous position was left, then the next position can't be left
// i.e. the current position can't be the same as the previous position
// except that it can be if the current position is the same as the
// position before the previous position.
// e.g. if the previous position was (1,1), and the current position is (1,1),
// then the position before the previous position must be (1,2) or (2,1).
// if the position before the previous position was (1,2), then the next
// position can't be (1,2) (as that would be going back)
