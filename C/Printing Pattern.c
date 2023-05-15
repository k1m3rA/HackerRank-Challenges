#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);

    int rows_and_columns = 2 * n - 1;

    for (int i = 0; i < rows_and_columns; i++){
        for (int j = 0; j < rows_and_columns; j++){
            printf("%d", n);
        }
        printf("\n");
    } 

    return 0;
}