#include <stdio.h>

int main(void)
{
    // the array m has 5 rows and 9 columns. both rows and columns are indexed
    // from 0. to access the element of m in row i, column j, we must write 
    // m[i][j]. the expression m[i] designates row i of m, and m[i][j] then 
    // selects element j in this row.
    int m[5][9];

    // resist the temptation to write m[i,j] instead of m[i][j]. C treats the 
    // comma as an operator in this context, so m[i,j] is the same as m[j].

    // although we visualize 2D arrays as tables, that's not the way they're 
    // actually stored in computer memory. C stores arrays in "row-major order,
    // with row 0 first, then row 1, and so forth.
    // row 0 (m[0,0] ... m[0,8]), row 1 (m[1,0] ... m[1,8]), ..., row 4 (m[4,0] ... m[4,8])
    // we'll usually ignore this detail, but sometimes it will affect our code, 
    // and it can matter for performance. for example, if we have many rows,
    // then most of our array will be in slow memory, but only some will be in
    // the cache.
    // another example is cache-friendly access patterns
    // consider:
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            m[i][j] = 0;
        }
    }

    // here we touch the elements of row 0, then the elements of row 1, etc
    // each time we start a new row, we access new memory addresses. 
    // if each row fits in the cache, we'll have good performance. 
    // now consider the alternative:
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 5; i++) {
            m[i][j] = 0;
        }
    }
    // here we touch m[0][0], m[1][0], ... m[4][0], then m[0][1], m[1][1], ...
    // if the rows are large, we'll have many cache misses. 
    // this kind of detailed consideration of cache access isn't usually necessary,
    // but it's good to be aware of.
    
    // in many real programs, we'll initialize arrays as we declare them:
    int m[5][9] = {{0}};
    // this initializes all elements to 0.
    int m[5][9] = {{0}, {1}, {2}, {3}, {4}};
    // this initializes the first element of each row to the given value.
    int m[5][9] = {{0, 1, 2, 3, 4, 5, 6, 7, 8}, 
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}, 
                   {2, 3, 4, 5, 6, 7, 8, 9, 10}, 
                   {3, 4, 5, 6, 7, 8, 9, 10, 11}, 
                   {4, 5, 6, 7, 8, 9, 10, 11, 12}};            

    // for C arrays: int m[ROWS][COLS]
    // the most cache-friendly traversal is usually: 
    #define ROWS 10
    #define COLS 10

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; i < COLS; i++) {
            use(m[i][j]);
        }
    }
    // because j changes fastest and elements with consecutive j values are 
    // stored next to each other in memory. In other words:
    // access memory in the same order it is stored.
    // since c stores arrays in row-major order, row-wise traversal tends to be 
    // the most cache-efficient.

    // Key Takeaway - The comment is teaching two fundamental ideas:
    // 1. A 2D array is conceptually a table but physically a linear block of memory.
    // 2. C stores 2D arrays in row-major order, meaning an entire row is stored before the next row.
    // 3. CPU caches reward sequential memory access.
    // 4. Traversing rows first (m[i][j]) follows memory order and is usually cache-friendly.
    // 5. Traversing columns first (m[i][j] with i changing fastest) can cause many cache misses for large arrays and significantly reduce performance.
    // This is one of the earliest examples of a deeper principle in systems programming:
    // The algorithm's complexity matters, but the pattern in which it touches memory can matter almost as much on modern hardware.
        

    return 0;
}

