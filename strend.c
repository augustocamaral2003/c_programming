//strend.c
//verifies if string b appears at the end of string a with pointers

#include <stdio.h>

//strend: verifies if b appears at the end of a
int strend(char *a, char *b) {
    char* pos = b;
    while (*a++ != '\0')
        ;
    while (*b++ != '\0')
        ;
    while (b != pos)
        if (*(--b) == *(--a))
            continue;
        else
            return 0;
    return 1;
}

int main(void) {
    char a[10] = "string";
    char b[10] = "ring";
    char c[10] = "yng";

    printf("a = %s, b = %s, c = %s\n", a, b, c);
    printf("strend(a, b) = %d, strend(a, c) = %d\n", strend(a, b), strend(a, c));
    printf("strend(b, a) = %d\n", strend(b, a));

    return 0;
}
