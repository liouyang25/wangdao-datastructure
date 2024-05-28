//
// Created by li on 2024/5/28.
// 顺序队列
// 牺牲一个单元区分队空和队满
//
#include <stdio.h>

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
    if ((*sqQueue).front == ((*sqQueue).rear + 1) % MaxSize)return 0;
    (*sqQueue).data[(*sqQueue).rear] = elemType;
    (*sqQueue).rear = ((*sqQueue).rear + 1) % MaxSize;
    return 1;
}

//出队
int DeQueue(SqQueue *sqQueue, ElemType *elemType) {
    if ((*sqQueue).front == (*sqQueue).rear)return 0;
    *elemType = (*sqQueue).data[(*sqQueue).front];
    (*sqQueue).front = ((*sqQueue).front + 1) % MaxSize;
    return 1;
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
void PrintQueue(SqQueue sqQueue, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", sqQueue.data[i]);
    }
    printf("\n");
}