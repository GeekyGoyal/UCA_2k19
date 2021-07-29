/**  C program to write the function htoi(char* s), which converts a string of hexadecimal digits into its equivalent integer value.
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */

#include <stdio.h>
#include <math.h>

void htoi(char* hex, int len) {
    int sum = 0, j = 0;
    for(int i = len-1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            sum += (hex[i]-48) * pow(16,j);
            j++;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            sum += (hex[i]-55) * pow(16,j);
            j++;
        }
    }
    printf("The Decimal value of %s is %d.", hex, sum);
}

int main() {
    char hex[100];
    printf("Enter a Hexadecimal Number: ");
    scanf("%s",&hex);
    int len = 0;
    while(hex[len] != '\0') {
        len++;
    }
    htoi(hex, len);
   return 0;
}