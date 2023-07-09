#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int pop() {
    if (top == -1) {
        printf("Stack underflow: Cannot pop element\n");
        return -1;
    }
    
    int poppedValue = stack[top];
    top--;
    return poppedValue;
}

bool isEmpty() {
    return (top == -1);
}

void removeMiddle() {
    int size = top + 1;
    int middle = size / 2;
    
    int* auxStack = (int*)malloc(middle * sizeof(int));
    if (auxStack == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Push the first half of the elements to the auxiliary stack
    for (int i = 0; i < middle; i++) {
        auxStack[i] = pop();
    }
    
    // Pop the middle element
    pop();
    
    // Push back the elements from the auxiliary stack to the original stack
    for (int i = middle - 1; i >= 0; i--) {
        push(auxStack[i]);
    }
    
    free(auxStack);
}

void displayStack() {
    if (isEmpty()) {
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
        printf("3. Remove Middle Element\n");
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
                printf("Popped %d from the stack\n", pop());
                break;
            case 3:
                removeMiddle();
                printf("Middle element removed from the stack\n");
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
