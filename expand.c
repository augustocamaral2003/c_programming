//expand.c
//expands shorthand a-z or 0-9 into abc...xyz 012..789

#include <stdio.h>
#include <ctype.h>

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

//expand: expands shorthand a-z 0-9 A-Z into longer form
void expand(char f[], char t[]) {
    int i, j;

    for (i = j = 0; f[i] != '\0'; i++, j++) {
        if (f[i+1] == '-' && isalnum(f[i]) && isalnum(f[i+2])) {
            for (char c = f[i]; c < f[i+2]; c++, j++)
                t[j] = c;
            j--;
            i++;
        } else {
            t[j] = f[i];
        }
    }
    t[j] = '\0';
}

int main(void) {
    int len;
    char line[MAXLINE];
    char output[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0) {
        expand(line, output);
        printf("%s", output);
    }

    return 0;
}
