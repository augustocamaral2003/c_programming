#include <stdio.h>

//reverse.c
//reverses input line by line

#define MAXLINE 1000

//getline: read line into s, return length
int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

//reverse: reverse string s
void reverse(char s[], int l) {
    char c;
    int i;

    for (i = 0; i < l/2; i++) {
        c = s[i];
        s[i] = s[l-i-1];
        s[l-i-1] = c;
    }
}

int main(void) {
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}
