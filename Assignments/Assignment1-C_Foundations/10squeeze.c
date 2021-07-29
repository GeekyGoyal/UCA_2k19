/**  C program to write an alternate version of squeeze(char*s1 , char* s2) that deletes each character in s1 that matches any character in the string s2.
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */

#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j, m;
	for(m = 0; s2[m] != '\0'; m++)
	{
		for(i = j = 0; s1[i] != '\0'; i++)
		{
			if(s1[i] != s2[m])
				s1[j++] = s1[i];
		}
		s1[j] = '\0';
	}
}

int main() {
	char s1[100], s2[100];
	printf("Enter the 1st string: ");
    scanf("%s",s1);
	printf("Enter the 2nd string: ");
	scanf("%s",s2);
	squeeze(s1, s2);
    printf("%s", s1);
    return 0;	
}