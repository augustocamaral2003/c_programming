#include <stdio.h>

//wrap.c
//wrapes lines greater than WRAP into next line

#define MAXLINE 1000
#define WRAP    80

//getine: read line into s, return length 
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

int main(void) {
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0) {
        if (len < WRAP) {
            printf("%s", line);
        } else {
            for (int i = 0; i < len; ++i) {
                if (i % WRAP != 0) {
                    putchar(line[i]);
                } else {
                    putchar('\n');
                    putchar(line[i]);
                }
            }
        }
    }

    return 0;
}
