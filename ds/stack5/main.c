#include <stdio.h>
#include "stack.h"

int main(void)
{
    struct stack s1, s2;
    initStack(&s1, 10);
    initStack(&s2, 100);

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);
    int re;
    pop(&s1, &re); printf("s1 1st pop() : %d\n", re);
    pop(&s1, &re); printf("s1 2nd pop() : %d\n", re);
    pop(&s1, &re); printf("s1 3rd pop() : %d\n", re);

    printf("s1 1st pop() : %d\n", re);
    printf("s1 2nd pop() : %d\n", re);
    printf("s1 3rd pop() : %d\n", re);

    //pop(&1);

    push(&s2, 900);
    push(&s2, 800);
    push(&s2, 700);
    pop(&s2, &re); printf("s1 1st pop() : %d\n", re);
    pop(&s2, &re); printf("s1 2nd pop() : %d\n", re);
    pop(&s2, &re); printf("s1 3rd pop() : %d\n", re);

    cleanupStack(&s1);
    cleanupStack(&s2);
    return 0;
}

