/**  C program to implement a stack.
*
*   @Aparna Goyal, 1911981092, 02/08/2021  */

#include <stdio.h>
#define MAXSIZE 10     

int stack[MAXSIZE];     
int top = 0;  

int isempty() {
   // Check if the stack is empty.
   if(top == 0)
      return 1;
   else
      return 0;
}

int isfull() {
   // Check if the stack is full
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   // Get the value of the top element without removing it
   return stack[top];
}

int push(int data) {
   // Add an element to the top of a stack.
   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } 
   else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int pop() {
   // Remove an element from the top of a stack.
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }
    else {
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