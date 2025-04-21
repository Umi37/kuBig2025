#ifndef STACK_H
#define STACK_H
class Stack { // typedef , struck keyword 삭제 (쓸 수도 있음)
private:
    int *pArr;
    int size;
    int tos;

public:
    // void initStack(int size);
    // void cleanupStack();
    Stack(int size);            // constructor !!
    ~Stack();                   // destructor !!

    void push(int data);
    int pop();
};
#endif

// 내부 구현은 숨기고 인터페이스는 보인다.
// 객체를 사용할 때 반드시 허용된 연산을 통해서만 쓰인다.
