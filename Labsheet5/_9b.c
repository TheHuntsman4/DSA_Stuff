#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    double items[MAX_SIZE];
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, double value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

double evaluatePostfix(char *expression) {
    Stack stack;
    initializeStack(&stack);
    int len = strlen(expression);
    int i;
    double operand1, operand2;

    for (i = 0; i < len; i++) {
        if (isdigit(expression[i])) {
            double num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(&stack, num);
        } else if (expression[i] != ' ') {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(1);
            }
        }
    }
    return pop(&stack);
}

double evaluatePrefix(char *expression) {
    Stack stack;
    initializeStack(&stack);
    int len = strlen(expression);
    int i;
    double operand1, operand2;

    for (i = len - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            double num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i--;
            }
            i++; 
            push(&stack, num);
        } else if (expression[i] != ' ') {
            operand1 = pop(&stack);
            operand2 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(1);
            }
        }
    }
    return pop(&stack);
}

int main() {
    int caseOperator;
    char expression[100];
    double result;

    printf("Menu:\n");
    printf("1. Evaluate postfix expression\n");
    printf("2. Evaluate prefix expression\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &caseOperator);

        switch (caseOperator) {
            case 1:
                printf("Enter a postfix expression: ");
                scanf(" %[^\n]", expression);
                printf("%lf\n", evaluatePostfix(expression));
                break;
            case 2:
                printf("Enter a prefix expression: ");
                scanf(" %[^\n]", expression);
                printf("%lf\n", evaluatePrefix(expression));
                break;
            default:
                printf("Invalid operator");
                break;
        }
    }

    return 0;
}
