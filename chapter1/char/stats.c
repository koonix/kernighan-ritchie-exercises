/* count the number of spaces, tabs and newlines of input. */

#include <stdio.h>

int main ()
{
    int c;
    int nl = 0, tab = 0, space = 0;
    while ((c = getchar()) != EOF ) {
        if (c == '\n')
            nl++;
        else if (c == '\t')
            tab++;
        else if (c == ' ')
            space++;
    }
    printf ("\n%d spaces, %d tabs, %d newlines.", space, tab, nl);
}
