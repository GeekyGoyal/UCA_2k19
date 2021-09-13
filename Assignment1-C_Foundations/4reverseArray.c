/** C Program to reverse the given 1 D array.
* 
*   @Aparna Goyal, 1911981092, 24/07/2021  */

#include <stdio.h>

void reverseArray(int *arr, int size) {
    int temp;
    for(int i = 0; i < size/2; i++) {
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    reverseArray(arr, size);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}