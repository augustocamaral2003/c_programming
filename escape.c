//escape.c
//shows escape sequences visibly

#include <stdio.h>

int main(void) {
    char c;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            printf("[\\n]\n");
        else if (c =='\t')
            printf("[\\t]\t");
        else
            putchar(c);
    }

    return 0;
}
