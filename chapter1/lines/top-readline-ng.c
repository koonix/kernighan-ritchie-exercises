/* this is like top-readline.c,
 * but it correctly prints the length of arbitrarily long
 * lines, and as much as possible of the text (bound by MAXLEN). */

#include <stdio.h>
#define MAXLEN 10

int readline (char line[], int lim);
void copy (char src[], char dest[]);

int main ()
{
    int c, len = 0, toplen = 0;
    char line[MAXLEN], top[MAXLEN];

    while ((len = readline(line, MAXLEN)) >= 0) {
        if (len > toplen) {
            toplen = len;
            copy (line, top);
        }
    }
    if (toplen == 0)
        printf("all lines are empty.\n");
    else
        printf("longest line (length %d):\n%s\n", toplen, top);
}

int readline (char line[], int lim)
{
    int c, len = 0;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (len < lim - 1)
                line[len] = c;
            len++;
            continue;
        }
        if (len > lim-1) {
            line[lim-2] = '~';
            line[lim-1] = '\0';
        } else
            line[len] = '\0';
        return len;
    }
    return -1;
}

void copy (char src[], char dest[])
{
    int i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}
