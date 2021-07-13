/* print all input lines longer than 80 characters. */

#include <stdio.h>
#define THRESH 80

int main ()
{
    int c, len = 0;
    char buffer[THRESH];

    while ((c = getchar()) != EOF) {
        if (len > THRESH)
            putchar(c);
        if (c == '\n') {
            len = 0;
            continue;
        }
        else if (len == THRESH) {
            printf("%s%c", buffer, c);
            len++;
        }
        else {
            buffer[len] = c;
            len++;
        }
    }
}
