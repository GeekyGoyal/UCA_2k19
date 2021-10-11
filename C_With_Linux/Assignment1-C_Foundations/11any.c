/**  C program to write the function any(char* s1 , char* s2), which returns the first location in the string1 
* where any character from the string2 occurs, or -1 if s1 contains no characters from s2
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */

#include <stdio.h>

int any (char s1[], char s2[])
{
    int i = 0;
    int j = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s2[j] == s1[i]) { 
                return i;
            }                
        }
    }
    // Default return of -1 to signify no position location found
    return -1 ;
}

int main() {
    char s1[100];
    char s2[100]; 
    printf("Enter the first string: ");
    scanf("%s",s1);
    printf("Enter the second string: ");
    scanf("%s",s2);
    printf("Location: %i\n\n", any (s1, s2));
    return 0;
}