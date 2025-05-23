#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <assert.h>

void initQueue(Queue *pq, int size)
{
    pq->pArr = malloc(sizeof(int) * size);
    assert(pq->pArr /*!= NULL*/); //assert(ps->pArr != 0);

    pq->size = size;
    pq->front = 0;
    pq->rear = 0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, int data)
{
    // assert(pq->rear != pq->size);    -> 공간하나 덜 쓰게
    assert((pq->rear + 1) % pq->size != pq->front);

    pq->pArr[pq->rear] = data;
    // ++pq->rear;                      -> 끝 까지 가면 앞으로 돌아오게
    pq->rear = (pq->rear + 1) % pq->size;
}

int pop(Queue *pq)
{
    assert(pq->front != pq->rear);

    int i = pq->front;
    // ++pq->front;
    pq->front = (pq->front + 1)% pq->size;
    return pq->pArr[i];
}
