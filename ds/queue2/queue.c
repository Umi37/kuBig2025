
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