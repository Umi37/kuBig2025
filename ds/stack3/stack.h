#ifndef STACK_H
#define STACK_H
#define STACKSIZE 100

typedef struct stack {
    int array[STACKSIZE];
    int tos;
}Stack;

void initStack(Stack *ps);

void push(Stack *ps, int data);
int pop(Stack *ps);

// int stack[100];
// int tos;

// int stack2[100];
// int tos2;

// int stack3[100];
// int tos3;

#endif