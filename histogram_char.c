//histogram_char.c
//outputs a histogram showing the occurence of chars in input

#include <stdio.h>

int main(void) {
    int c;
    int histogram[95] = {};
    
    while ((c = getchar()) != EOF) {
        histogram[c - ' ']++;
    }

    for (int i = 0; i < 95; i++) {
        if (histogram[i]) {
            printf("[%c] ", i + ' ');
            while(histogram[i]--) {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}
