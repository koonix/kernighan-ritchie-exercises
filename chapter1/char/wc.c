/* count the number of words, characters and lines of input. */

#include <stdio.h>

int main () {
    enum { in = 1, out = 2 };
    int c, nl, nw, nc, state = out;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\t' || c == '\n')
            state = out;
        else if (state == out) {
            state = in;
            nw++;
        }
    }
    printf ("lines: %d\nwords: %d\nchars: %d\n", nl, nw, nc);
}
