#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define a maximum size for the queue

// Structure to represent the queue
typedef struct {
    int arr[MAX_SIZE];
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Current number of elements in the queue
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    queue->front = 0;
    queue->rear = -1; // Initialize rear to -1 for an empty queue
    queue->size = 0;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to enqueue an element
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
    queue->arr[queue->rear] = value;
    queue->size++;
    printf("%d enqueued.\n", value);
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Or return some error value
    }

    int dequeuedValue = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE; // Circular increment
    queue->size--;
    printf("%d dequeued.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the queue (for testing)
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    for (int j = 0; j < queue->size; j++) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}


int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);

    dequeue(queue);
    displayQueue(queue);

    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    enqueue(queue, 100);
    enqueue(queue, 110); // Demonstrates wrap-around with circular queue
    displayQueue(queue);


    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);


    free(queue); // Important: Free the allocated memory
    return 0;
}
