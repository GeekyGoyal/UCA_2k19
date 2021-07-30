/**  C program to write the function strrindex( char* s , char* t ) which returns the position of the rightmost 
* occurrence of t in s , or - 1 if there is none
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */

#include <stdio.h>
#define MAXLINE 1000


int getLine(char d[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    d[i] = c;
  }
  /* Don't include newline char */
  d[i] = '\0';
  return i;
}

/* reverse a string */
void reverse(char from[], char to[], int len) {
  int i, j;

  for (i = 0, j = len; i < len; i++) {
    to[i] = from[--j];
  }
  to[i] = '\0';
}

int strrindex(char s[], char t[]) {
  int idx, i, j, k;
  idx = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') {
      idx = i;
    }
  }
  return idx;
}

int main(void) {
  int c, i;
  char d[MAXLINE]; /* Will hold initial string for `t` */
  char s[MAXLINE], t[MAXLINE]; /* `t` will be reversed string */
    printf("Enter the first string: ");
    scanf("%s",s);
    printf("Enter the second string: ");
    scanf("%s",t);
    i = strrindex(s, t);
    printf("Rightmost occurrence: %d\n", i);
}