/* C program to Implement a stack(operations - push, pop, is_empty,peek) using a Linked List.
*
* @Aparna Goyal, 1911981092, 02/09/2021 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next; 
    int data;           
};

struct node *head = NULL;

void push(int value) {
    // create new node
    struct node *dummy = malloc(sizeof(struct node));
    dummy -> data = value;

    //make the new node points to the head node
    dummy -> next = head;

    // make the new node as head node, so that head will always point the last inserted data
    head = dummy;
}


void pop() {
    //temp is used to free the head node
    struct node *temp;

    if(head == NULL) {
        printf("Stack is Empty\n");
    }
    else {
        printf("Poped element = %d\n", head->data);

        //backup the head node
        temp = head;

        //make the head node points to the next node.
        //logically removing the node
        head = head->next;

        //free the poped element's memory
        free(temp);
    }
}

void printList() { 
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL) {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Linked List\n");
    printList();
    pop();
    printf("After the pop, the new linked list\n");
    printList();
    pop();
    printf("After the pop, the new linked list\n");
    printList();

    return 0;
}

