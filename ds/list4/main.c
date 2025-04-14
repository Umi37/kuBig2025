#include "list.h"

int main(void)
{
    List list1, list2;
    initList(&list1, sizeof(int));
    initList(&list2, sizeof(double));

    int i = 4;  insertFirstNode(&list1, &i); // [4]
    i = 3;      insertFirstNode(&list1, &i);
    insertFirstNode(&list, 4);  
    printList(&list);
    insertFirstNode(&list, 3);  
    printList(&list);
    insertFirstNode(&list, 1);  
    printList(&list);
    
    insertNode(&list, 1, 2);    
    printList(&list);

    deleteNode(&list, 3);       
    printList(&list);
    
    cleanupList(&list);
    i = 1;      insertFirstNode(&list1, &i);
    int j = 1;
    i = 2;      insertNode(&list1, &j, &i); 
    i = 3;          deleteNode(&list1, &i);      
    printList(&list1);

    double d = 4.4;  insertFirstNode(&list2, &d);
    d = 3.3;      insertFirstNode(&list2, &d);
    d = 1.1;      insertFirstNode(&list2, &d);
    double f = 1.1;
    d = 2.2;      insertNode(&list2, &f, &d); 
    d = 3.3;          deleteNode(&list2, &d);      
    printList(&list2);

    cleanupList(&list1);
    cleanupList(&list2);
    return 0;
}