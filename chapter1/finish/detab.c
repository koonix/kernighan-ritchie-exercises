/* replace tabs in input with proper number of
 * blanks to reach the next tabstop. */

#include <stdio.h>
#define TABSTOP 4

int main() {
    int c, n = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0, m = n; i < TABSTOP - (m % TABSTOP); i++) {
                putchar(' ');
                n++;
            }
        }
        else if (c == '\n') n = 0;
        else {
            putchar(c);
            n++;
        }
    }
}
