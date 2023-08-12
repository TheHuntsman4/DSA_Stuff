#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int elements[MAX_SIZE];
    int top;
};

void init_stack(struct Stack* stack) {
    stack->top = -1;
}

bool is_stack_empty(struct Stack* stack) {
    return stack->top == -1;
}

bool is_stack_full(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int data) {
    if (is_stack_full(stack)) {
        printf("Stack overflow. Push operation failed.\n");
        return;
    }

    stack->top++;
    stack->elements[stack->top] = data;
}

int pop(struct Stack* stack) {
    if (is_stack_empty(stack)) {
        printf("Stack underflow. Pop operation failed.\n");
        return -1;
    }

    int data = stack->elements[stack->top];
    stack->top--;
    return data;
}

struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

void init_queue(struct Queue* queue) {
    init_stack(&(queue->stack1));
    init_stack(&(queue->stack2));
}

bool is_queue_empty(struct Queue* queue) {
    return is_stack_empty(&(queue->stack1)) && is_stack_empty(&(queue->stack2));
}

void enqueue(struct Queue* queue, int data) {
    if (is_stack_full(&(queue->stack1))) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    push(&(queue->stack1), data);
}

int dequeue(struct Queue* queue) {
    if (is_queue_empty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    if (is_stack_empty(&(queue->stack2))) {
        while (!is_stack_empty(&(queue->stack1))) {
            int data = pop(&(queue->stack1));
            push(&(queue->stack2), data);
        }
    }

    return pop(&(queue->stack2));
}

void display_queue(struct Queue* queue) {
    printf("Queue elements: ");
    struct Stack* s1 = &(queue->stack1);
    struct Stack* s2 = &(queue->stack2);

    for (int i = s2->top; i >= 0; i--) {
        printf("%d ", s2->elements[i]);
    }

    for (int i = 0; i <= s1->top; i++) {
        printf("%d ", s1->elements[i]);
    }

    printf("\n");
}

int main() {
    struct Queue queue;
    init_queue(&queue);

    int choice, data;

    while (1) {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1)
                    printf("Dequeued element: %d\n", data);
                break;
            case 3:
                display_queue(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}



