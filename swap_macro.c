#include <stdio.h>

#define swap(t, x, y) if(1){t temp = x; x = y; y = temp;}

int main(void) {
    int a = 5, b = 6;

    printf("a = %d, b = %d\n", a, b);
    printf("call swap macro\n"); 
    swap(int, a, b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
