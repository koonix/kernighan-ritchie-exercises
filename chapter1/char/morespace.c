/* squash one or more space characters into just one. */

#include <stdio.h>

int main ()
{
    int c;
    int noecho = 0;
    while ((c = getchar()) != EOF ) {
        if (c == ' ') {
            if (noecho)
                continue;
            noecho = 1;
        } else
            noecho = 0;
        putchar(c);
    }
}
