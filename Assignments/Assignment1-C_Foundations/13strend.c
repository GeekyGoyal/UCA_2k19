/**  C program to write the function strend(char *s , char* t) , which returns 1 if the string t occurs at the 
* end of the string s, and zero otherwise
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */

#include <stdio.h>
#include <string.h>
#define MAX 100

int strend(char *, char *);

/* strend: returns 1 if t occurs at the end of s, and zero otherwise */
int strend(char *s, char *t)
{
	s += strlen(s) - strlen(t); /* advance the pointer */
	while (*s && *t)
		if (*s++ != *t++)
			return 0;;
	return 1;
}

int main(void)
{
	char str1[MAX];
	char str2[MAX];
    printf("Enter the first string: ");
    scanf("%s",str1);
    printf("Enter the second string: ");
    scanf("%s",str2);

	printf("%i", strend(str1, str2));
	
	return 0;
}