/* check a C program for basic syntax errors
 * like unbalanced parentheses, brackets, braces,
 * single/double quotes, and comments.
 * it's very much like no-comment.c. */

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
    int cmnt[2] = {0}, p[2] = {0}, bk[2] = {0}, br[2] = {0}, sq[2] = {0}, dq[2] = {0};

    while ((c = getchar()) != EOF) {

        if (state == OUT)
        {
            if (c == '/')
                state = ENTERING;
            else if (c == '"') {
                state = STRING;
                ++dq[0];
            }
            else if (c == '\'') {
                state = CHAR;
                ++sq[0];
            }
            else if (c == '(')
                ++p[0];
            else if (c == ')')
                ++p[1];
            else if (c == '[')
                ++bk[0];
            else if (c == ']')
                ++bk[1];
            else if (c == '{')
                ++br[0];
            else if (c == '}')
                ++br[1];
        }

        else if (state == ENTERING)
        {
            if (c == '*') {
                state = IN;
                ++cmnt[0];
            }
            else
                state = OUT;
        }

        else if (state == IN)
        {
            if (c == '*')
                state = LEAVING;
        }

        else if (state == LEAVING)
        {
            if (c == '/') {
                state = OUT;
                ++cmnt[1];
            }
            else
                state = IN;
        }

        else if (state == STRING || state == CHAR)
        {
            if (escape)
                escape = 0;
            else if (c == '\\')
                escape = 1;
            else if (c == '"' && state == STRING) {
                state = OUT;
                ++dq[1];
            }
            else if (c == '\'' && state == CHAR) {
                state = OUT;
                ++sq[1];
            }
        }
    }

    if (cmnt[0] != cmnt[1])
        printf("comment problem\n");
    if (p[0] != p[1])
        printf("parentheses problem\n");
    if (bk[0] != bk[1])
        printf("bracket problem\n");
    if (br[0] != br[1])
        printf("brace problem\n");
    if (sq[0] != sq[1])
        printf("single quote problem\n");
    if (dq[0] != dq[1])
        printf("double quote problem\n");
}
