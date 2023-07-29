#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

bool is_empty(struct Deque* deque) {
    return deque->front == -1;
}

bool is_full(struct Deque* deque) {
    return (deque->rear + 1) % MAX_SIZE == deque->front;
}

void insertFront(struct Deque* deque, int data) {
    if (is_full(deque)) {
        printf("Deque is full. InsertFront operation failed.\n");
        return;
    }

    if (is_empty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->arr[deque->front] = data;
    printf("%d inserted at the front of the deque.\n", data);
}

void insertLast(struct Deque* deque, int data) {
    if (is_full(deque)) {
        printf("Deque is full. InsertLast operation failed.\n");
        return;
    }

    if (is_empty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->arr[deque->rear] = data;
    printf("%d inserted at the last of the deque.\n", data);
}

void deleteFront(struct Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty. DeleteFront operation failed.\n");
        return;
    }

    int data = deque->arr[deque->front];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    printf("%d deleted from the front of the deque.\n", data);
}

void deleteLast(struct Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty. DeleteLast operation failed.\n");
        return;
    }

    int data = deque->arr[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    printf("%d deleted from the last of the deque.\n", data);
}

int getFront(struct Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->arr[deque->front];
}

int getRear(struct Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->arr[deque->rear];
}

void display(struct Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    int i = deque->front;
    printf("Deque elements: ");
    do {
        printf("%d ", deque->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (deque->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct Deque* deque = createDeque();

    insertFront(deque, 10);
    insertLast(deque, 20);
    insertFront(deque, 30);
    deleteFront(deque);
    deleteLast(deque);
    insertLast(deque, 25);
    insertFront(deque, 40);
    insertFront(deque, 50);

    printf("Rear element: %d\n", getRear(deque));
    printf("Front element: %d\n", getFront(deque));

    display(deque);

    return 0;
}
