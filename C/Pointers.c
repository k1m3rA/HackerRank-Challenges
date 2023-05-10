#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    int sum = *a + *b;
    
    *b = abs((*a - *b));
    *a = sum;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb); /* pa and pb without * is the address of the pointer. By passing them to the function we are defining int *a = &a and int *b = &b in the update() function */
    printf("%d\n%d", a, b);

    return 0;
}