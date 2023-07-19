// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define max 100

// char stack[max];
// char postfix[max],infix[max];
// int top=-1;

// void push(char c){
//     if (top==max){
//         printf("stack overflow");
//         return;
//     }
//     top++;
//     stack[top]=c;
// }

// char pop(){
//     char c=stack[top];
//     top--;
//     return c;
// }

// int isEmpty(){
//     if(top==-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void print(){
//     for(int i=0;i<strlen(postfix);i++){
//         printf("%c",postfix[i]);
//     }
// }

// int space(char c){
//     if (c==' '|| c=='\t'){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int precedence(char symbol){
//     switch(symbol){
//         case '^':
//         return 3;
//         case '*':
//         case '/':
//         return 2;
//         case '+':
//         case '-':
//         return 1;
//         defualt:
//         return 0;
//     }
// }

// void inToPost(){
//     int i,j=0;
//     char next,symbol;
//     for(i=0;i<strlen(infix);i++){
//         symbol=infix[i];
//         switch (symbol)
//         {
//         case '(':
//             push(symbol);
//             break;
//         case ')':
//         while((next=pop())!='('){
//             postfix[j++]=next;
//         }
//         break;
//         case '+':
//         case '-':
//         case '*':
//         case '/':
//         while(!isEmpty && precedence(stack[top])>=precedence(symbol)){
//             postfix[j++]=pop();
//         }
//         push(symbol);
//         break;
//         default:
//         postfix[j++]=symbol;
//             break;
//         }
//     }
//     while(!isEmpty()){
//         postfix[j++]=pop();
//        postfix[j]='\0'; 
//     }
// }

// int main(){
//     gets(infix);
//     inToPost();
//     print();
//     return 0;
// }



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

char stack[max], postfix[max], infix[max];
int top = -1;

void push(char c) {
    if (top == max - 1) {
        printf("Stack overflow");
        return;
    }
    else {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow");
        return '\0';
    }
    else {
        char c = stack[top];
        top--;
        return c;
    }
}

void print() {
    for (int i = 0; i < strlen(postfix); i++) {
        printf("%c", postfix[i]);
    }
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

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

void reverse(char* charr,int len){
    int i=0;
    int j=len-1;
    char temp;
    while(i<j){
        temp=charr[i];
        charr[i]=charr[j];
        charr[j]=temp;
        i++;
        j--;
    }
}

void inToPost() {
    int i, j;
    char symbol, next;
    j = 0;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
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
            case '^':
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
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    printf("Enter the infix expression: ");
    fgets(infix, max, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove the newline character from fgets
    reverse(infix,strlen(infix));
    inToPost();
    reverse(postfix,strlen(postfix));
    printf("Postfix expression: ");
    print();

    return 0;
}
