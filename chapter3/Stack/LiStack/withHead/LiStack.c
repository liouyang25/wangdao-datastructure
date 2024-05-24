//
// Created by li on 2024/5/24.
//
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

// 初始化
int InitStack(LiStack *liStack) {
    *liStack = (LiStack *) malloc(sizeof(LinkNode));
    (*liStack)->data = 0;
    (*liStack)->next = NULL;
    return 1;
}

int DestroyStack(LiStack *liStack) {
    if (*liStack == NULL)return 0;
    LinkNode *current = (*liStack)->next, *temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    free(*liStack);
    *liStack = NULL;
    return 1;
}

int Push(LiStack *liStack, ElemType elemType) {
    if (*liStack == NULL)return 0;
    LinkNode *firstNode = (*liStack)->next, *newNode;
    newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->next = NULL;
    newNode->data = elemType;
    if (firstNode == NULL) {
        (*liStack)->next = newNode;
    } else {
        newNode->next = firstNode;
        (*liStack)->next = newNode;
    }
    (*liStack)->data++;
    return 1;
}

int Pop(LiStack *liStack, ElemType *elemType) {
    if (*liStack == NULL)return 0;
    LinkNode *firstNode = (*liStack)->next, *temp = (*liStack)->next->next;
    *elemType = firstNode->data;
    free(firstNode);
    (*liStack)->next = temp;
    (*liStack)->data--;
    return 1;
}

int GetTop(LiStack *liStack, ElemType *elemType) {
    if (*liStack == NULL)return 0;
    *elemType = (*liStack)->next->data;
    return 1;
}

int StackEmpty(LiStack *liStack) {
    if (*liStack == NULL)return 1;
    if ((*liStack)->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

