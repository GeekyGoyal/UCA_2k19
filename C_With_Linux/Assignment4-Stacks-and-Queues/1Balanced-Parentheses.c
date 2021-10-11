/**  C program to check whether the sequence of brackets in the given string is balanced or not.
*
*   @Aparna Goyal, 1911981092, 10/08/2021  */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidExp(char* str) {
    if(str == "") {
         return true;
    }
    char stack[10000];
    int n = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
            stack[n] = str[i];
            n++;
        }
        else{
            switch (str[i]) {
                case ')': {
                    if(n-1 < 0 || stack[n-1] != '(') {
                        return false;
                    }
                    else {
                        n--;
                    }
                    break;
                }
                case '}': {
                    if(n-1 < 0 || stack[n-1] != '{') {
                        return false;
                    }
                    else {
                        n--;
                    }
                    break;
                }
                case ']': {
                    if(n-1 < 0 || stack[n-1] != '[') {
                        return false;
                    }
                    else {
                        n--;
                    }
                    break;
                }
            }
        }
    }
    if(n == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char str[100] = "((a+b+(c-d+f))";
    if(isValidExp(str)) {
        printf("Are the paranthesis Balanced? Yes.");
    }
    else {
        printf("Are the paranthesis Balanced? No.");
    }
    return 0;     
}