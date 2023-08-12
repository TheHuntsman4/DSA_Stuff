#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct Deque {
    int elements[MAX_SIZE];
    int front, rear;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = -1;
    dq->rear = -1;
    return dq;
}

bool is_empty(struct Deque* dq) {
    return dq->front == -1;
}

bool is_full(struct Deque* dq) {
    return (dq->rear + 1) % MAX_SIZE == dq->front;
}

void insertFront(struct Deque* dq, int data) {
    if (is_full(dq)) {
        printf("Deque is full. InsertFront operation failed.\n");
        return;
    }

    if (is_empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    dq->elements[dq->front] = data;
    printf("%d inserted at the front of the deque.\n", data);
}

void insertLast(struct Deque* dq, int data) {
    if (is_full(dq)) {
        printf("Deque is full. InsertLast operation failed.\n");
        return;
    }

    if (is_empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }

    dq->elements[dq->rear] = data;
    printf("%d inserted at the last of the deque.\n", data);
}

void deleteFront(struct Deque* dq) {
    if (is_empty(dq)) {
        printf("Deque is empty. DeleteFront operation failed.\n");
        return;
    }

    int data = dq->elements[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }

    printf("%d deleted from the front of the deque.\n", data);
}

void deleteLast(struct Deque* dq) {
    if (is_empty(dq)) {
        printf("Deque is empty. DeleteLast operation failed.\n");
        return;
    }

    int data = dq->elements[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    printf("%d deleted from the last of the deque.\n", data);
}

int getFront(struct Deque* dq) {
    if (is_empty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return dq->elements[dq->front];
}

int getRear(struct Deque* dq) {
    if (is_empty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return dq->elements[dq->rear];
}

void display(struct Deque* dq) {
    if (is_empty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    int i = dq->front;
    printf("Deque elements: ");
    do {
        printf("%d ", dq->elements[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (dq->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct Deque* dq = createDeque();

    insertFront(dq, 10);
    insertLast(dq, 20);
    insertFront(dq, 30);
    deleteFront(dq);
    deleteLast(dq);
    insertLast(dq, 25);
    insertFront(dq, 40);
    insertFront(dq, 50);

    printf("Rear element: %d\n", getRear(dq));
    printf("Front element: %d\n", getFront(dq));

    display(dq);

    return 0;
}
