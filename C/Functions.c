#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b; /* using conditional statements */
    /* return a * (a>b) + b * (b>a); /* without using cond. statements */
}

int max_of_four(int a, int b, int c, int d) {

    return max(max(a,b),max(c,d));

}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
