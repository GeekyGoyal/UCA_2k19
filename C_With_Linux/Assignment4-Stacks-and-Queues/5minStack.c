/**  Problem Link: https://leetcode.com/problems/min-stack/
*
*   @Aparna Goyal, 1911981092, 18/08/2021  */

typedef struct {
    int top;
    int top_min;
    int arrVal[10000];
    int minVal[10000];   
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack)*1);
    stack->minVal[0] = INT_MAX;
    stack->top = -1;
    stack->top_min = -1;
    return stack;
    
}

void minStackPush(MinStack* obj, int val) {
    int min = obj->minVal[obj->top_min];
    if((val <= min) || (obj->top_min == -1)) {
        obj->top_min = obj->top_min + 1;
        obj->minVal[obj->top_min] = val;
    }
    obj->top = obj->top + 1;
    obj->arrVal[obj->top] = val;  
}

void minStackPop(MinStack* obj) {
    if(obj->arrVal[obj->top] == obj->minVal[obj->top_min]) {
      obj->top_min = obj->top_min - 1; 
    }
  obj->top = obj->top - 1;
  
}

int minStackTop(MinStack* obj) {
    return obj->arrVal[obj->top];  
}

int minStackGetMin(MinStack* obj) {
    return obj->minVal[obj->top_min];  
}

void minStackFree(MinStack* obj) {
    free(obj);    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/