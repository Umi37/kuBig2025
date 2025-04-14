#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initList(List *pList, int eleSize)
{
    pList->ptr = malloc(sizeof(Node));  // dummy node
    pList->ptr =  = NULL;
}

void cleanupList(List *pList)
{
    Node *p = pList->ptr;
    while (p ) {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

void insertFirstNode(List *pList, const void *pData)
{
    Node *p = malloc(sizeof(Node));
    p->data = data;
    p->next = pList->ptr->next;
    pList->ptr->next = p;
}

void insertNode(List *pList, const void *pPrevData, const void *pData)
{
    Node *p = pList -> ptr->next;
    while (p ) {
        if (p->data == prevData) {
            break;
        }
        p =p->next;
    } 

    if (p ){
        Node *tmp = malloc(sizeof(Node));
        tmp->data = data;
        tmp->next = p->next;
        p->next = tmp;
    } /*else {
        // X
    }*/
}

void deleteNode(List *pList, const void *pData)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr;

    while (p ){
        if (p->data == data)
            break;

        p = p->next;
        p2 = p2->next;
    }

    if (p ) {
        p2->next = p->next;
        free(p);
    }
}

void printList(const List *pList)
{
    Node *p = pList->ptr->next;
    printf("[");
    while (p ) {
        printf("%d", p->data);
        printf( (p->next) ? ", " : "");
        p = p->next;
    }
    printf("]\n");
}
