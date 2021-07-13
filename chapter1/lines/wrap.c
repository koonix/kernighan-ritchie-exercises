/* hard wrap lines longer than 80 characters. */

#include <stdio.h>
#define WRAP 10
#define BUFSIZE 1000

void wrap(char line[]);

int main()
{
    int c, i = 0;
    char line[BUFSIZE];
    while ((c = getchar()) != EOF) {
        line[i] = c;
        i++;
        if (c == '\n') {
            line[i] = '\0';
            i = 0;
            wrap(line);
        }
    }
}

void wrap(char line[])
{
    int i, c;
    for (i = 0, c = 0; line[i] != '\0'; ++i, ++c) {
        if (c == WRAP) {
            putchar('\n');
            c = 0;
        }
        putchar(line[i]);
    }
}
