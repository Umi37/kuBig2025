#ifndef LIST_H
#define LIST_H


typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *ptr;
} List;

void initList(List *plist);
void cleanupList(List *plist);
void insertFirstNode(List *plist, int data);
void insertNode(List *plist, int prevData, int data);
void deleteNode(List *plist, int data);
void printList(const List *plist);

#endif