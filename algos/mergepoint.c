/*
Given two lists find the merge point
*/
#include "stdio.h"
#include "list.h"

void PrintList(NodePtr head);
NodePtr Join(NodePtr dest, NodePtr src);
int Length(NodePtr head);
NodePtr Mergepoint(NodePtr lista, NodePtr listb);

int main()
{
    NodePtr lista = NULL, listb = NULL, listc = NULL; 
    
    // build the two lists
    lista = Insert(lista, 30);
    lista = Insert(lista, 20);
    lista = Insert(lista, 10);

    listb = Insert(listb, 70);
    listb = Insert(listb, 60);
    listb = Insert(listb, 50);
	
	listc = Insert(listc, 40);

    lista = Join(lista, listb);
	listb = Join(listc, listb);

    PrintList(lista);
    PrintList(listb);

    NodePtr mergenode = Mergepoint(lista, listb);

    printf("Merge point of the two list is %d\n", mergenode->data); 
}

void PrintList(NodePtr head)
{
    while(head)
    {
        printf("%d => ", head->data);
        head = head->next; 
    }
	printf("NULL\n");
}

NodePtr Join(NodePtr dest, NodePtr src)
{
    if(dest == NULL)
    {
        return src;
    }
    else
    {
		NodePtr t = dest;
        while(t->next)
        {
            t = t->next;
        }
        t->next = src;
    }

    return dest;
}

int Length(NodePtr head)
{
    int count = 0;
    while(head)
    { 
        count++;
        head = head->next;
    }
  
    return count;
}

NodePtr Mergepoint(NodePtr lista, NodePtr listb)
{
    NodePtr t = NULL; 

    int lena = Length(lista);
    int lenb = Length(listb);

    int diff = (lena - lenb);

    if(lena < lenb)
    {
        t = lista; 
        lista = listb;
        listb = t;
        diff = (lenb - lena);
    }        

    while(diff)
    {
        lista = lista->next;
        diff--;
    }
 
    while(lista && listb)
    {
        if(lista->data == listb->data)
        {
            break;
        }

        lista = lista->next;
        listb = listb->next;
    }    

    return lista;
}
