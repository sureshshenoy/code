#include "stdlib.h"
#include "list.h"

NodePtr Insert(NodePtr head, int data)
{
    NodePtr t = (NodePtr)malloc(sizeof(Node));
    t->data = data;
    t->next = head; 

    head = t; 

    return head;
}
