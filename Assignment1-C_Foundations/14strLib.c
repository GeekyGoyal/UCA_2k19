/**  C program to write library functions strncpy, strncat, and strncmp, which operate on at most the first n 
* characters of their argument strings. For example, strncpy (char *s, char*  t , size_t n) copies at most n 
* characters of t to s.
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */

#include <stdio.h>
#define MAX 100

/* strncat: concatenate t to end of s; s must be big enough */
void mystrncat(char* s, char* t, int n) {
    while (*s) { 
        s++;
    }
    for(int i = 0; *t != '\0' && i < n; ++i) { 
        *s++ = *t++;
    }
    *s = '\0';
}

/* strncmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int mystrncmp(char* s, char* t, int n) {
    for( ; *s == *t && n > 0; s++, t++, n--) { 
        if(*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

/* strncpy: copy t to s */
void mystrncpy(char* s, char* t, int n) {
     while(n-- > 0 && (*s++ = *t++) != '\0')
        ;

    *s = '\0';
}

int main() {
    char s1[MAX], s2[MAX], s3[MAX], s4[MAX];
    printf("Enter first string: ");
    scanf("%s",s1);
    printf("Enter second string: ");
    scanf("%s",s2);

    //strncat ----> appends n characters from source(str1) to destination(str2).
    mystrncat(s1, s2, 3);
    printf("strncat: %s\n", s1);

    //strncmp ----> compares two strings lexicographically.
    int res = mystrncmp(s1, s2, 3);
    if(res == 0) {
        printf("Strings are equal.\n");
    }
    else if(res < 0) {
        printf("Str1 is smaller than str2.\n");
    }
    else if(res > 0) {
        printf("Str1 is greater than str2.\n");
    }

    //strncpy ----> Copies the first n characters of source(str1) to destination(str2).
    mystrncpy(s1, s2, 2);
    printf("strncpy: %s", s3);

    return 0;
    
}