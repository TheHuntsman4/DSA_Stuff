#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int min;
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
    
    if (top->next == NULL || value < top->next->min)
        top->min = value;
    else
        top->min = top->next->min;
    
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

int getMin() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    
    return top->min;
}

struct Node* copyStack() {
    if (top == NULL) {
        printf("Stack is empty. Cannot copy.\n");
        return NULL;
    }
    
    struct Node* originalCurrent = top;
    struct Node* duplicateTop = NULL;
    struct Node* duplicateCurrent = NULL;
    
    while (originalCurrent != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed. Unable to copy element.\n");
            return NULL;
        }
        
        newNode->data = originalCurrent->data;
        newNode->next = NULL;
        
        if (duplicateTop == NULL) {
            duplicateTop = newNode;
            duplicateCurrent = newNode;
        } else {
            duplicateCurrent->next = newNode;
            duplicateCurrent = duplicateCurrent->next;
        }
        
        originalCurrent = originalCurrent->next;
    }
    
    return duplicateTop;
}

void displayStack(struct Node* stack) {
    if (stack == NULL) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements: ");
    struct Node* current = stack;
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
        printf("4. Get Minimum\n");
        printf("5. Copy Stack\n");
        printf("6. Display Stack\n");
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
                printf("Minimum element: %d\n", getMin());
                break;
            case 5: {
                struct Node* duplicateStack = copyStack();
                printf("Duplicate stack: ");
                displayStack(duplicateStack);
                break;
            }
            case 6:
                displayStack(top);
                break;
            default:
                printf("Invalid choice\n");
        }
        
    } while (choice != 0);
    
    return 0;
}
