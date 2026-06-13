#include <stdio.h>

int main(void)
{
    // the goto statement, on the other hand, is capableof jumping to any 
    // statement in a function, provided that the statement has a label.
    // the goto statement can be helpful once in a while. Consider the problem 
    // of exiting a loop from within a switch statement. As we saw earlier, the 
    // break statement doesn't quite have the desired effect: it exits from the
    // switch, but not from the loop. A goto statement solves the problem:

    // while (...) {
    //     switch (...) {
    //         ...
    //         goto loop_done;
    //     }
    // }
    // loop_done;
    
    // The goto statement is also useful for exiting from nested loops.
}