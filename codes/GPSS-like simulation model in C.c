#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int time;
    int eventType; // 1: Arrival, 2: Departure
} Event;

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(Queue *q, int item) {
    if (isQueueFull(q)) {
        printf("Queue overflow! Customer %d has been rejected.\n", item);
        return; // Do not enqueue, or handle differently
    }

    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }

    q->queue[q->rear] = item;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow!\n");
        exit(EXIT_FAILURE);
    }

    int item = q->queue[q->front];

    if (q->front == q->rear) {
        initializeQueue(q);
    } else {
        q->front++;
    }

    return item;
}

void simulate(int numCustomers, int serviceTime) {
    Queue queue;
    initializeQueue(&queue);

    Event event;
    int currentTime = 0;

    for (int i = 0; i < numCustomers; ++i) {
        event.time = rand() % 10; // Arrival time
        event.eventType = 1; // Arrival event
        enqueue(&queue, event.time);
    }

    while (!isQueueEmpty(&queue)) {
        int nextEventTime = dequeue(&queue);
        currentTime = nextEventTime;

        printf("Processing event at time %d\n", currentTime);

        // Process departure event
        event.time = currentTime + serviceTime;
        event.eventType = 2; // Departure event
        printf("Customer departure scheduled at time %d\n", event.time);
        if (!isQueueFull(&queue)) {
            enqueue(&queue, event.time);
        }
    }
}

int main() {
    srand((unsigned int)time(NULL)); // Seed for random number generation

    int numCustomers = 5;
    int serviceTime = 3;

    simulate(numCustomers, serviceTime);

    return 0;
}
