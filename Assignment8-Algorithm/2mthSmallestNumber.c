/**  C program to find Mth smallest number in an unsorted array of size N.
* Try to solve with Run time complexity <= O(N) and additional space request is O(1). 
*
* Example: {5,4,1,3,2} M = 2. Then 2nd smallest is 2
*
*   @Aparna Goyal, 1911981092, 20/08/2021  */

#include <stdio.h>

void swap(int a[], int i, int j) {
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void mthSmallest(int arr[], int left, int right) {
    // USING QUICKSORT (TIME COMPLEXITY TO SORT ---> O(N LOG N))

    /*Assuming first element to be pivot*/
    int pivot = left;
    int final_pivot = left;
 
    /*If end of array reached*/
    if(left >= right) {
	    return;
    }
   
    /*Finding correct position of pivot in the array*/
    for(int i = left + 1; i <= right; i++) {
        if(arr[pivot] > arr[i]) {
            swap(arr, i, ++final_pivot);
        }
    }
    swap(arr, pivot, final_pivot);         //moving pivot to correct position
    mthSmallest(arr, left, final_pivot-1);  //recursive call to sort array elements to the left of pivot
    mthSmallest(arr, final_pivot+1, right); //recursive call to sort array elements to the right of pivot
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int m;
    printf("Enter the number for which you want to find the mth smallest element: ");
    scanf("%d", &m);
    mthSmallest(arr, 0, n);
    printf("M'th smallest element is: %d ", arr[m]);
    return 0;
}