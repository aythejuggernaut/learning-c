#include <stdio.h>
#include <string.h>

int main(void)
{
    // a structure (or struct) is a user-defined type that lets you group 
    // different kinds of data together under one name. unlike an array, whose 
    // elements must all have the same type, a structure's member can all have 
    // different types.
    // a structure type (also known as a struct) contains sequentially 
    // allocated members. Each member has its own name and may have a distinct 
    // type—unlike array elements, which must all be of the same type. 
    // structures are like record types found in other programming languages.
    // structures are useful for declaring collections of related objects and 
    // may be used to represent things such as a date, customer, or personnel 
    // record. They are especially useful for grouping objects that are 
    // frequently passed together as arguments to a function, so you don’t need 
    // to repeatedly pass individual objects separately.
    
    // Array example
    int numbers[3];
    
    // Memory Layout:
    // +-----+-----+-----+
    // | 10  | 20  | 30  |
    // +-----+-----+-----+
    // every element is an int

    // Structure example
    struct Student {
        int id;
        char name[20];
        float gpa;
    };

    // Memory Layout (Conceptual):
    // +-----------------+----------------+---------------+---...---+
    // |     id          |      name      |      gpa      | Padding |
    // +-----------------+----------------+---------------+---...---+
    // Different types

    struct sigrecord {
        int signum;
        char signame[20];
        char sigdesc[100];
    } sigline, *sigline_p;
    // after closing brace '} sigline;' creates a variable sigline whose type
    // is struct sigrecord, which is equivalent to
    // struct sigrecord sigline, *sigline_p;
    // After the struct definition,sigline is a variable of type "struct sigrec
    // ord" and sigline_p is a pointer to that struct type.
    // it can be initialized with an initializer list

    // sigline
    // +-----------------------------+
    // | signum   = ?                |
    // | signame  = ?                |
    // | sigdesc  = ?                |
    // +-----------------------------+
    // after
    sigline.signum = 5;

    // +-----------------------------+
    // | signum   = 5                |
    // | signame  = ?                |
    // | sigdesc  = ?                |
    // +-----------------------------+
    strcpy(sigline.signame, "SIGINT");

    // +-----------------------------+
    // | signum   = 5                |
    // | signame  = "SIGINT"         |
    // | sigdesc  = ?                |
    // +-----------------------------+
    strcpy(sigline.sigdesc, "Interrupt signal");

    // +-----------------------------+
    // | signum   = 5                |
    // | signame  = "SIGINT"       |
    // | sigdesc  = "Interrupt sig   nal" |
    // +-----------------------------+

    // members may be of any type
    // can be initialized with an initializer list
    struct sigrecord mysignal = {1, "SIGHUP", "hangup"};

    // using a pointer
    sigline_p = &sigline;
    // now
    // sigline_p
    // |
    // v
    // +-----------------------------------+
    // | signum                            |
    // | signame                           |
    // | sigdesc                           |
    // +-----------------------------------+
    // the pointer stores the address of the structure.

    // accessing through the pointer
    // instead of sigline.signum
    sigline_p->signum = 4;
    // the -> operator means, "follow the pointer, then access the member"
    // sigline.signum can be written as (*sigline_p).signum
    // without the parentheses, *sigline_p.signum would be interpreted 
    // incorrectly because . has higher precedence than *. the -> operator is 
    // just a convenient shorthand for this common operation.
    // dereference the pointer (*sigline_p), then access the member (.signum)
    
    // sigline_p->signum = 1;
    // strcpy(sigline_p->signame, "SIGHUP");
    // strcpy(sigline_p->sigdesc, "hangup");
    
    // Example
    // sigline_p
    // |
    // v

    // +-----------------------------+
    // | signum                      |
    // | signame                     |
    // | sigdesc                     |
    // +-----------------------------+
    // when you write sigline_p->signum = 4; the computer does
    // 1. takes the value of sigline_p (which is the address of sigline)
    // 2. adds the offset of signum within the struct to that address
    // 3. stores the value 4 at that location
    // offset is the distance in bytes from the beginning of the struct to the 
    // start of that member
    // offset of signum = 0
    // offset of signame = sizeof(int)
    // offset of sigdesc = sizeof(int) + sizeof(signame)
    // note that padding may be inserted between members, so these are
    // approximate offsets.

    // Dot (.) vs Arrow (->)
    // if you have an actual structure object, 
    // struct sigrecord sigline;
    // use . operator
    // sigline.signum

    // if you have a pointer to a structure
    // struct sigrecord *sigline_p
    // use -> operator
    // sigline_p->signum

    // Use the arrow operator (->) to access members through a pointer to a 
    // structure. The expression ptr->member is exactly equivalent to (*ptr) 
    // member.

    // strcpy prototype -> char *strcpy(char * restricts dest, const char * restrict src);
    // The const means strcpy promises not to modify the source string.
    // src must be null terminated string
    // dest must have at least as much storage as src (including the null 
    // terminator)
    // the null terminator is copied returns a pointer to the first argument (dest)

    // if src is longer than dest, strcpy will write past the end of 
    // dest, corrupting memory. This is a common source of security 
    // vulnerabilities. Use strncpy or snprintf instead, if possible.
 
    // return type -> char *
    // strcpy() returns a pointer to the destination string.
    char buffer[20];
    char *p = strcpy(buffer, "Hello");
    // after the call, p points to buffer
    printf("%s\n", p);
    // prints "Hello"
    // Both buffer and p point to the same string "Hello".

    return 0;
}
