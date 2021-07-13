/* this is the same as top.c,
 * but getting the lines is done in a function (readline()). */

#include <stdio.h>
#define MAXLEN 1000

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
        line[len] = c;
        if (c != '\n' && len < lim -1) {
            len++;
            continue;
        }
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
