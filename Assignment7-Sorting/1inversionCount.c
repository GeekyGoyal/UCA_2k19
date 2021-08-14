/**  C program to count number of pairs such that for any 2 elements of the array a[i] > a[j], for i < j.
*
*   @Aparna Goyal, 1911981092, 14/08/2021  */

#include <stdio.h>

int merge(int* arr, int start, int mid, int end) {
    int i = start;
    int j = (mid + 1);
    int k = start;
    int temp[100000];
    int count = 0; // cross inversions
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }
    //fill the array if some elements are left in one of the arrays
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= end) {
        temp[k++] = arr[j++];
    }
    //copy all elements back to array arr
    for(int i = start; i <= end; i++) {
        arr[i] = temp[i];
    }
    return count;
}

int inversionCount(int* arr, int start, int end) {
    //Base Case
    if(start >= end) {
        return 0;
    }
    //Merge Sort
    int mid = (start + end)/2;
    int x = inversionCount(arr, start, mid);
    int y = inversionCount(arr, mid+1, end);
    int z = merge(arr, start, mid, end); //cross inversions
    return x+y+z;
}


int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The number of inversions are: %d", inversionCount(arr, 0, n-1));
    return 0;
}