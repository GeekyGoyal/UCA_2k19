/** C program to find the count of the number of vowels and consonants in the given string
*
*   @Aparna Goyal, 1911981092, 24/07/2021 */

#include <stdio.h>
#include <string.h>
#define N 10000

int main() {
    char str[N];
    int Vowels=0, Consonants=0;
    printf("Enter  the string: ");
    fgets(str,N,stdin);
    for(int i = 0; str[i]; i++) 
     {
    	if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
    	{
		
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] =='I' || str[i] == 'O' || str[i] == 'U')
		      Vowels++;
            else
             Consonants++;
        }
 
 	}
    printf("Vowels = %d\n",Vowels);
    printf("Consonants = %d\n",Consonants);
    
    return 0;

}