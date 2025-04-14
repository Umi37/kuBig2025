#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static Node *createNode(int data, Node *next) //static 넣어서 메인에서는 접근 못 함.
{
    Node *p = malloc(sizeof(Node));
    assert(p );
    p-> data = data;
    p->next = next;
   
    return p; //지역공간에 있는 지역변수를 리턴하면 나중에 사라지기 때문에 최대한 포인터를 리턴하면 안 되는데 노드가 힙 상에 만들어지는 애라서 여기서는 ㄱㅊ
}

void initList(List *plist)
{
    // // plist ->ptr =malloc(sizeof(Node)); // dummy node
    // plist ->ptr =malloc(sizeof(Node)); // dummy node
    // plist->ptr->next = NULL;
    plist ->ptr = createNode(-1, NULL); // dummy node
}
void cleanupList(List *plist)
{
    Node *p =plist->ptr;
    while(p ){
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}
void insertFirstNode(List *plist, int data)
{
    // Node *p = malloc(sizeof(Node));
    // p -> data   = data;
    // p -> next   = plist->ptr->next;
    // plist ->ptr->next = p;
    plist ->ptr ->next = createNode(data, plist->ptr->next);
}
void insertNode(List *plist, int prevData, int data)
{
    Node *p = plist->ptr->next;
    while(p ){
        if(p->data == prevData){
           break;
        }
        p = p->next;
    }
    // if(p){Node *tmp = malloc(sizeof(Node));
    //     tmp->data = data;
    //     tmp->next = p->next;
        p->next = createNode(data, p->next);
    }
    
void deleteNode(List *plist, int data)
{
    Node *p = plist->ptr->next;
    Node *p2 = plist->ptr;

    while(p ){
        if(p -> data == data)
            break;
        p = p->next;
        p2 = p2 ->next;
    }
    if(p){
        p2->next = p->next;
        free(p);
    }
}

void printList(const List *plist)
{
    Node *p = plist->ptr->next;
    printf("[");
    while (p ) {
        printf("%d", p->data);
        printf(( p->next)? ", " :"");
        p = p->next;
    }
    printf("]\n");
}