#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void method1(int n) {
    int rows_and_columns = 2 * (n - 1);
    int i_axis = 0, j_axis = 0, main_matrix = 0, aux_matrix = 0;


    for (int i = 0; i <= rows_and_columns; i++){
        for (int j = 0; j <= rows_and_columns; j++){
            main_matrix = (i >= n) * 2 + abs(n - i);
            i_axis = i - (i >= n) * 2 * (i - n + 1);
            j_axis = j - (j >= n) * 2 * (j - n + 1);
            aux_matrix =  (i_axis >= j_axis) * (i_axis - j_axis);
            printf("%d ", main_matrix + aux_matrix);

            /* one liner: ((i >= n) * 2 + abs(n - i)) + ((i - (i >= n) * 2 * (i - n + 1)) >= (j - (j >= n) * 2 * (j - n + 1))) * ((i - (i >= n) * 2 * (i - n + 1)) - (j - (j >= n) * 2 * (j - n + 1))) */
        }
        printf("\n");
    }
} 

void method2(int n) {
    
    for(int k=2*n-1; k>0; k--) {
        for(int i=2*n-1; i>0;i--) {
            if(abs(n-k)>abs(n-i)){
                printf("%d ", abs(n-k)+1);
            }
            else{
                printf("%d ", abs(n-i)+1);
            }
        }
        printf("\n");
    }

} 

int main() {

    int n;
    scanf("%d", &n);

    method2(n);

    return 0;
}