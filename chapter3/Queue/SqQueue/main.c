//
// Created by li on 2024/5/28.
//
//#include "SqQueue.c"
#include "SqQueue1.c"

int main() {
    SqQueue sqQueue;
    ElemType elemType;
    int length;

    // 初始化队列
    InitQueue(&sqQueue);

    // 入队
    EnQueue(&sqQueue, 1);
    EnQueue(&sqQueue, 2);
    EnQueue(&sqQueue, 3);
    EnQueue(&sqQueue, 4);
    EnQueue(&sqQueue, 5);
    EnQueue(&sqQueue, 6);
    EnQueue(&sqQueue, 7);

    // 打印队列
    length = GetItemNum(sqQueue);
    PrintQueue(sqQueue, length);

    // 检查队列是否为空
    if (QueueEmpty(sqQueue)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    // 获取队列中的元素数量
    printf("The number of items in the queue is %d.\n", GetItemNum(sqQueue));

    // 出队
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);

    // 打印队列
    length = GetItemNum(sqQueue);
    PrintQueue(sqQueue, length);

    // 检查队列是否为空
    if (QueueEmpty(sqQueue)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    // 获取队列中的元素数量
    printf("The number of items in the queue is %d.\n", GetItemNum(sqQueue));

    return 0;
}