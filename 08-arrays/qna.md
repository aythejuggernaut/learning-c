### Q: Is it possible to use a character as an array subscript?

### A: Yes, because C treats characters as integers.

You'll probably need to "scale" the character before you use it as a subscript, though. Let's say that we want the
letter_count array to keep track of a count for each letter in the alphabet. The
array will need 26 elements, so we'd declare it in the following way:

```c
int letter_count[26];
```

However, we can't use letters to subscript letter_count directly, because their
integer values don't fall between 0 and 25. To scale a lower-case letter to the
proper range, we can simply subtract 'a'; to scale an upper-case letter, we'll sub-
tract 'A'. For example, if ch contains a lower-case letter, we'd write

```c
letter_count[ch - 'a'] = 0;
```

to clear the count that corresponds to ch. A minor caveat: this technique isn't completely portable, because it assumes that letters have consecutive codes. However, it works with most character sets, including ASCII.

### Q: It seems like a designated initializer could end up initializing an array element more than once. Consider the following array declaration:

```c
int a[] = {4, 9, 1, 8, [0] = 5, 7};
```

### Is this declaration legal, and if so, what is the length of the array?

### A: Yes, the declaration is legal. Here's how it works: as it processes an initializer list, the compiler keeps track of which array element is to be initialized next. Normally, the next element is the one following the element that was last initialized. However, when a designator appears in the list, it forces the next element be the one represented by the designator, even if that element has already been initialized. Here's a step-by-step look at how the compiler will process the initializer for the array a:

The 4 initializes element 0; the next element to be initialized is element 1.
The 9 initializes element 1; the next element to be initialized is element 2.
The 1 initializes element 2; the next element to be initialized is element 3.
The 8 initializes element 3; the next element to be initialized is element 4.
The [0] designator causes the next element to become 0, so the 5 initializes
element 0 (replacing the 4 previously stored there). The next element to
be initialized is element 1.
The 7 initializes element 1 (replacing the 9 previously stored there). The next
element to be initialized is element 2 (which is irrelevant since we're at
the end of the list).
The net effect is the same as if we had written

```c
int a[] = {5, 7, 1, 8};
```

Thus, the length of this array is four.

### Q: The compiler gives me an error message if I try to copy one array into another by using the assignment operator. What's wrong?

### A: Although it looks quite plausible, the assignment

```c
a = b; // a and b are arrays
```

is indeed illegal. The reason for its illegality isn't obvious; it has to do with the
peculiar relationship between arrays and pointers in C, The simplest way to copy
one array into another is to use a loop that copies the elements, one by one:

```c
for (i = 0; i < N; i++)
    a[i] = b[i];
```

Another possibility is to use the memepy ("memory copy") function from the
`<string.h>` header, memcpy is a low-level function that simply copies bytes
from one place to another. To copy the array b into the array a, use memcpy as
follows:

```c
memcpy(a, b, sizeof(a));
```

Many programmers prefer memepy, especially for large arrays, because it's potentially faster than an ordinary loop.

### Q: C99 doesn't allow a goto statement to bypass the declaration of a variable-length array. What's the reason for this restriction?

### A: The memory used to store a variable-length array is usually allocated when the declaration of the array is reached during program execution. Bypassing the declaration using a goto statement could result in a program accessing the elements of an array that was never allocated. Allowing a goto statement to bypass the declaration of a VLA could lead to a situation where the array is never properly initialized. Consider the following example:

```c
void f(int n)
{
    goto label;
    int vla[n]; // VLA declaration
    // ...
label:
    // 'vla' is jumped over, so it's never initialized
    for (int i = 0; i < n; i++) {
        vla[i] = 0; // Undefined behavior!
    }
}
```

If the goto statement were allowed to bypass the VLA declaration, the VLA would be created without being initialized. Subsequently, accessing its elements would result in undefined behavior. This is because VLAs must be properly initialized before they can be used, and the VLA's storage must be properly managed (allocated and deallocated). By prohibiting goto from jumping over a VLA declaration, C99 ensures that the array is always initialized and its storage is properly managed, thus avoiding undefined behavior.
