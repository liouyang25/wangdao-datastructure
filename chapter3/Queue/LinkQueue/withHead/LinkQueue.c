//
// Created by li on 2024/5/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct linkNode {
    ElemType data;
    struct linkNode *next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;
} *LinkQueue;

/**
 * 初始化队列
 * @param pLinkQueue 队列
 * @return true 成功 false 失败
 */
bool InitQueue(LinkQueue *pLinkQueue) {
    *pLinkQueue = (LinkQueue) malloc(sizeof(LinkQueue));
    (*pLinkQueue)->front = (*pLinkQueue)->rear = (LinkNode *) malloc(sizeof(LinkNode));
    (*pLinkQueue)->front->next = NULL;
    return true;
}

/**
 * 入队
 * @param linkQueue 队列
 * @param elemType 入队的元素
 * @return true 成功 false 失败
 */
int EnQueue(LinkQueue *linkQueue, ElemType elemType) {
    if (!*linkQueue)return false;
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = elemType;
    newNode->next = NULL;
    (*linkQueue)->rear->next = newNode;
    (*linkQueue)->rear = newNode;
    return true;
}

/**
 * 出队
 * @param linkQueue 队列
 * @param elemType 出队的元素
 * @return true 成功 false 失败
 */
bool DeQueue(LinkQueue *linkQueue, ElemType *elemType) {
    if (!*linkQueue)return false;
    if ((*linkQueue)->front == (*linkQueue)->rear) {
        printf("队空\n");
        return false;
    }
    LinkNode *node = (*linkQueue)->front->next;
    *elemType = node->data;
    (*linkQueue)->front->next = node->next;
    if (node == (*linkQueue)->rear)(*linkQueue)->rear = (*linkQueue)->front;
    free(node);
    return true;
}

//队列是否为空
bool QueueEmpty(LinkQueue linkQueue) {
    if (linkQueue->front == linkQueue->rear) {
        return true;
    } else {
        return false;
    }
}

/**
 * 读取队头元素
 * @param linkNode 队列
 * @return 对头元素
 */
ElemType GetHead(LinkQueue linkQueue) {
    if (!linkQueue || !linkQueue->front || !linkQueue->front->next)return -999;
    return linkQueue->front->next->data;
}

/**
 * 获取队列元素个数
 * @param linkQueue 队列
 * @return 队列元素个数
 */
int GetItemNum(LinkQueue linkQueue) {
    if (!linkQueue)return 0;
    if (linkQueue->front == linkQueue->rear)return 0;
    LinkNode *pNode = linkQueue->front;
    int count = 0;
    while (pNode != linkQueue->rear) {
        count++;
        pNode = pNode->next;
    }
    return count;
}

/**
 * 销毁队列
 * @param linkQueue
 * @return
 */
bool DestroyQueue(LinkQueue *linkQueue) {
    if (!*linkQueue)return false;
    LinkNode *node = (*linkQueue)->front->next, *temp;
    while (node != NULL) {
        temp = node->next;
        free(node);
        node = temp;
    }
    free(*linkQueue);
    *linkQueue = NULL;
    return true;
}

/**
 * 打印队列
 * @param linkQueue 队列
 */
void PrintQueue(LinkQueue linkQueue) {
    if (!linkQueue) {
        printf("队空\n");
        return;
    }
    if (linkQueue->front == linkQueue->rear) {
        printf("队空\n");
        return;
    }
    LinkNode *pNode = linkQueue->front->next;
    while (pNode != linkQueue->rear->next) {
        printf("%d  ", pNode->data);
        pNode = pNode->next;
    }
    printf("\n");
}