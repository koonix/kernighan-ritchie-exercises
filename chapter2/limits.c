/* Write a program to determine the ranges of
 * char, short, int, and long variables, both signed and unsigned,
   by printing appropriate values from standard headers
   and by direct computation (which takes fucking ages).
   Harder if you com pute them:
   determine the ranges of the various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

/* for the given TYPE, define three functions
 * for calculating unsigned TYPE's max,
 * signed TYPE's max and signed TYPE's min. */
#define FN(TYPE) \
    unsigned TYPE u##TYPE##_max(void) { \
        unsigned TYPE n = 0;   \
        while(n != 0) \
            ++n;      \
        return --n;   \
    } \
    signed TYPE s##TYPE##_max(void) { \
        signed TYPE n = 1;  \
        while(n > 0) \
            ++n;     \
        return --n;  \
    } \
    signed TYPE s##TYPE##_min(void) { \
        signed TYPE n = -1;  \
        while(n < 0) \
            --n;     \
        return ++n;  \
    }

FN(char)
FN(short)
FN(int)
FN(long)

int main()
{
    printf("std headers:\n\n");

    printf("uchar:\t0\tto\t%u\n", UCHAR_MAX);
    printf("ushort:\t0\tto\t%u\n", USHRT_MAX);
    printf("uint:\t0\tto\t%u\n", UINT_MAX);
    printf("ulong:\t0\tto\t%lu\n\n", ULONG_MAX);

    printf("schar:\t%d\tto\t%d\n", SCHAR_MIN, SCHAR_MAX);
    printf("sshort:\t%d\tto\t%d\n", SHRT_MIN, SHRT_MAX);
    printf("sint:\t%d\tto\t%d\n", INT_MIN, INT_MAX);
    printf("slong:\t%ld\tto\t%ld\n", LONG_MIN, LONG_MAX);

    printf("\ncomputation:\n\n");

    printf("uchar:\t0\tto\t%u\n", uchar_max());
    printf("ushort:\t0\tto\t%u\n", ushort_max());
    printf("uint:\t0\tto\t%u\n", uint_max());
    printf("ulong:\t0\tto\t%lu\n\n", ulong_max());

    printf("schar:\t%d\tto\t%d\n", schar_min(), schar_max());
    printf("sshort:\t%d\tto\t%d\n", sshort_min(), sshort_max());
    printf("sint:\t%d\tto\t%d\n", sint_min(), sint_max());
    printf("slong:\t%ld\tto\t%ld\n", slong_min(), slong_max());

    return 0;
}
