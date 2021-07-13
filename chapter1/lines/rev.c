/* reverses the input.
 * it puts each line into a string and gives it to rev(),
 * which reverses the given string. */

#include <stdio.h>
#define BUFSIZE 1000

void rev(char line[]);

int main() {
    char line[BUFSIZE];
    int c, i = 0;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            line[i] = c;
            i++;
            continue;
        }
        line[i] = '\0';
        i = 0;
        rev(line);
        printf("%s\n", line);
    }
}

void rev(char s[])
{
    int n, i;
    for (n = 0; s[n] != '\0'; ++n);
    for (i = 0; i < n / 2; ++i) {
        char c = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = c;
    }
}
