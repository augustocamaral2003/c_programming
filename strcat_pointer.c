#include <stdio.h>

void nstrcat(char *a, char *b) {
    while (*(++a) != '\0')
        ;
    while ((*a++ = *b++) != '\0') 
        ;
}

int main(void) {
    char a[10] = "string a";
    char b[10] = "string b";

    printf("%s %s\n", a, b);
    nstrcat(a, b);
    printf("%s",  a);

    return 0;
}
