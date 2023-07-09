#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top1 = -1; // Top index for the first stack
int top2 = MAX_SIZE; // Top index for the second stack

void push1(int value) {
    if (top1 + 1 == top2) {
        printf("Stack overflow: Cannot push element into the first stack\n");
        return;
    }
    
    top1++;
    stack[top1] = value;
    printf("Pushed %d into the first stack\n", value);
}

void push2(int value) {
    if (top2 - 1 == top1) {
        printf("Stack overflow: Cannot push element into the second stack\n");
        return;
    }
    
    top2--;
    stack[top2] = value;
    printf("Pushed %d into the second stack\n", value);
}

int pop1() {
    if (top1 == -1) {
        printf("Stack underflow: Cannot pop element from the first stack\n");
        return -1;
    }
    
    int poppedValue = stack[top1];
    top1--;
    return poppedValue;
}

int pop2() {
    if (top2 == MAX_SIZE) {
        printf("Stack underflow: Cannot pop element from the second stack\n");
        return -1;
    }
    
    int poppedValue = stack[top2];
    top2++;
    return poppedValue;
}

void displayStacks() {
    printf("First Stack: ");
    if (top1 == -1) {
        printf("Empty");
    } else {
        for (int i = 0; i <= top1; i++) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
    
    printf("Second Stack: ");
    if (top2 == MAX_SIZE) {
        printf("Empty");
    } else {
        for (int i = MAX_SIZE - 1; i >= top2; i--) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main() {
    push1(1);
    push2(2);
    push1(3);
    push2(4);
    
    displayStacks();
    
    printf("Popped %d from the first stack\n", pop1());
    printf("Popped %d from the second stack\n", pop2());
    
    displayStacks();
    
    return 0;
}
