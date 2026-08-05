#include <stdio.h>

int main(void)
{
    // Floating-point types store real numbers with fractional (decimal) parts.
    // Floating-point arithmetic is similar to real-number arithmetic, but precision is limited by the computer's representation.
    // Most systems use the IEEE 754 standard for floating-point representation.
    // The choice of floating-point representation is implementation-defined.
    // C provides three standard floating-point types: float, double, long double
    // float ⊆ double ⊆ long double (each wider type can represent at least all values of the narrower type).
    // C23 introduces three decimal floating-point types: _Decimal32, _Decimal64, _Decimal128
    // Standard floating types and decimal floating types together are called real floating types.
    // C also provides three complex types: float complex, double complex, long double complex
    // Floating types consist of real floating types and complex types.
    // float f = 1.0f;
    // double d = 1.0;
    // long double ld = 1.0L;
    // _Decimal32 d32 = 1.0df;
    // _Decimal64 d64 = 1.0dd;
    // _Decimal128 d128 = 1.0dl;
    // float complex fc = 1.0f + 1.0f * I;
    // double complex dc = 1.0 + 1.0 * I;
    // long double complex ldc = 1.0L + 1.0L * I;

    // Floating Types
    // │
    // ├── Real Floating Types
    // │     ├── float
    // │     ├── double
    // │     ├── long double
    // │     ├── _Decimal32
    // │     ├── _Decimal64
    // │     └── _Decimal128
    // │
    // └── Complex Types
    //      ├── float complex
    //      ├── double complex
    //      └── long double complex
    return 0;
}
