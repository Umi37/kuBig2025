#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // assert
#include "stack.h"

void initStack(Stack *ps, int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    assert(ps->pArr /*!= NULL*/); //assert(ps->pArr != 0);
    ps->size = size;
    ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps, int data)
{
    assert(ps->tos != ps->size);
    ps->pArr[ps->tos] = data;   // *[ps->pArr + ps->tos] = data;
    ++ps->tos;
}

int pop(Stack *ps)
{
    assert(ps->tos != 0);
    --ps->tos;
    return ps->pArr[ps->tos];
}
