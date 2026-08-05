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
    int remainder, possible_row, possible_col;
    char walk_board[BOARD_LENGTH_SIZE][BOARD_BREADTH_SIZE];
    char markers[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int valid_directions[VALID_DIRECTIONS_COUNT] = {-1};
    int valid_count = 0;
    int marker_length = (int) sizeof(markers) / sizeof(markers[0]);
    printf("marker length = %d\n", marker_length);

    srand((unsigned) time(NULL));

    // fill the board with "."
    memset(walk_board, '.', sizeof(walk_board));

    walk_board[row][col] = markers[0];

    for (int i = 1; i < marker_length - 1; i++) {
        // compute marker mover - selected direction
        remainder = rand() % 4;
        int stop = 0;

        // compute four possible directions
        for (int j = 0; j < VALID_DIRECTIONS_COUNT; j++) {
            // Up → (row - 1, col)
            // Right → (row, col + 1)
            // Down → (row + 1, col)
            // Left → (row, col - 1)

            // compute the change in position on the board
            // check if the new position is a valid position on the board
            // i.e., the position is within bounds
            // and the position is not already visited
            switch (remainder) {
                case MOVE_UP:
                    // check if the marker can move up
                    possible_row = row - 1;
                    if (possible_row > 9) {
                        stop = 1;
                        break;
                    }
                    if (possible_row < 0) {
                        row = 1;
                        i--;
                        continue;
                    };
                    // if valid, add to the list of valid directions
                    valid_directions[j] = MOVE_UP;
                    valid_count++;
                    break; 
                case MOVE_RIGHT:
                    // check if the marker can move right
                    possible_col = col + 1;
                    if (possible_col > 9) {
                        stop = 1;
                        break;
                    }
                    if (possible_col < 0) {
                        col = 1;
                        i--;
                        continue;
                    };
                    // if valid, add to the list of valid directions
                    valid_directions[j] = MOVE_RIGHT;
                    valid_count++;
                    break;
                case MOVE_DOWN:
                    // check if the marker can move down
                    possible_row = row + 1;
                    if (possible_row > 9) {
                        stop = 1;
                        break;
                    }
                    if (possible_row < 0) {
                        row = 1;
                        i--;
                        continue;
                    };
                    // if valid, add to the list of valid directions
                    valid_directions[j] = MOVE_DOWN;
                    valid_count++;
                    break;
                case MOVE_LEFT:
                    // check if the marker can move left
                    possible_col = col - 1;
                    if (possible_col > 9) {
                        stop = 1;
                        break;
                    }
                    if (possible_col < 0) {
                        col = 1;
                        i--;
                        continue;
                    };
                    // if valid, add to the list of valid directions
                    valid_directions[j] = MOVE_LEFT;
                    valid_count++;
                    break;
            }
        }

        if (stop) break;

        printf("valid count = %d\n", valid_count);

        // check if there are no valid directions
        int has_valid_directions = 0;
        for (int j = 0; j < valid_count; j++) {
            if (valid_directions[j] != -1) {
                has_valid_directions = 1;
                break;
            }
        }

        if (!has_valid_directions) break;

        for (int j = 0; j < valid_count; j++) {
            switch (valid_directions[j]) {
            case MOVE_UP:
                row -= 1;
                break;
            case MOVE_RIGHT:
                col += 1;
                break;
            case MOVE_DOWN:
                row += 1;
                break;
            case MOVE_LEFT:
                col -= 1;
                break;
            }
        }

        printf("marker index = %d\n", i + 1);
        printf("row = %d; col = %d\n", row, col);

        walk_board[row][col] = markers[i + 1];
        valid_count = 0;
        for (int j = 0; j < VALID_DIRECTIONS_COUNT; j++) {
            valid_directions[j] = -1;
        }
    }

    for (int i = 0; i < BOARD_LENGTH_SIZE; i++) {
        for (int j = 0; j < BOARD_BREADTH_SIZE; j++) {
            printf("%c", walk_board[i][j]);
        }
        printf("\n");
    }

    printf("row - %d; col - %d; remainder - %d\n", row, col, remainder);
    return 0;
}

