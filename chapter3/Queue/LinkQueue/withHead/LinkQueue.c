//
// Created by li on 2024/5/29.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;
} *LinkQueue;

//初始化队列
int InitQueue(LinkQueue *pLinkQueue) {
    *pLinkQueue = (LinkQueue) malloc(sizeof(LinkQueue));
    (*pLinkQueue)->front = (*pLinkQueue)->rear = (LinkNode *) malloc(sizeof(LinkNode));
    (*pLinkQueue)->front->next = NULL;
    return 1;
}

//入队
int EnQueue(LinkQueue *linkQueue, ElemType elemType) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = elemType;
    newNode->next = (*linkQueue)->front->next;
    if ((*linkQueue)->front->next == NULL) {
        (*linkQueue)->front->next = (*linkQueue)->rear->next = newNode;
    } else {
        (*linkQueue)->rear->next = newNode;
    }
    (*linkQueue)->rear = newNode;
    return 1;
}

//出队
int DeQueue(LinkQueue *linkQueue, ElemType *elemType) {
    //TODO
    return 1;
}

//队列是否为空
int QueueEmpty(LinkQueue linkQueue) {
    if (linkQueue->front->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

//队列元素个数
int GetItemNum(LinkQueue linkQueue) {
    if (linkQueue->front->next == NULL)return 0;
    LinkNode *current = linkQueue->front->next->next;
    int count = 1;
    while (current != linkQueue->front->next) {
        count++;
        current = current->next;
    }
    return count;
}

//打印队列
void PrintQueue(LinkQueue linkQueue) {
    if (linkQueue->front->next == NULL)return;
    LinkNode *current = linkQueue->front->next;
//    printf("%d  ", current->data);
//    current = current->next;
//    while (current != linkQueue->front->next) {
//        printf("%d  ", current->data);
//        current = current->next;
//    }
//    printf("\n");
    do {
        printf("%d  ", current->data);
        current = current->next;
    } while (current != linkQueue->front->next);
    printf("\n");
}