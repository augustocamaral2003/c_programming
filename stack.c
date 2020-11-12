//stack.c
//implementation of stack in c

#include <stdio.h>

#define MAXVAL 1000

typedef struct {
    int pos;
    double stack[MAXVAL];
} Stack;

//createStack: return stack at position 0
Stack createStack(void) {
    Stack stack;
    stack.pos = 0;

    return stack;
}

//push: push value into stack, update pos
void push(Stack* stack, double n) {
    if (stack->pos < MAXVAL)
        stack->stack[stack->pos++] = n;
    else
        printf("stack error: full stack\n");
}

//pop: pop value from stack, update pos
double pop(Stack* stack) {
    if (stack->pos > 0) {
        return stack->stack[--stack->pos];
    } else {
        printf("stack error: empty stack\n");
        return 0.0;
    }
}

int main(void) {
    Stack stack = createStack();

    push(&stack, 30);
    printf("%f\n", pop(&stack));

    return 0;
}
