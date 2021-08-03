/** C program to implement selection sort using recursion.
* 
*   @Aparna Goyal, 1911981092, 03/08/2021  */

#include <stdio.h>

void selectionSort(int arr[], int n) {

    //Base Case
    if (n == 1){ 
        return;
    }

    int index = 0;

    for (int i = 1; i < n; i++) {
        if(arr[i] > arr[index])
            index = i;
    }

    int temp = arr[index];
    arr[index] = arr[n-1];
    arr[n-1] = temp;

    selectionSort(arr, n - 1);

}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("The Sorted array is: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}