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
    int choice, stackNum, value;
    
    while (true) {
        printf("\nStack Operations\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stacks\n");
        printf("0. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exiting the program\n");
                return 0;
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                value = pop1();
                if (value != -1) {
                    printf("Popped %d from the first stack\n", value);
                }
                break;
            case 4:
                value = pop2();
                if (value != -1) {
                    printf("Popped %d from the second stack\n", value);
                }
                break;
            case 5:
                displayStacks();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
