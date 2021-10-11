/**  C program to write a function reverse(char* s)  that reverses the character string.
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */

#include <stdio.h>
#define SIZE 1000

void reverse(char* str, int len) {
    int p1 = 0;
    int p2 = len-1;
    while(p1 < p2) {
        char temp = str[p1];
        str[p1++] = str[p2];
        str[p2--] = temp;
    }
    printf("The reversed string is: %s", str);
}

int main() {
    char str[SIZE];
    printf("Enter the String: ");
    fgets(str, SIZE, stdin);
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    reverse(str, len);
    return 0;
}