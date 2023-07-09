#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

bool isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

bool isStackFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack* stack, char value) {
    if (isStackFull(stack)) {
        printf("Stack overflow: Cannot push element\n");
        return;
    }

    stack->top++;
    stack->items[stack->top] = value;
}

char pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow: Cannot pop element\n");
        return '\0';
    }

    char poppedValue = stack->items[stack->top];
    stack->top--;
    return poppedValue;
}

char peek(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        return '\0';
    }

    return stack->items[stack->top];
}

int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

bool isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool isOperand(char symbol) {
    return (isalpha(symbol) || isdigit(symbol));
}

char* infix_to_prefix(char* expression) {
    int length = strlen(expression);
    struct Stack operatorStack;
    struct Stack resultStack;

    initializeStack(&operatorStack);
    initializeStack(&resultStack);

    for (int i = length - 1; i >= 0; i--) {
        char symbol = expression[i];

        if (symbol == ' ' || symbol == '\t') {
            continue;
        }

        if (isOperand(symbol)) {
            push(&resultStack, symbol);
        } else if (symbol == ')') {
            push(&operatorStack, symbol);
        } else if (symbol == '(') {
            while (peek(&operatorStack) != ')' && !isStackEmpty(&operatorStack)) {
                char poppedOperator = pop(&operatorStack);
                push(&resultStack, poppedOperator);
            }

            if (peek(&operatorStack) == ')') {
                pop(&operatorStack);
            }
        } else if (isOperator(symbol)) {
            while (!isStackEmpty(&operatorStack) && getPrecedence(symbol) < getPrecedence(peek(&operatorStack))) {
                char poppedOperator = pop(&operatorStack);
                push(&resultStack, poppedOperator);
            }

            push(&operatorStack, symbol);
        }
    }

    while (!isStackEmpty(&operatorStack)) {
        char poppedOperator = pop(&operatorStack);
        push(&resultStack, poppedOperator);
    }

    char* prefixExpression = (char*)malloc((resultStack.top + 2) * sizeof(char));
    int index = 0;

    while (!isStackEmpty(&resultStack)) {
        prefixExpression[index] = pop(&resultStack);
        index++;
    }

    prefixExpression[index] = '\0';

    return prefixExpression;
}

char* infix_to_postfix(char* expression) {
    int length = strlen(expression);
    struct Stack operatorStack;
    char* postfixExpression = (char*)malloc((length + 1) * sizeof(char));  // Allocate memory for the postfix expression
    int postfixIndex = 0;

    initializeStack(&operatorStack);

    for (int i = 0; i < length; i++) {
        char symbol = expression[i];

        if (symbol == ' ' || symbol == '\t') {
            continue;
        }

        if (isOperand(symbol)) {
            postfixExpression[postfixIndex] = symbol;
            postfixIndex++;
        } else if (symbol == '(') {
            push(&operatorStack, symbol);
        } else if (symbol == ')') {
            while (peek(&operatorStack) != '(' && !isStackEmpty(&operatorStack)) {
                char poppedOperator = pop(&operatorStack);
                postfixExpression[postfixIndex] = poppedOperator;
                postfixIndex++;
            }

            if (peek(&operatorStack) == '(') {
                pop(&operatorStack);
            }
        } else if (isOperator(symbol)) {
            while (!isStackEmpty(&operatorStack) && getPrecedence(symbol) <= getPrecedence(peek(&operatorStack))) {
                char poppedOperator = pop(&operatorStack);
                postfixExpression[postfixIndex] = poppedOperator;
                postfixIndex++;
            }

            push(&operatorStack, symbol);
        }
    }

    while (!isStackEmpty(&operatorStack)) {
        char poppedOperator = pop(&operatorStack);
        postfixExpression[postfixIndex] = poppedOperator;
        postfixIndex++;
    }

    postfixExpression[postfixIndex] = '\0';

    return postfixExpression;
}

int main() {
    int _caseOperator;
    char expression[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';  // Remove the trailing newline character

    printf("How would you wish to evaluate the given expression: \n");
    printf("1.infix to prefix\n");
    printf("2.infix to postfix\n");

    scanf("%d",&_caseOperator);

    switch(_caseOperator){
        case 1:
            char* prefixExpression = infix_to_prefix(expression);
            printf("Prefix expression: %s\n", prefixExpression);
            free(prefixExpression);
            break;
        case 2:
char* postfixExpression = infix_to_postfix(expression);

    printf("Postfix expression: %s\n", postfixExpression);

    free(postfixExpression);

            printf("exp");
            break;
        default:
        printf("invalid operation");

    }


    return 0;
}
