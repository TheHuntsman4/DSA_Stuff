#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

bool isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

bool isStackFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int data) {
    if (isStackFull(stack)) {
        printf("Stack overflow. Push operation failed.\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = data;
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow. Pop operation failed.\n");
        return -1;
    }

    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

void initQueue(struct Queue* queue) {
    initStack(&(queue->stack1));
    initStack(&(queue->stack2));
}

bool isQueueEmpty(struct Queue* queue) {
    return isStackEmpty(&(queue->stack1)) && isStackEmpty(&(queue->stack2));
}

void enqueue(struct Queue* queue, int data) {
    if (isStackFull(&(queue->stack1))) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    push(&(queue->stack1), data);
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    if (isStackEmpty(&(queue->stack2))) {
        while (!isStackEmpty(&(queue->stack1))) {
            int data = pop(&(queue->stack1));
            push(&(queue->stack2), data);
        }
    }

    return pop(&(queue->stack2));
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued element: %d\n", dequeue(&queue));

    enqueue(&queue, 40);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}
