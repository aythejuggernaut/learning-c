#ifndef MIKEMATH_H // #ifdef checks that something exists; #ifndef checks that it doesn't exist.
#define MIKEMATH_H // header guards to ensure they're only included once. it prevents the header's content from being included multiple times in the same compilation unit.

typedef struct vector {
    float x;
    float y;
} vector_h;

// Function declaration for the ability to add two vectors
void Add(vector_h*, const vector_h*);

#endif