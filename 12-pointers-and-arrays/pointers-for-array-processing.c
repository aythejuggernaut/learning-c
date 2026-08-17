#include <stdio.h>

#define N 10

int main(void)
{
    // pointer arithmetic allows us to visit the elements of an array by 
    // repeatedly incrementing a pointer variable.
    int a[N] = {11, 34, 82, 7, 64, 98, 47, 18, 79, 20}, sum, *p;
    sum = 0;
    for (p = &a[0]; p < &a[N]; p++) {
        sum += *p;
    }

    printf("Sum=%d\n", sum);
    // the condition p < &a[N] in the for statement deserves special mention. 
    // strange as it may seem, it's legal to apply the address operator to a[N] 
    // even though this element doesn't exist (a is indexed from 0 to N-1).
    // using a[N] in this fashion is perfectly safe, since the loop doesn't 
    // attempt to examine its value.
    // the body of the loop will be executed with p equal to &a[0], &a[1]..&a[N]
    // but when p is equal to &a[N], the loop terminates

    // Combining the * andd ++ Operators
    // C programmers often combine the * (indirection) and ++ operators in 
    // statements that process array elements. Consider the simple case of 
    // storing a value into an array element and then advancing to the next 
    // element. Using array subscripting. we might write:
    // a[i++] = j;
    // if p is pointing to an array element, the corresponding statement would be:
    // *p++ = j;

    // 1. *p++ or *(p++): use the value, the move the pointer
    // int x = *p++;
    // is essentially
    // int x = *p;
    // p++;

    // *p++ = j; // means store j in the current element, then advance p.

    // 2. (*p)++: increment the value, not the pointer
    // if p -> 10
    // then: *(p++)
    // means 10 -> 11
    // the pointer doesn't move.
    // so:
    int x = (*p)++;
    // gives:
    // x = 10;
    // *p = 11;
    // p still points to 11
    
    // 3. *++p or *(++p) -> move the pointer first, then get the value
    // first: p++
    // then: *p
    // so if p -> 10 20 30
    // after *++p
    // the expression's value is 20

    // 4. ++*p or ++(*p) -> increment the value first
    // if p -> 10
    // then: ++*p;
    // changes the array element:
    // p -> 11
    // the pointer doesn't move.

    // | Expression | What gets incremented? | What happens first?            |
    // | ---------- | ---------------------- | ------------------------------ |
    // | `*p++`     | `p` (pointer)          | use `*p`, then move `p`        |
    // | `(*p)++`   | `*p` (value)           | use value, then increase value |
    // | `*++p`     | `p` (pointer)          | move `p`, then use `*p`        |
    // | `++*p`     | `*p` (value)           | increase value, then use it    |

    // A very useful trick is to add parentheses yourself:
    // *p++    → *(p++)
    // *++p    → *(++p)
    // ++*p    → ++(*p)
    // (*p)++  → (*p)++
    // Then it becomes much easier.

    // One important distinction
    // Think of p as an address and *p as the thing stored at that address.
    //     p
    //     ↓
    //  ┌────┬────┬────┐
    //  │ 10 │ 20 │ 30 │
    //  └────┴────┴────┘
    //    ↑
    //   *p

    // p++ → move the arrow
    // (*p)++ → change the number
    // ++p → move the arrow first
    // ++(*p) → change the number first

    // That is the whole idea behind the table.
}