#include <stdio.h>
#include <stdlib.h>


#define MAX_LEN 100
// Implementing Stack using array
int stack[MAX_LEN];

void push(int stack[],int value){
    int top=sizeof(stack)/sizeof(stack[0]);
    stack[top-1]=value;
} 

int pop(int stack[]){
    int len = sizeof(stack)/sizeof(stack[0]);
    int top = stack[len-1];
    len--;
    return top;
}

int peek(int stack[]){
    int len = sizeof(stack)/sizeof(stack[0]);
    int top = stack[len-1];
    return top;
}