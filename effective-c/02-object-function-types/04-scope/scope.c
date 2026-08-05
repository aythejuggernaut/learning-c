#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // an identifier can be the name of a: variable, function, macro, typedef, 
    // enum constant, label.
    
    // The four kinds of scope in C are:
    // 1. File scope - An identifier has file scope if it is declared outside 
    // any/every function or block, accessible throughout the file
    // 2. Block scope - An identifier has block scope if it is declared inside 
    // anything enclosed in braces. Blocks can be nested. Inner block can access
    // variables declared in the outer block, but not vice-versa.
    // Why? because inner scopes can see outward but outer scopes cannot see
    // inward. Think of nested boxes.
    // +----------------------+
    // | x                    |
    // |                      |
    // |   +--------------+   |
    // |   | y            |   |
    // |   +--------------+   |
    // |                      |
    // +----------------------+
    //
    //
    // 3. Function prototype scope - This is the least important scope. It 
    // applies only to the parameters of a function. Consider:
    void print(int number);
    // `number` has function prototype scope. It is only visible within the 
    // function prototype. you cannot write:
    // print("%d", number);
    // after the prototype. its scope ends immediately after the prototype.
    // This is why it is the least important scope. It is only there for 
    // reasons of documentation. so that someone reading the function 
    // prototype knows what parameters it takes.

    // 4. Function scope: only labels have function scope. Consider:
    void f(void) {
        start:
            printf("start");
        goto start;
    }
    // Here, start: is a label. It is visible throughout the function. No 
    // ordinary variable has function scope. This is what most people mean when
    // they say a variable has function scope - they mean it is global to the 
    // function in which it is defined.

    // Scopes can exist inside other scopes. Every inner scope can access 
    // everything above it.

    // Shadowing (Hiding) means: when you declare a variable in an inner
    // scope that has the same name as a variable in an outer scope.
    // In that case, the inner variable hides the outer variable.
    // Hiding is not all bad. It allows you to reuse names in different scopes without conflict.

    // Lifetime of objects: when an object is created and when it is destroyed.
    // There are three major categories of objects based on their lifetime:
    // 1. Automatic storage duration: objects declared inside a block, 
    //    created when the block is entered, destroyed when the block is exited.
    //    This is what most people mean when they say a variable has function scope.
    // 2. Static storage duration: objects declared outside any block, 
    //    created when the program starts, destroyed when the program ends.
    // 3. Dynamic storage duration: objects created using malloc, destroyed using free.

    // Automatic variables are initialized to 0 if they are global or static, 
    // but not if they are automatic.
    // In C, uninitialized automatic variables have indeterminate values - they 
    // can contain garbage data.
    // This is a common source of bugs in C programming.

    // Lifetime vs Scope: just because an object has a certain scope, does not mean
    // it has a certain lifetime. For example, a static variable inside a function
    // has static storage duration, but it has local scope. 
    // It is only visible within the function in which it is defined, but it is 
    // created when the program starts and destroyed when the program ends.


    int x = 55;
    // Scope asks: where can i use the name x?
    // Lifetime asks: when does the object actually exist?

    {
        int y = 12;
        {
            int y = 34;
            // Here, we have two y variables. The inner y hides the outer y.
            // We can access both y variables using different approaches, such as:
            printf("inner y: %d\n", y);
            printf("outer y: %d\n", ({ int y = 100; y; }));
        }
    }
    // Here, we can only access x. y is not visible here.

    // COMPOUND BLOCK STATEMENT
    // In C, you can introduce a new compound statement (block) anywhere a statement is allowed by using curly braces:
    // {
    //     {
    //         int y = 12;
    //         {
    //             int y = 34;
    //             printf("%d\n", y);
    //         }
    //     }
    // }
    // the extra braces simply create a new scope. the outer y exists only 
    // inside the extra block. once execution reaches the closing }, the y goe 
    // out of scope. creating extra scope is commonly used to:
    // - Limit the lifetime and visibility of variables.
    // - Reuse variable names in different parts of a function.
    // - Group related code together.

    return EXIT_SUCCESS;
}