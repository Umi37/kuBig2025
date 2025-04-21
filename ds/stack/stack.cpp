#include <cstdio>
// #include <stdlib.h>
#include <cassert> // assert
#include "stack.h"

Stack::Stack(int size)
{
    // this->pArr = (int *)malloc(size * sizeof(int)); // C99 표준에서는 타입캐스팅 안해줘도 되는데, C++ 에서는 해줘야함
    this->pArr = new int[size];
    assert(this->pArr);
    
    this->size = size;
    this->tos = 0;
}

Stack::~Stack()
{
    // free(this->pArr);
    delete [] this->pArr;
}

void Stack::push(int data)
{
    assert(this->tos != this->size);
    this->pArr[this->tos] = data;   // *[this->pArr + this->tos] = data;
    ++this->tos;
}

int Stack::pop()
{
    assert(this->tos != 0);
    --this->tos;
    return this->pArr[this->tos];
}
