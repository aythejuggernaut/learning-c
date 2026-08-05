#include <stdio.h>

int main(void)
{
    // C has three character types: char, signed char, and unsigned char.
    // char is a distinct type and is not compatible with signed char or unsigned char, even if it behaves like one of them. 
    // The compiler determines whether char is signed or unsigned (implementation-defined).
    // char is intended for storing character data, not general integer values.
    // Use signed char for small signed integers.
    // Use unsigned char for small unsigned integers.
    // sizeof(char) is always 1 byte.
    // The width of a char is CHAR_BIT bits, where CHAR_BIT is defined in <limits.h>.
    // CHAR_BIT is at least 8, and on most modern systems it is 8 bits.
    // The basic execution character set includes:
    //      - Uppercase letters (A–Z)
    //      - Lowercase letters (a–z)
    //      - Digits (0–9)
    //      - Space
    //      - Punctuation characters
    //      - Control characters (e.g., \n, \t)
    // The basic execution character set is sufficient for English but does not support many international characters.
    // wchar_t was introduced to represent larger character sets.
    // A wchar_t typically occupies 16 or 32 bits, depending on the implementation.
    // The C standard library provides functions for both narrow characters (char) and wide characters (wchar_t).
    // wchar_t was not designed specifically for Unicode, so modern C programs often prefer UTF-8 encoded char arrays instead.
    // Quick Summary:
    //      - char → character data
    //      - signed char → small signed integers
    //      - unsigned char → small unsigned integers
    //      - sizeof(char) = 1 byte
    //      - CHAR_BIT ≥ 8 (usually 8)
    //      - wchar_t supports larger character sets (typically 16 or 32 bits)
    //      - Modern C commonly uses UTF-8 with char instead of wchar_t for Unicode text.
}