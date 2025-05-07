#include <stdio.h>

int stack[100]; // int stack[100] = {0, };
int tos;        // top of stack

void push(int data)
{
    stack[tos] = data;
    ++tos;  // tos = tos + 1; 
}

int pop(void)
{
    --tos;
    return stack[tos];
}

int main(void)
{
    push(100);
    push(200);
    push(300);

    int re = pop(); printf("1st pop() : %d\n", re);
    re = pop();     printf("2st pop() : %d\n", re);
    re = pop();     printf("3st pop() : %d\n", re);

    return 0; // 운영체제가 받는 정상종료 신호
}