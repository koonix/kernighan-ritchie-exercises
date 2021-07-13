/* a function for raising x to the power of y */

#include <stdio.h>

int pwr (int base, int exp);

int main () {
    int base=2;
    for (int i=0; i<11; i++)
        printf("%d^%d\t= %d\n", base, i, pwr(base,i));
    return 0;
}

/* raise base to the power of exp, exp >= 0 */
int pwr (int base, int exp) {
    int ans=1;
    for (int i=0; i<exp; i++)
        ans = ans*base;
    return ans;
}
