#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int main(void)
{
    Node *ptr;
    ptr = malloc(sizeof(Node)); 
    ptr -> data = 1;
    ptr -> next = malloc(sizeof(Node));
    ptr->next->data = 3;
    ptr->next->next = malloc(sizeof(Node));
    ptr->next->next->data = 4;
    ptr->next->next->next = NULL; //포인터가 0이 됨. 포인터가 0이라는 건 포인터가 0을 가리킨다는 게 아니라

    //insert
    {Node *p = malloc(sizeof(Node));
    p->data = 2;
    p->next = ptr ->next;
    ptr ->next = p;
    }

    //3번째 노드 삭제
    {Node *p = ptr->next->next;
    ptr-> next ->next = p->next;
    free(p);
    }

    {Node *p = ptr;
    printf("[");
    while(p != NULL) {
         printf("%d", p->data);
         printf(( p->next)? "," :"");
         p= p->next;
    }  
    printf("]\n");
    }
 //free
{Node *p = ptr;
while(p != NULL) {
    Node *temp = p;
    p = p->next;
    free(temp);
}  
}
return 0;
}