/** C program implement the tower of hanoi function.
* 
*   @Aparna Goyal, 1911981092, 05/08/2021  */

#include <stdio.h>

void TowerOfHanoi(int n, char src, char helper, char dest) {
    //Base Case
    if(n == 0) {
        return;
    }
    //Recursive Case, move n-1 disks from src to helper
    TowerOfHanoi(n-1, src, dest, helper);
    printf("Shift Disk %d from %c to %c.\n", n, src, dest);
    TowerOfHanoi(n-1, helper, src, dest);
}

int main() {
    int n;
    printf("Enter the number of disks you want to shift from A to C: ");
    scanf("%d",&n);
    TowerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}