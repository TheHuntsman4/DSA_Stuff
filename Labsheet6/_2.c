#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int* createQueue(int maxSize) {
    int* queue = (int*)malloc(maxSize * sizeof(int));
    return queue;
}

int isFull(int front, int rear, int size) {
    return ((rear + 1) % size == front);
}

int isEmpty(int front, int rear) {
    return (front == -1);
}

void enqueue(int* queue, int* front, int* rear, int size, int data) {
    if (isFull(*front, *rear, size)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(*front, *rear))
        *front = 0;

    *rear = (*rear + 1) % size;
    queue[*rear] = data;

    printf("Enqueued element: %d\n", data);
}

int dequeue(int* queue, int* front, int* rear, int size) {
    if (isEmpty(*front, *rear)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = queue[*front];

    if (*front == *rear)
        *front = *rear = -1;
    else
        *front = (*front + 1) % size;

    printf("Dequeued element: %d\n", data);
    return data;
}

void display(int* queue, int front, int rear, int size) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    printf("\n");
}

void destroyQueue(int* queue) {
    free(queue);
}

int main() {
    int maxSize, choice, data;
    int* queue;
    int front = -1;
    int rear = -1;

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);
    queue = createQueue(maxSize);

    while (1) {
        printf("\nChoose the queue Operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, &front, &rear, maxSize, data);
                break;
            case 2:
                dequeue(queue, &front, &rear, maxSize);
                break;
            case 3:
                display(queue, front, rear, maxSize);
                break;
            case 4:
                destroyQueue(queue);
                printf("Exit..\n");
                return 0;
            default:
                printf("Invalid choice!!\n");
        }
    }

    return 0;
}
