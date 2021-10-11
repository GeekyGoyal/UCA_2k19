/**  C program to check if the given string is palindrome or not.
* 
*   @Aparna Goyal, 1911981092, 24/07/2021  */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define N 100

bool isPalindrome(char * str){
    int len = strlen(str);
    int low = 0, high = len - 1;
    
    while(low < high){
        if(isalnum(str[low]) && isalnum(str[high])) {
            if(tolower(str[low]) != tolower(str[high])) { 
                return false;
            }
            low++;
            high--;
        }
        if(!isalnum(str[low])) { 
            low++;
        }
        if(!isalnum(str[high])) { 
            high--;        
        }
    }
    return true;
}

int main() {
    char str[N];
    printf("Enter the string:\n");
    fgets(str, N, stdin);
    if(isPalindrome(str)) {
        printf("true");
    }
    else 
    printf("false");

    return 0;
}
