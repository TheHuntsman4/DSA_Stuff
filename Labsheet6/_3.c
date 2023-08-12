#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int* data;
    int capacity;
    int front;
    int rear;
};

struct CircularQueue* createCircularQueue(int capacity) {
    struct CircularQueue* cq = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    cq->capacity = capacity;
    cq->data = (int*)malloc(cq->capacity * sizeof(int));
    cq->front = cq->rear = -1;
    return cq;
}

int is_empty(struct CircularQueue* cq) {
    return cq->front == -1;
}

int is_full(struct CircularQueue* cq) {
    return (cq->rear + 1) % cq->capacity == cq->front;
}

void enqueue(struct CircularQueue* cq, int value) {
    if (is_full(cq)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    if (is_empty(cq))
        cq->front = 0;

    cq->rear = (cq->rear + 1) % cq->capacity;
    cq->data[cq->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

int dequeue(struct CircularQueue* cq) {
    if (is_empty(cq)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int value = cq->data[cq->front];
    if (cq->front == cq->rear)
        cq->front = cq->rear = -1;
    else
        cq->front = (cq->front + 1) % cq->capacity;

    return value;
}

void display(struct CircularQueue* cq) {
    if (is_empty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = cq->front;
    printf("Queue elements: ");
    do {
        printf("%d ", cq->data[i]);
        i = (i + 1) % cq->capacity;
    } while (i != (cq->rear + 1) % cq->capacity);
    printf("\n");
}

int getMinElement(struct CircularQueue* cq) {
    if (is_empty(cq)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int minElement = cq->data[cq->front];
    int index = (cq->front + 1) % cq->capacity;

    while (index != (cq->rear + 1) % cq->capacity) {
        if (cq->data[index] < minElement)
            minElement = cq->data[index];

        index = (index + 1) % cq->capacity;
    }

    return minElement;
}

void splitQueue(struct CircularQueue* cq, struct CircularQueue* oddQueue, struct CircularQueue* evenQueue) {
    int index = cq->front;
    int position = 1; // To keep track of the position of the element

    while (index != cq->rear) {
        if (position % 2 == 1)
            enqueue(oddQueue, cq->data[index]);
        else
            enqueue(evenQueue, cq->data[index]);

        index = (index + 1) % cq->capacity;
        position++;
    }

    // Enqueue the last element (rear) in the appropriate queue
    if (position % 2 == 1)
        enqueue(oddQueue, cq->data[index]);
    else
        enqueue(evenQueue, cq->data[index]);
}

void freeCircularQueue(struct CircularQueue* cq) {
    free(cq->data);
    free(cq);
}

int main() {
    int capacity, choice, value;
    printf("Enter the capacity of the circular queue: ");
    scanf("%d", &capacity);

    struct CircularQueue* cq = createCircularQueue(capacity);
    struct CircularQueue* oddQueue = createCircularQueue(capacity);
    struct CircularQueue* evenQueue = createCircularQueue(capacity);

    while (1) {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Split into Odd and Even queues\n");
        printf("5. Get Minimum Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(cq, value);
                break;
            case 2:
                value = dequeue(cq);
                if (value != -1)
                    printf("%d dequeued from the queue.\n", value);
                break;
            case 3:
                display(cq);
                break;
            case 4:
                splitQueue(cq, oddQueue, evenQueue);
                printf("Queue split into Odd and Even queues.\n");
                break;
            case 5:
                printf("Minimum element in the queue: %d\n", getMinElement(cq));
                break;
            case 6:
                freeCircularQueue(cq);
                freeCircularQueue(oddQueue);
                freeCircularQueue(evenQueue);
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
