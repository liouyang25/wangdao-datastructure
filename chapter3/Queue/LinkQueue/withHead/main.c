//
// Created by li on 2024/5/29.
//
#include "LinkQueue.c"

int main() {
    LinkQueue linkQueue;
    ElemType elemType;

    // 初始化队列
    InitQueue(&linkQueue);

    // 入队
    EnQueue(&linkQueue, 1);
    EnQueue(&linkQueue, 2);
    EnQueue(&linkQueue, 3);
    EnQueue(&linkQueue, 4);
    EnQueue(&linkQueue, 5);
    EnQueue(&linkQueue, 6);

    // 打印队列
    PrintQueue(linkQueue);

    // 检查队列是否为空
    if (QueueEmpty(linkQueue)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    // 获取队列中的元素数量
    printf("The number of items in the queue is %d.\n", GetItemNum(linkQueue));

    // 出队
    DeQueue(&linkQueue, &elemType);
    DeQueue(&linkQueue, &elemType);
    DeQueue(&linkQueue, &elemType);
    DeQueue(&linkQueue, &elemType);
    DeQueue(&linkQueue, &elemType);
    DeQueue(&linkQueue, &elemType);

    // 打印队列
    PrintQueue(linkQueue);

    // 检查队列是否为空
    if (QueueEmpty(linkQueue)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    // 获取队列中的元素数量
    printf("The number of items in the queue is %d.\n", GetItemNum(linkQueue));

    return 0;
}