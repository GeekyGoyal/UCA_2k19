/**  C program to implement a queue.
*
*   @Aparna Goyal, 1911981092, 08/08/2021  */

#include <stdio.h>
#include <stdbool.h> 
#define MAXSIZE 10

int queue[MAXSIZE];
int cs = 0;
int front = 0;
int rear = 1;

bool isEmpty() {
    // Check if the queue is empty
    return cs == 0;
}

bool isFull() {
    // Check if the queue is full
    return cs == MAXSIZE;
}

int peek() {
    // Get the value of the front of the queue without removing it
    return queue[front];
}

void enqueue(int data) {
    // Add an element to the end of the queue
    if(!isFull()) {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = data;
        cs++;
    }
} 

int dequeue() {
    // Remove an element from the front of the queue
    if(!isEmpty()) {
        front = (front + 1) % MAXSIZE;
        cs--;
    }
}

int main() {
    //Push elements in a queue.
    for(int i = 1; i < MAXSIZE; i++) {
        enqueue(i*i);
    }
    printf("The front-most element in the queue is: %d\n" ,peek());
    while(!isEmpty) {
        dequeue();
    }
    printf("Is the queue empty? %s\n" , isEmpty() ? "false" : "true");

}