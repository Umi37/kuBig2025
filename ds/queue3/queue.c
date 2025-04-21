#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *pq)
{
    pq->rear = 0;
    pq->front = 0;
}

void push(Queue *pq, int data)
{
    if (pq->rear == QUEUESIZE) {
        fprintf(stderr, "queue is full.\n");
        exit(1);
    }

    pq->array[pq->rear] = data;
    ++pq->rear;
}

int pop(Queue *pq)
{
    if (pq->front == pq->rear) {
        fprintf(stderr, "queue is empty.\n");
        exit(2);  // underflow
    }

    int i = pq->front;
    ++pq->front;
    return pq->array[i];
}
// int pop(Queue *pq)
// {
//     int i = pq->front;
//     ++pq->front;
//     return  pq->array[i];
// }