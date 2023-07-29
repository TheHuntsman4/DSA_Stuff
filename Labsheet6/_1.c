#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int* createQueue() {
 int* queue = (int*)malloc(MAX_SIZE * sizeof(int));
 return queue;
}

int isFull(int front, int rear) {
 return ((rear + 1) % MAX_SIZE == front);
}

int isEmpty(int front, int rear) {
 return (front == -1);
}

void enqueue(int* queue, int* front, int* rear, int data) {
 if (isFull(*front, *rear)) {
  printf("Queue is full. Enqueue operation not possible\n");
  return;
 }

 if (*front == -1)
  *front = 0;

 *rear = (*rear + 1) % MAX_SIZE;
 queue[*rear] = data;

 printf("Enqueued element: %d\n", data);
}

int dequeue(int* queue, int* front, int* rear) {
 if (isEmpty(*front, *rear)) {
  printf("Queue is empty \n");
  return -1;
 }

 int data = queue[*front];
 if (*front == *rear)
  *front = *rear = -1;
 else
  *front = (*front + 1) % MAX_SIZE;

 printf("Dequeued element: %d\n", data);
 return data;
}

void display(int* queue, int front, int rear) {
 if (isEmpty(front, rear)) {
  printf("Queue is empty.\n");
  return;
 }

 printf("Queue elements: ");
 int i = front;
 while (i != rear) {
  printf("%d ", queue[i]);
  i = (i + 1) % MAX_SIZE;
 }
 printf("%d\n", queue[rear]);
}

void destroyQueue(int* queue) {
 free(queue);
}

int main() {
 int* queue = createQueue();
 int front = -1;
 int rear = -1;
 int opCode, data;

 while (1) {
  printf("\nChoose the queue operation:\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Display\n");
  printf("4. Exit\n");
  printf("Enter your opCode: ");
  scanf("%d", &opCode);

  switch (opCode) {
   case 1:
    printf("Enter the element to enqueue: ");
    scanf("%d", &data);
    enqueue(queue, &front, &rear, data);
    break;
   case 2:
    dequeue(queue, &front, &rear);
    break;
   case 3:
    display(queue, front, rear);
    break;
   case 4:
    destroyQueue(queue);
    printf("Exiting....\n");
    return 0;
   default:
    printf("Invalid Op code\n");
  }
 }

 return 0;
}