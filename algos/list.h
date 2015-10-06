#ifndef _LIST_H
#define _LIST_H

typedef struct node {
    int data;
    struct node *next;
}Node;

typedef Node* NodePtr; 

NodePtr Insert(NodePtr head, int data);

#endif
