#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

char stack[max];
char postfix[max], infix[max];
int top = -1;

void push(char c) {
    if (top == max - 1) {
        printf("stack overflow");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        printf("stack underflow");
        return '\0';
    }
    char c = stack[top];
    top--;
    return c;
}

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void print() {
    for (int i = 0; i < strlen(postfix); i++) {
        printf("%c", postfix[i]);
    }
}

int space(char c) {
    if (c == ' ' || c == '\t') {
        return 1;
    } else {
        return 0;
    }
}

A * B + C / D

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void reverse(char* arr, int length) {
    if (arr == NULL || length <= 0) {
        return;
    }

    int i = 0;
    int j = length - 1;

    while (i < j) {
        // Swap characters at positions i and j
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        // Move to the next pair of characters
        i++;
        j--;
    }
}

int space(char c){
    if(c==" "|| c=="\t"){
        return 1;
    }
    else{
        return 0;
    }
}

void inToPost() {
    int i, j = 0;
    char next, symbol;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
                    break;
            }
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    printf("Enter an infix expression: ");
    gets(infix);
    reverse(infix, strlen(infix));
    inToPost();
    reverse(postfix, strlen(postfix));
    print();
    return 0;
}
