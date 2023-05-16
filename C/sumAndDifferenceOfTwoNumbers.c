#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a,b;
    float c,d;

    scanf("%d %d", &a, &b);
    scanf("%f %f", &c, &d);

    printf("%d %d\n", a+b, a-b);

    printf("%.1f %.1f", c+d, c-d); /* Use %.nf to round the number for output purposes, being n => number of decimals */

    /* For further computation this will work, using math.h ---> https://stackoverflow.com/questions/1343890/how-do-i-restrict-a-float-value-to-only-two-places-after-the-decimal-point-in-c */
    float rounded_down = floorf((c+d) * 10) / 10; /* If c+d = 2.55556, rounded_down = 2.5 */
    float nearest = roundf((c+d) * 10) / 10;      /* If c+d = 2.55556, nearest = 2.6 */
    float rounded_up = ceilf((c+d) * 10) / 10;    /* If c+d = 2.55556, rounded_up = 2.6 */
        
    return 0;
}