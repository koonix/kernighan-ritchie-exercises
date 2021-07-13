/* list a table of temperatures in celcius, plus
 * it's conversion to fahrenheit. */

#include <stdio.h>

int main()
{
    printf("celcius to fahrenheit\n\n");

    for (int celcius = 40; celcius >= -20; celcius -= 2)
        printf("%3.0d %6.1f\n", celcius, 9.0/5.0*celcius+32);
}
