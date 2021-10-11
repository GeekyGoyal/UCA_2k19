/** Problem Link: https://leetcode.com/problems/implement-stack-using-queues/
*
*   @Aparna Goyal, 1911981092, 18/08/2021  */

typedef struct {
    int *q1;
    int *q2; 
    int top1;
    int top2;
    int front;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s = (MyStack*) malloc(sizeof(MyStack));
    s -> q1 = (int*) malloc(100000 * sizeof(int));
    s -> q2 = (int*) malloc(100000 * sizeof(int));
    s -> top1 = -1;
    s -> top2 = -1;
    s -> front = 0;
    return s;    
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj -> top1 += 1;
    obj -> q1[obj -> top1] = x;  
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(obj -> top1 == -1) {
        return -1;
    }
    while(obj -> front != obj -> top1) {
        obj -> top2 += 1;
        obj -> q2[obj -> top2] = obj -> q1[obj -> front];
        obj -> front += 1;
    }
    int data;
    data = obj -> q1[obj -> front];
    obj -> front += 1;
    while(obj -> top2 != -1) {
        obj -> front -= 1;
        obj -> q1[obj -> front] = obj -> q2[obj -> top2];
        obj -> top2 -= 1;
    }
    return data;
  
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj -> q1[obj -> top1];  
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj -> top1 == obj -> front - 1) {
      return true;
    }
  else {
      return false;
  }
}

void myStackFree(MyStack* obj) {
     if(obj) {
        free(obj -> q1);
     }
    free(obj);    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/