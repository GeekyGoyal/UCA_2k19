/** Implement bubble sort code and note down time to bubble sort using gettimeoftheday function.
* 
* Link to the run time complexity chart ---->
* https://docs.google.com/spreadsheets/d/1eNlbq7RqIjYqCaGa2xWzvpro6bshx2HSsLbYz_L3xMQ/edit?usp=sharing
* 
*   @Aparna Goyal, 1911981092, 26/07/2021  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int arr[], int n) {
    int temp;
    clock_t t;
    t = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp     = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The Sorted Array is:\n");
    for (int i = 0; i < n; i++) { 
        printf("%d\n", arr[i]);
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken to sort this array is: %lf\n",time_taken);
}

int main()
{
  int n;
  printf("Enter number of elements you want to generate:\n");
  scanf("%d", &n);
  int arr[n];
  char ch;
  printf("Generate: \n a. Random Data Set\n b. Sorted Data Set\n c. Reversely Sorted Data Set\n");
  scanf(" %c", &ch);
  if(ch == 65) {
    //   For random Data Set
      for(int i = 0; i < n; i++) {
          arr[i] = rand()%n;
      }
  }
  else if(ch == 66) {
    //   For Sorted Data Set
      for(int i = 1; i <= n; i++) {
          arr[i] = i;
      }
  }
  else if(ch == 67) {
      //   For Reversely Sorted Data Set
      for(int i = 0; i < n; i++) {
          arr[i] = n - i;
      }
  }
  else if(ch != 65 && ch != 66 && ch != 67) {
      printf("Please enter a valid input.");
  }

  bubbleSort(arr,n);
  return 0;
}