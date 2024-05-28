//
// Created by li on 2024/5/28.
// 顺序队列
// 使用size或tag区分队列满或队列空
//
#include <stdio.h>

#define MaxSize 6
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
    int tag;    //tag为1表示上次为入队操作，为0表示为出队操作
    int size;   //表示当前元素的个数
} SqQueue;

//初始化队列
int InitQueue(SqQueue *sqQueue) {
    (*sqQueue).front = (*sqQueue).rear = 0;
    (*sqQueue).size = 0;
    (*sqQueue).tag = -1;
    return 1;
}

//入队
int EnQueue(SqQueue *sqQueue, ElemType elemType) {
    if ((*sqQueue).front == (*sqQueue).rear && ((*sqQueue).size == MaxSize || (*sqQueue).tag == 1))return 0;
    (*sqQueue).data[(*sqQueue).rear] = elemType;
    (*sqQueue).rear = ((*sqQueue).rear + 1) % MaxSize;
    (*sqQueue).size++;
    (*sqQueue).tag = 1;
    return 1;
}

//出队
int DeQueue(SqQueue *sqQueue, ElemType *elemType) {
    if ((*sqQueue).front == (*sqQueue).rear && ((*sqQueue).size == 0 || (*sqQueue).tag == 0))return 0;
    *elemType = (*sqQueue).data[(*sqQueue).front];
    (*sqQueue).front = ((*sqQueue).front + 1) % MaxSize;
    (*sqQueue).size--;
    (*sqQueue).tag = 0;
    return 1;
}

//队列是否为空
int QueueEmpty(SqQueue sqQueue) {
    if (sqQueue.front == sqQueue.rear && (sqQueue.size == 0 || sqQueue.tag == 0)) {
        return 1;
    } else {
        return 0;
    }
}

//队列元素个数
int GetItemNum(SqQueue sqQueue) {
    return sqQueue.size;
}

//打印队列
void PrintQueue(SqQueue sqQueue, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", sqQueue.data[i]);
    }
    printf("\n");
}