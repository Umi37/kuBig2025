#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // assert
#include "stack.h"

void initStack(Stack *ps, int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    assert(ps->pArr /*!= NULL*/); 
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
    ps->pArr[ps->tos] = data;   
    ++ps->tos;
}

void pop(Stack *ps, int *pRe)
{
    assert(ps->tos != 0);
    --ps->tos;
    *pRe = ps->pArr[ps->tos];
}


// int pop(Stack *ps)
// {
//     assert(ps->tos != 0);

//     --ps->tos;
//     return ps->pArr[ps->tos];
// }
