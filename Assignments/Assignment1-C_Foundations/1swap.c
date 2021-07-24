/** C program to swap two numbers without using a third variable.
* 
*   @Aparna Goyal, 1911981092, 24/07/2021  */

#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("The swapped numbers are: %d %d",a,b);

    return 0;
}
