#ifndef LKDLIST_H_INCLUDED
#define LKDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCOL 1024
#define MAXLINE 1024



struct tNode
{
    void* elem;
    size_t _size;
    struct tNode* next;

};

typedef struct tNode tNode;

void createLinkedList(tNode** p);
int insertNodeAtEnd(tNode** p, void* elem, size_t elemSize);
int addNodeAnyPosition(tNode** p, void* elem, size_t elemSize, int pos);
int deleteNode(tNode** p, int pos);
int deleteLinkedList(tNode** p);
void operateLinkedList(tNode** p, void action(const tNode* node));
void showStringNode(const tNode* node);
void showFloatNode(const tNode* node);
void showIntegerNode(const tNode* node);

#endif // LKDLIST_H_INCLUDED
