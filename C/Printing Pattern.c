#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);

    int rows_and_columns = 2 * (n - 1);
    int i_axis = 0, j_axis = 0, main_matrix = 0, aux_matrix = 0;


    for (int i = 0; i <= rows_and_columns; i++){
        for (int j = 0; j <= rows_and_columns; j++){
            main_matrix = (i >= n) * 2 + abs(n - i);
            i_axis = i - (i >= n) * 2 * (i - n + 1);
            j_axis = j - (j >= n) * 2 * (j - n + 1);
            aux_matrix =  (i_axis >= j_axis) * (i_axis - j_axis);
            printf("%d ", main_matrix + aux_matrix);
        }
        printf("\n");
    } 

    return 0;
}