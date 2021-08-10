/**  C program to implement a stack.
*
*   @Aparna Goyal, 1911981092, 02/08/2021  */

#include <stdio.h>
#define MAXSIZE 10     

int stack[10];     
int top = 0;  

int isempty() {
   if(top == 0)
      return 1;
   else
      return 0;
}

int isfull() {
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int push(int data) {
   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } 
   else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int main() {
   //Push elements in a stack.
   for(int i = 1; i < MAXSIZE; i++) {
      push(i*i);
   }
   printf("The topmost element in the stack is: %d\n" ,peek());
   while(!isempty()) {
      pop();
   }
   printf("Is the stack empty? %s\n" , isempty() ? "true" : "false");
}