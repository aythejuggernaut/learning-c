#include <stdio.h>

int main(void)
{
    // tags are a special naming mechanism for structures, unions, and 
    // enumerations. For example, the identifier s in the following 
    // structure is a tag:
    struct s {
        // -- snip --
    };
    // By itself, a tag is not a type name and cannot be used to declare a 
    // variable. Instead, you must declare variables of this type as follows:
    struct s v; // instance of struct s
    struct s *p; // pointer to struct s

    // The names of unions and enumerations are also tags and not types, 
    // meaning that they cannot be used alone to declare a variable. For example:
    enum day { sun, mon, tue, wed, thu, fri, sat };
    day today; // error
    enum day tomorrow; // OK

    // The tags of structures, unions, and enumerations are defined in a 
    // separate namespace from ordinary identifiers. This allows a C program to 
    // have both a tag and another identifier with the same spelling in the same scope:
    enum status { ok, fail }; // enumeration
    enum status status(void); // function
    // This common practice is dangerous, however, as it can lead to confus-ing
    // error messages. For example, if the programmer accidentally writes:
    // enum status { ok, fail };
    // status(ok); // error
    // The compiler will report that the identifier status is used incorrectly, 
    // but it may not be obvious to the beginner that the error results from the
    // attempt to call the enumeration status as a function.
    // There is one way that a tag can be used to create a type name.
    
    // This may not be good practice, but it is valid C. You can think of struct
    // tags as type names and define an alias for the tag by using a typedef. 
    // Here’s an example:
    typedef struct x { int x; } t;

    // 1. Struct tags vs typedef names
    // normally, when you define a structure, you write:
    struct sx {
        int x;
    };
    // In this example, sx is a tag, and struct sx is a type name.
    // A common practice is to use a typedef to create a type name that is 
    // the same as the tag name:
    typedef struct sxy {
        int x;
    } sxy;
    // In this case, both sxy and struct sxy are type names. You can use either 
    // to declare variables:
    struct sxy v1;
    sxy v2; // equivalent to struct sx v2
    
    // It is also possible to omit the tag name entirely:
    typedef struct { 
        int x; 
    } tx;
    tx vtx; // equivalent to struct tx vtx
    
    // When you omit the tag name, the type name exists, but you cannot use
    // the struct keyword to declare another variable of this type later. For
    // example, the following code does not compile:
    tx v1;
    struct tx v2; // error: tx has no tag

    // This can be especially convenient for self-referential structures:
    typedef struct node { 
        int x; 
        struct node *next; 
    } node;


    // 2. Why self-referential structures are different
    // suppose you're making a binary tree node. each node contains pointers 
    // to more nodeds.
    // conceptually,
    //        node
    //       /    \
    //    node   node    
    // you'd like to write:
    typedef struct {
        int count;
        tnode *left;
        tnode *right;
    } tnode;
    // but this doesn't work. because while the compiler is reading the 
    // structure, tnode does not exist yet.
    // the typedef name is not known until the compiler has finished reading
    // the entire structure definition. At that point, it can create the type
    // name tnode, but it cannot use that name earlier in the definition.
    // for structures, tags are different. The tag name is defined 
    // before the structure body.
    typedef struct tnode {
        int count;
        struct tnode *left;
        struct tnode *right;
    } tnode;
    // as soon as the compiler reads struct tnode, it immediately knows there's 
    // a structure named tnode. It allocates space for the structure definition 
    // and then processes the members.

    // Why is it possible to define a self-referential structure?
    // When you declare a pointer to a structure type, the compiler
    // doesn't need to know the complete structure layout. It only needs to
    // reserve enough storage for a pointer, which is a fixed size on any given
    // architecture.
    // In the example above, when the compiler encounters the declaration:
    // struct tnode *left;
    // It knows that struct tnode is a pointer type, and it allocates space 
    // for a pointer (e.g., 8 bytes on a 64-bit system). 
    // It does not need to know the size of struct tnode itself to make this 
    // decision.
    
    // However, when it later encounters:
    // struct tnode v;
    // Now it needs the complete layout of struct tnode to allocate space
    // for v. By this time, the compiler has processed the entire structure
    // definition and knows that it contains an int and two pointers.
    
    // struct tnode left; while the compiler is defining the structure, it 
    // doesn't yet know its full size. It can't place another whole structure 
    // inside itself. That would be impossible. A pointer is different,
    // pointers always have a known size. for example, 8 bytes on a 64-bit system. 

    // 3. Why people use ugly tag names
    // sometimes you'll see
    typedef struct tnode_ {
        int count;
        struct tnode_ *left;
        struct tnode_ *right;
    } tnode;
    // now there are two names: struct tnode and tnode
    // the trailing underscore is used to distinguish the tag name (tnode_)
    // from the typedef name (tnode). This prevents the name collision 
    // problem described earlier. While some programmers find this approach 
    // confusing, it is a common convention in C codebases. programmers are 
    // encouraged to use tnode instead of struct tnode_
    // the ugly underscore reminds you that the tag is just an implementation detail.

    // 4. Forward declarations of structure types
    // You've seen that you can't use a structure type before it's fully 
    // defined. This applies to function parameters and return types as well.
    struct point *next_point(); // error
    // However, you can declare a pointer to a structure type before the 
    // structure is defined. This is called a forward declaration. 
    // For example:
    struct point;
    struct point *next_point();

    typedef struct xnode xnode;
    // this tells the compiler: there will eventually be a structure called 
    // struct xnode, and i want xnode to be an alias for it. At this point the structure is incomplete.

    // Later:
    struct xnode {
        int count;
        xnode *left;
        xnode *right;
    };
    // now xnode is a complete type. We can declare variables of this type.
    xnode vf;
    xnode *vp = &vf;

    // 5. Why typedef improves readability?
    void (*signal(int, void (*)(int)))(int);
    // let's decode it, It says:
    // signal is a function
    // takes an int
    // takes a pointer to a function
    // returns a pointer to another function

    // signal is a function

    // takes:
    //     int
    //     pointer to function(int) returning void

    // returns:
    //     pointer to function(int) returning void

//               signal
//              |
//           function
//          /        \
//       int      function pointer
//                   |
//              void func(int)

// returns

//       function pointer
//             |
//        void func(int)

    typedef void fv(int); // function that returns void and takes int
    // meaning fv is the name of a func type -> void function(int)
    typedef void (*pfv)(int);
    // meaning pfv is the name of a func pointer type -> pointer to a function that returns void and takes int
    // now instead of  void (*signal(int, void (*)(int)))(int);
    // we can write:
    pfv signal(int, pfv);
    // signal is a function taking an int and pfv, and returing a pfv
    // This is much easier to read and understand!

    // Key takeaway
    // A struct tag (e.g. struct tnode) is available while the structure is being defined, so it can be used for self-references.
    // A typedef name (e.g. tnode) is introduced only after the declaration is complete, so it cannot be used inside the structure unless you first provide a forward declaration:
    typedef struct knode knode;
    // typedef doesn't create a new type; it creates an alias for an existing type, making declarations much easier to read, especially for structures and function pointers.

    // A useful rule for decoding C declarations
    // Whenever you see a complicated declaration:
    // 1. Find the variable/function name (signal).
    // 2. Look right first:
            // () → function
            // [] → array
    // 3. Then look left:
            // * → pointer
    // 4. Move outward, respecting parentheses.
    // Applying that rule to
    void (*signal(int, void (*)(int)))(int);
    // naturally leads to: "signal is a function that takes an int and a pointer to a function (int) -> void, and returns a pointer to a function (int) -> void."
    
    return 0;
}