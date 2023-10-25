#include "lkdlist.h"
#include <stdlib.h>

void createLinkedList(tNode** p)
{
    *p = NULL;
}

int insertNodeAtEnd(tNode** p, void* elem, size_t elemSize)
{
    tNode* newNode = (tNode*)malloc(sizeof(tNode));

    if (!newNode)
    {
        return 0;
    }


    newNode->elem = malloc(elemSize);
    if (!newNode->elem)
    {
        free(newNode);
        return 0;
    }
    memcpy(newNode->elem, elem, elemSize);

    newNode->_size = elemSize;
    newNode->next = NULL;

    if (*p == NULL)
    {
        *p = newNode;
    }
    else
    {
        tNode* current = *p;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    return 1;
}

int addNodeAnyPosition(tNode** p, void* elem, size_t elemSize, int pos)
{
    if (pos < 0)
    {
        return 0;
    }

    tNode* current = *p;
    int currentPos = 0;
    tNode* newNode = (tNode*)malloc(sizeof(tNode));

    if (!newNode)
    {
        return 0;
    }

    newNode->elem = malloc(elemSize);
    if (!newNode->elem)
    {
        free(newNode);
        return 0;
    }
    memcpy(newNode->elem, elem, elemSize);
    newNode->_size = elemSize;
    newNode->next=NULL;


    if (pos == 0)
    {
        newNode->next = *p;
        *p = newNode;
        return 1;
    }

    while (current && currentPos < pos - 1)
    {
        current = current->next;
        currentPos++;
    }

    if (!current)
    {
        current = *p;
        while (current->next)
        {
            current = current->next;
        }
    }

    newNode->next = current->next;
    current->next = newNode;

    return 1;
}



int deleteNode(tNode** p, int pos)
{
    tNode* nodeToDelete;
    tNode* current=*p; //current aims to head position
    int i;

    if(pos<1)
    {
        return 0;
    }

    for(i=0; i<pos-1; i++)
    {
        if(current->next==NULL)
        {
            return 0;
        }
        current= current->next; //current goes through the linked list until it aims to the previous node that user wants to delete

    }
    nodeToDelete= current->next;

    if(nodeToDelete==NULL)
    {
        return 0;
    }

    current->next = nodeToDelete->next;
    free(nodeToDelete->elem);
    free(nodeToDelete);


    return 1;

}

int deleteLinkedList(tNode** p)
{
    if(!*p)
    {
        return 0;
    }
    tNode* current=*p;
    tNode* toDelete;
    while(current)
    {
        toDelete=current;
        current=current->next;
        free(toDelete->elem);
        free(toDelete);
    }

    *p=NULL;
    return 1;
}

void operateLinkedList(tNode** p, void action(const tNode* node))
{
    tNode* current= *p;
    while(current)
    {
        action(current);
        current=current->next;
    }
}
void showStringNode(const tNode* node)
{
    const char* string= (char*)node->elem;
    printf("%s\n",string);
}
void showIntegerNode(const tNode* node)
{
    const int* a= (int*)node->elem;
    printf("%d ",*a);
}

void showFloatNode(const tNode* node)
{
    const float* a= (float*)node->elem;
    printf("%.3f ",*a);
}

