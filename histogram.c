//histogram.c
//outputs a histogram showing the lenght of the imput words

#include <stdio.h>

int main(void) {
    int c, l = 0;
    int histogram[100] = {};
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++histogram[l];
            l = 0;
        } else {
            ++l;
        }
    }

    for (int i = 0; i < 100; i++) {
        if (histogram[i]) {
            printf("%-2d | ", i);
            while(histogram[i]--) {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}
