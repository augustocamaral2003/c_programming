//squeeze.c
//removes chars in s2 from s1

#include <stdio.h>

//squeeze: remove chars in s2 from s1
void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}

int main(void) {
    char c[] = "string before remove";
    char r[] = "string";

    printf("%s\tto remove [%s]\n", c, r);
    squeeze(c, r);
    printf("%s\n", c);

    return 0;
}
