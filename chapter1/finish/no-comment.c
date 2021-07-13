/* remove all comments from a c program. */

#include <stdio.h>

#define OUT      0
#define ENTERING 1
#define IN       2
#define LEAVING  3
#define STRING   4
#define CHAR     5

int main()
{
    int c, state = 0, escape = 0;

    while ((c = getchar()) != EOF) {

        if (state == OUT)
        {
            if (c == '/')
                state = ENTERING;
            else if (c == '"') {
                state = STRING;
                putchar(c);
            }
            else if (c == '\'') {
                state = CHAR;
                putchar(c);
            }
            else
                putchar(c);
        }

        else if (state == ENTERING)
        {
            if (c == '*')
                state = IN;
            else {
                state = OUT;
                putchar('/');
                putchar(c);
            }
        }

        else if (state == IN)
        {
            if (c == '*')
                state = LEAVING;
        }

        else if (state == LEAVING)
        {
            if (c == '/')
                state = OUT;
        }

        else if (state == STRING || state == CHAR)
        {
            putchar(c);
            if (escape)
                escape = 0;
            else if (c == '\\')
                escape = 1;
            else if (c == '"' && state == STRING)
                state = OUT;
            else if (c == '\'' && state == CHAR)
                state = OUT;
        }
    }
}
