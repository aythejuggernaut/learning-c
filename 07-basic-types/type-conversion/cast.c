#include <stdio.h>

int main(void) {
    float f, frac_part;

    frac_part = f - (int)f;
    // The cast expression ( int ) f represents the result of converting the
    // value of f to type int. C's usual arithmetic conversions then require
    // that ( int ) f be converted back to type fl o a t before the subtraction
    // can be performed. The difference between f and ( int ) f is the
    // fractional part of f , which was dropped during the cast.
    // Cast expressions enable us to document type conversions that would take
    // place anyway and to override the usual conversions.
    int i = (int) f;

    // They also enable us to overrule the compiler and force it to do conversions that we want.
    float quotient;
    int dividend, divisor;
    quotient = dividend / divisor;

    // As it's now written, the result of the division—an integer- -will be
    // converted to float form before being stored in quotient. We probably want
    // dividend and divisor converted to float before the division, though,
    // so that we get a more exact answer. A cast expression will do the trick
    quotient = (float) dividend / divisor;

    // divisor doesn't need a cast, since casting dividend to float forces
    // the compiler to convert divisor to float also. Incidentally, C regards
    // (type-name) as a unary operator. Unary operators have higher precedence
    // than binary operators, so the compiler interprets
    
    // dividend / divisor is evaluated first, yielding an int. Then the result
    // is converted to float.
    quotient = (float) (dividend / divisor);

    // divisor doesn't need a cast, since casting dividend to float forces
    // the compiler to convert divisor to float also.
    quotient = (float) dividend / divisor;

    // as

    // The extra parentheses aren't necessary, but they make the order of
    // operations explicit.
    quotient = ((float) dividend) / divisor;

    // dividend / divisor is evaluated first, yielding an int. Then the result
    // is converted to float.
    quotient = dividend / (float) divisor;

    // or

    // both dividend and divisor are converted to float before the division
    quotient = (float) dividend / (float) divisor;

    return 0;
}