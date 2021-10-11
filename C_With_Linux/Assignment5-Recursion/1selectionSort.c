/** C program to implement selection sort using recursion.
* 
*   @Aparna Goyal, 1911981092, 03/08/2021  */

#include <stdio.h>

void selectionSort(int arr[], int beginIndex, int n) {

    if(beginIndex >= n-1) {
        return;
    }
    int minIndex = beginIndex;
    for(int i = beginIndex; i < n; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    int temp = arr[minIndex];
    arr[minIndex] = arr[beginIndex];
    arr[beginIndex] = temp;

    selectionSort(arr, beginIndex + 1,  n);

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
    selectionSort(arr, 0, n);
    printf("The Sorted array is: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}