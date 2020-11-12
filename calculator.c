//calculator.c
//calculator in polish notation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXLINE 1000
#define MAXVAL  100

int sp = 0;
double val[MAXVAL];

//getline: read line into s, return length
int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i <= lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

//push: push f to stack
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

//pop: pop and return top value from stack
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int j = 0;
char line[MAXLINE];

//getop: get next char or operand
int getop(char s[]) {
    int i, c;

    if (line[j] == '\0') {
        if (getline(line, MAXLINE) == 0)
            return EOF;
        else
            j = 0;
    }

    while ((s[0] = c = line[j++]) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c))
        while (isdigit(s[++i] = c = line[j++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[j++]))
            ;

    s[i] = '\0';
    j--;

    return NUMBER;
}

int main(void) {
    int type;
    double op2;
    char s[MAXOP];
    double last = 0.0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero operand");
                break;
            case 'S':
                push(sin(pop()));
                break;
            case 'C':
                push(cos(pop()));
                break;
            case 'T':
                push(tan(pop()));
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case 'l':
                push(last);
                break;
            case '\n':
                last = pop();
                printf("\t=%.8g\n", last);
                break;
            case 'R':
                op2 = pop();
                push(pow(pop(), 1/op2));
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
    }
    
    return 0;
}
