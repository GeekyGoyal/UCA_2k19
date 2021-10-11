/** C program to print a pyramid having a given number of  steps.
* 
*   @Aparna Goyal, 1911981092, 24/07/2021  */


#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for(int j = 1;j <= i; j++) {
            printf("# ");
        }
        printf("\n");
    }
    return 0;
}
