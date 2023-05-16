#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sumdigits(int n){

    int s = 0;

    while (n){ /* When n is divided by 10, it will reach 0 at some point and set while condition to false */
        s += n%10;
        n /= 10;
    }

    return s;

} 

int main() {
	
    int n;
    scanf("%d", &n);

    printf("%d\n", n / 10000 + (n % 10000)/1000  + (n % 1000)/100 + (n % 100)/10 + n % 10); /* this will work only for 5 digits number */

    printf("%d\n", sumdigits(n));

    return 0;
}