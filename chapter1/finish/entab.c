/* replace tabs in input with proper number of
 * blanks to reach the next tabstop.
 * if either a tab or blank gets us to the next
 * tabstop, use blank. */

#include <stdio.h>
#define TABSTOP 4

int main()
{
    int c, n = 0, blank = 0;
    while ((c = getchar()) != EOF) {
        ++n;
        if (n > TABSTOP) n = 1;
        if (c == ' ') {
            ++blank;
            if (n != TABSTOP) continue;
            if (blank == 1) putchar(' ');
            else putchar('\t');
            blank = 0;
            n = 0;
        }
        else {
            if (c == '\n' || c == '\t') n = 0;
            for (; blank > 0; blank--) putchar(' ');
            putchar(c);
        }
    }
}
