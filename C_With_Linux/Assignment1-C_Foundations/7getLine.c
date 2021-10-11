/**  C program to print all input lines that are longer than 80 characters.
* 
*   @Aparna Goyal, 1911981092, 29/07/2021  */


#include <stdio.h>
#define MAXLINE 1000
#define MINLENGTH 80


int getLine(char line[], int limit)
{
    int c, i = 0;
    for (i = 0; i < limit-1 && (c=getchar())!=EOF && c!='\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
    }
    line[++i] = '\0';
    return i;
}

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > MINLENGTH) {
            puts(line);
        }
    }

    return 0;
}