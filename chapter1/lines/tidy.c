/* remove trailing spaces and tabs from each line of input,
 * and remove empty lines (lines that are only spaces/tabs). */

#include <stdio.h>
#define BUFSIZE 1000

int main()
{
    int c, nl, i = 0;
    char buf[BUFSIZE];

    while ((c = getchar()) != EOF)
    {
        if (c == '\n') {
            if (nl == 0)
                putchar(c);
            nl = 1;
            i = 0;
        }
        else if (c == ' ' || c == '\t') {
            buf[i] = c;
            i++;
        }
        else {
            buf[i] = '\0';
            printf("%s%c", buf, c);
            i = 0;
            nl = 0;
        }
    }
}
