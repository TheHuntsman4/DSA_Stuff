#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to push element.\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow: Cannot pop element\n");
        return;
    }
    
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    printf("Popped %d from the stack\n", poppedValue);
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    
    return top->data;
}



void displayStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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
