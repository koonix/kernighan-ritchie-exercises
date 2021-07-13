/* print the longest line and it's length. */

#include <stdio.h>
#define MAXLEN 1000

void copy (char src[], char dest[]);

int main ()
{
    int c, len = 0, toplen = 0;
    char line[MAXLEN], top[MAXLEN];

    while ((c = getchar()) != EOF) {
        line[len] = c;
        if (c != '\n') {
            len++;
            continue;
        }
        if (len > toplen) {
            line[len] = '\0';
            toplen = len;
            copy (line, top);
        }
        len = 0;
    }
    if (toplen == 0)
        printf("all lines are empty.\n");
    else
        printf("longest line (length %d):\n%s\n", toplen, top);
}

void copy (char src[], char dest[]) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}
