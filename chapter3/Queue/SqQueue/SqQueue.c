//
// Created by li on 2024/5/28.
// 顺序队列
// 牺牲一个单元区分队空和队满
//
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 6
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//初始化队列
int InitQueue(SqQueue *sqQueue) {
    (*sqQueue).front = (*sqQueue).rear = 0;
    return 1;
}

//入队
int EnQueue(SqQueue *sqQueue, ElemType elemType) {
    if ((*sqQueue).front == ((*sqQueue).rear + 1) % MaxSize) {
        printf("队满\n");
        return 0;
    }
    (*sqQueue).data[(*sqQueue).rear] = elemType;
    (*sqQueue).rear = ((*sqQueue).rear + 1) % MaxSize;
    return 1;
}

//出队
int DeQueue(SqQueue *sqQueue, ElemType *elemType) {
    if ((*sqQueue).front == (*sqQueue).rear) {
        printf("队空\n");
        return 0;
    }
    *elemType = (*sqQueue).data[(*sqQueue).front];
    (*sqQueue).front = ((*sqQueue).front + 1) % MaxSize;
    return 1;
}

/**
 * 读取队头元素
 * @param sqQueue 队列
 * @param elemType 返回的队头元素
 * @return true 成功 false 失败
 */
bool GetHead(SqQueue sqQueue, ElemType *elemType) {
    if (sqQueue.front == sqQueue.rear) {
        printf("队空\n");
        return false;
    }
    *elemType = sqQueue.data[sqQueue.front];
    return true;
}

//队列是否为空
int QueueEmpty(SqQueue sqQueue) {
    if (sqQueue.front == sqQueue.rear) {
        return 1;
    } else {
        return 0;
    }
}

//队列元素个数
int GetItemNum(SqQueue sqQueue) {
    return (sqQueue.rear + MaxSize - sqQueue.front) % MaxSize;  //循环队列存不满，front和rear相等的情况下队列为空
}

//打印队列
void PrintQueue(SqQueue sqQueue) {
    if (sqQueue.front == sqQueue.rear) {
        printf("队空\n");
        return;
    }
    int tempFront = sqQueue.front;
    while (sqQueue.front != sqQueue.rear) {
        printf("%d ", sqQueue.data[sqQueue.front]);
        sqQueue.front = (sqQueue.front + 1) % MaxSize;
    }
    printf("\n");
    sqQueue.front = tempFront;
}