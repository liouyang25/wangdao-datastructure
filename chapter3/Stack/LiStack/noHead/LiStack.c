//
// Created by li on 2024/5/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} *LiStack, LinkNode;

int InitStack(LiStack *liStack) {
    *liStack = NULL;
    return 1;
}

int DestroyStack(LiStack *liStack) {
    if (*liStack == NULL)return 0;
    LinkNode *current = *liStack, *temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    *liStack = NULL;
    return 1;
}

int Push(LiStack *liStack, ElemType elemType) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = elemType;
    newNode->next = *liStack;
    *liStack = newNode;
    return 1;
}

int Pop(LiStack *liStack, ElemType *elemType) {
    if (*liStack == NULL)return 0;
    LinkNode *temp = (*liStack)->next;
    *elemType = (*liStack)->data;
    free(*liStack);
    *liStack = temp;
    return 1;
}

int GetTop(LiStack *liStack, ElemType *elemType) {
    if (*liStack == NULL) {
        *elemType = -999;
        return 0;
    }
    *elemType = (*liStack)->data;
    return 1;
}

int StackEmpty(LiStack *liStack) {
    if (*liStack == NULL) {
        return 1;
    } else {
        return 0;
    }
}

