//
// Created by li on 2024/5/28.
// 顺序队列
// 使用size或tag区分队列满或队列空
//
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
    int tag;    //tag为1表示上次为入队操作，为0表示为出队操作
    int size;   //表示当前元素的个数
} SqQueue;

/**
 * 初始化队列
 * @param sqQueue 队列
 * @return
 */
bool InitQueue(SqQueue *sqQueue) {
    (*sqQueue).front = 0;
    (*sqQueue).rear = MaxSize - 1;
    (*sqQueue).size = 0;
    (*sqQueue).tag = -1;
    return true;
}

/**
 * 入队
 * @param sqQueue 队列
 * @param elemType 入队的元素
 * @return true 成功 false 失败
 */
bool EnQueue(SqQueue *sqQueue, ElemType elemType) {
    if ((*sqQueue).front == ((*sqQueue).rear + 1) % MaxSize && ((*sqQueue).tag == 1 || (*sqQueue).size == MaxSize)) {
        printf("队满\n");
        return false;
    }
    (*sqQueue).rear = ((*sqQueue).rear + 1) % MaxSize;
    (*sqQueue).data[(*sqQueue).rear] = elemType;
    (*sqQueue).size++;
    (*sqQueue).tag = 1;
    return true;
}

/**
 * 出队
 * @param sqQueue 队列
 * @param elemType 出队的元素
 * @return true 成功 false 失败
 */
bool DeQueue(SqQueue *sqQueue, ElemType *elemType) {
    if ((*sqQueue).front == (*sqQueue).rear && ((*sqQueue).size == 0 || (*sqQueue).tag == 0)) {
        printf("队空\n");
        return false;
    }
    *elemType = (*sqQueue).data[(*sqQueue).front];
    (*sqQueue).front = ((*sqQueue).front + 1) % MaxSize;
    (*sqQueue).size--;
    (*sqQueue).tag = 0;
    return true;
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

/**
 * 打印队列
 * @param sqQueue 队列
 */
void PrintQueue(SqQueue sqQueue) {
    if (sqQueue.front == sqQueue.rear && (sqQueue.size == 0 || sqQueue.tag == 0)) {
        printf("队空\n");
        return;
    }
    int tempFront = sqQueue.front;
    while (sqQueue.front != (sqQueue.rear + 1) % MaxSize) {
        printf("%d ", sqQueue.data[sqQueue.front]);
        sqQueue.front = (sqQueue.front + 1) % MaxSize;
    }
    printf("\n");
    sqQueue.front = tempFront;
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