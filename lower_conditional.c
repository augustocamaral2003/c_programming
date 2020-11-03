#include <stdio.h>

//lower_conditional.c
//converts upper-case chars to lower-case using conditional expressions

//lower: converts chars to lower-case
void lower(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 'a' - 'A' : s[i];
    }
}

int main(void) {
    char s[] = "String MayuSfk DDDD 123}{";

    printf("%s\t", s);
    lower(s);
    printf("%s\n", s);

    return 0;
}
