/** C program to print every third element of the fibonacci series.
* 
*   @Aparna Goyal, 1911981092, 05/08/2021  */

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
  int n = 5;

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