/**  C program to Print n numbers in Fibonacci series that are even.
*
*   @Aparna Goyal, 1911981092, 20/08/2021  */

#include <stdio.h>

int evenFibonacci(int n);

int evenFibonacci(int n){
    if(n == 0 || n == 1)
        return n;

    // Recursive algorithm
    return evenFibonacci(n - 1) + evenFibonacci(n - 2);
}

int main() {
  // The number of even Fibonacci numbers to print:
  int n;
  printf("Enter the number of even fibonacci numbers you want to print: ");
  scanf("%d", &n);
  int x;
  for(int i = 0; n > 0; i++){
    x = evenFibonacci(i);
    
    // Check if the number returned is even
    if(x % 2 == 0){
      printf("%d ", x);
      n--;
    }
  }
  return 0;
}