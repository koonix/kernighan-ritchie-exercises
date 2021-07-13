/* print the input one word per line. */

#include <stdio.h>

int main () {
    enum { out = 0, in = 1 };
    int c, state = out;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            state = in;
            putchar(c);
        } else if (state == in) {
            state = out;
            putchar('\n');
        }
    }
}
