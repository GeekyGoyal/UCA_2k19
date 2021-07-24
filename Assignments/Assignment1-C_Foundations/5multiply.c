/** C program to multiply the given 2 matrices.
* 
*   @Aparna Goyal, 1911981092, 24/07/2021  */

#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX];
    int arows, acols, brows, bcols;
    int sum = 0;
    printf("Enter the rows and columns of first matrix: ");
    scanf("%d %d", &arows, &acols);
    printf("Enter the elements of first matrix:\n");
    for(int i = 0; i < arows; i++) {
        for(int j = 0; j < acols; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the rows and columns of second matrix: ");
    scanf("%d %d", &brows, &bcols);
    
    if(brows != acols) {
        printf("Number of rows of second matrix must be equal to number of columns of first matrix");
    }
    else { 
        printf("Enter the elements of second matrix:\n");
        for(int i = 0; i < brows; i++) {
            for(int j = 0; j < bcols; j++) {
                scanf("%d", &b[i][j]);
            }
        }
    }
    printf("\n");

    for(int i = 0; i < arows; i++) {
        for(int j = 0; j < bcols; j++) {
            for(int k = 0; k < brows; k++) {
                sum += a[i][k] * b[k][j];
            }
            product[i][j] = sum;
            sum=0;
        }
    }

    printf("Resultant matrix:\n");
    for(int i = 0; i < arows; i++) {
        for(int j = 0; j < bcols; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    return 0;
}