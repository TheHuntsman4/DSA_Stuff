#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow: Cannot push element\n");
        return;
    }
    
    top++;
    stack[top] = value;
    printf("Pushed %d onto the stack\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack underflow: Cannot pop element\n");
        return;
    }
    
    int poppedValue = stack[top];
    top--;
    printf("Popped %d from the stack\n", poppedValue);
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    
    return stack[top];
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    do {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("0. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exiting the program\n");
                break;
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top of the stack: %d\n", peek());
                break;
            case 4:
                displayStack();
                break;
            default:
                printf("Invalid choice\n");
        }
        
    } while (choice != 0);
    
    return 0;
}
