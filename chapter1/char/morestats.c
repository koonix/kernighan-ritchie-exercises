/* count the number of occurences of each digit(0-9),
 * white space characters (blank, tab, newline), and of
 * all other characters. */

#include <stdio.h>

int main () {
    int nother = 0, nwhite = 0, c;
    int ndigit[10]={0};
    while ((c = getchar()) != EOF) {
        if (c==' '||c=='\t'||c=='\n')
            nwhite++;
        else if (c>='0'&&c<='9')
            ndigit[c-'0']++;
        else
            nother++;
    }
    for (int i=0; i<10; i++)
        printf("digit %d: %d\n", i, ndigit[i]);
    printf("whitesp: %d\nother: %d\n", nwhite, nother);
}
