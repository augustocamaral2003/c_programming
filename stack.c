#include <stdio.h>

#define MAXVAL 1000

typedef struct {
    int pos;
    double stack[MAXVAL];
} Stack;

void push(Stack* stack, double n) {
    if (stack->pos < MAXVAL)
        stack->stack[stack->pos++] = n;
    else
        printf("stack error: full stack\n");
}

double pop(Stack* stack) {
    if (stack->pos > 0) {
        return stack->stack[--stack->pos];
    } else {
        printf("stack error: empty stack\n");
        return 0.0;
    }
}

int main(void) {
    Stack stack1;
    stack1.pos = 0;

    push(&stack1, 30);
    printf("%f\n", pop(&stack1));

    return 0;
}
