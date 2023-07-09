#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to push element.\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack underflow: Cannot pop element\n");
        return '\0';
    }
    
    struct Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

void reverseString(char* str) {
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }
    
    for (int i = 0; i < length; i++) {
        str[i] = pop();
    }
}

int main() {
    char input[MAX_SIZE];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character
    
    printf("Original string: %s\n", input);
    reverseString(input);
    printf("Reversed string: %s\n", input);
    
    return 0;
}
