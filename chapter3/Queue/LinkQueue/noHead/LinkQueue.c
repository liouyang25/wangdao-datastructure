//
// Created by li on 2024/6/23.
//
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct linkNode {
    ElemType data;
    struct linkNode *next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;
} *LinkQueue;

//初始化队列
bool InitQueue(LinkQueue *linkQueue);

//入队
bool EnQueue(LinkQueue *linkQueue, ElemType elemType);

//出队
bool DeQueue(LinkQueue *linkQueue, ElemType *elemType);

//获取队列元素个数
int GetItemNum(LinkQueue linkQueue);

//获取对头元素
ElemType GetHead(LinkQueue linkQueue);

//销毁队列
bool DestroyQueue(LinkQueue *linkQueue);

//打印队列
void PrintQueue(LinkQueue linkQueue);

/**
 * 初始化队列
 * @param linkQueue 队列
 * @return true 成功 false 失败
 */
bool InitQueue(LinkQueue *linkQueue) {
    *linkQueue = (LinkQueue) malloc(sizeof(LinkQueue));
    (*linkQueue)->front = (*linkQueue)->rear = NULL;
    return true;
}

/**
 * 入队
 * @param linkQueue 队列
 * @param elemType 入队元素
 * @return true 成功 false 失败
 */
bool EnQueue(LinkQueue *linkQueue, ElemType elemType) {
    LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
    node->data = elemType;
    node->next = NULL;
//    if ((*linkQueue)->front == NULL) {
//        (*linkQueue)->front = node;
//        (*linkQueue)->rear = node;
//    } else {
//        (*linkQueue)->rear->next = node;
//        (*linkQueue)->rear = node;
//    }
    if ((*linkQueue)->front == NULL) {
        (*linkQueue)->front = node;
    }
    if ((*linkQueue)->rear)(*linkQueue)->rear->next = node;
    (*linkQueue)->rear = node;
    return true;
}

/**
 * 出队
 * @param linkQueue 队列
 * @param elemType 出队的元素
 * @return
 */
bool DeQueue(LinkQueue *linkQueue, ElemType *elemType) {
    if ((*linkQueue)->front == NULL)return false;
    LinkNode *node = (*linkQueue)->front;
    *elemType = node->data;
    (*linkQueue)->front = node->next;
    if (node == (*linkQueue)->rear->next)(*linkQueue)->front = (*linkQueue)->rear = NULL;
    free(node);
    return true;
}

/**
 * 获取队列元素个数
 * @param linkQueue 队列
 * @return 队列元素个数
 */
int GetItemNum(LinkQueue linkQueue) {
    if (!linkQueue || !linkQueue->front)return 0;
    int count = 0;
    LinkNode *node = linkQueue->front;
    while (node != linkQueue->rear->next) {
        count++;
        node = node->next;
    }
    return count;
}

/**
 * 获取队头元素
 * @param linkQueue 队列
 * @return 队头元素
 */
ElemType GetHead(LinkQueue linkQueue) {
    if (!linkQueue || !linkQueue->front)return -999;
    return linkQueue->front->data;
}

/**
 * 销毁队列
 * @param linkQueue 队列
 * @return true 成功 false 失败
 */
bool DestroyQueue(LinkQueue *linkQueue) {
    if (!*linkQueue)return false;
    if ((*linkQueue)->front) {
        LinkNode *node = (*linkQueue)->front, *temp;
        while (node != NULL) {
            temp = node->next;
            free(node);
            node = temp;
        }
    }
    (*linkQueue)->rear = NULL;
    free(*linkQueue);
    *linkQueue = NULL;
    return true;
}

/**
 * 打印链表
 * @param linkQueue 链表
 */
void PrintQueue(LinkQueue linkQueue) {
    if (!linkQueue || !linkQueue->front) {
        printf("队空\n");
        return;
    }
    LinkNode *node = linkQueue->front;
    while (node != linkQueue->rear->next) {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}