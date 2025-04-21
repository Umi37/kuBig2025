#include <stdio.h>
// 전역이라 자동 초기화
int queue[100];
int rear;
int front;

void push(int data)
{
    queue[rear] = data;
    ++rear; // rear는 data가 들어갈 위치
}

int pop(void)
{
    int i = front;
    ++front;
    return queue[i];
}
int main(void)
{
    push(100);
    push(200);
    push(300);

    printf("1st pop() : %d\n", pop());
    printf("2nd pop() : %d\n", pop());
    printf("3rd pop() : %d\n", pop());

    return 0;

}