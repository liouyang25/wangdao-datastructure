//
// Created by li on 2024/5/28.
//
//#include "SqQueue.c"
#include "SqQueue1.c"

int main() {
    SqQueue sqQueue;
    ElemType elemType;

    InitQueue(&sqQueue);

    EnQueue(&sqQueue, 1);
    EnQueue(&sqQueue, 2);
    EnQueue(&sqQueue, 3);
    EnQueue(&sqQueue, 99);
    PrintQueue(sqQueue);
    DeQueue(&sqQueue, &elemType);
    EnQueue(&sqQueue, 4);
    EnQueue(&sqQueue, 5);
    EnQueue(&sqQueue, 6);
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);
    EnQueue(&sqQueue, 20);
    EnQueue(&sqQueue, 21);
    EnQueue(&sqQueue, 22);
    EnQueue(&sqQueue, 23);
    DeQueue(&sqQueue, &elemType);
    DeQueue(&sqQueue, &elemType);
    EnQueue(&sqQueue, 24);

    PrintQueue(sqQueue);
    GetHead(sqQueue, &elemType);
    printf("对头元素: %d\n", elemType);
    return 0;
}