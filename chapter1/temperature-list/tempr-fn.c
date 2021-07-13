/* same as tempr.c, but conversion
 * from celc to fahr is done in a function. */

#include <stdio.h>

float ctof(float c);

int main()
{
    printf("celcius to fahrenheit\n\n");

    for (int c = -10; c >= 40; c += 2)
        printf("%3.0d %6.1f\n", c, ctof(c));
}

float ctof(float c)
{
    return 9.0/5.0*c+32;
}
