#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q1, q2;
    initQueue(&q1, 10);
    initQueue(&q2, 100);

    push(&q1, 100);
    push(&q1, 200);
    push(&q1, 300);
    int re;
    pop(&q1, &re); printf("s1 1st pop() : %d\n", re);
    pop(&q1, &re); printf("s1 2nd pop() : %d\n", re);
    pop(&q1, &re); printf("s1 3rd pop() : %d\n", re);

    printf("q1 1st pop() : %d\n", re);
    printf("q1 2nd pop() : %d\n", re);
    printf("q1 3rd pop() : %d\n", re);

    // pop(&q1);

    push(&q2, 900);
    push(&q2, 800);
    push(&q2, 700);
    pop(&q2, &re); printf("s1 1st pop() : %d\n", re);
    pop(&q2, &re); printf("s1 2nd pop() : %d\n", re);
    pop(&q2, &re); printf("s1 3rd pop() : %d\n", re);

    cleanupQueue(&q1);
    cleanupQueue(&q2);
    return 0;

}