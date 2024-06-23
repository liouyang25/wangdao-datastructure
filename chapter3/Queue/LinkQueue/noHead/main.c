//
// Created by li on 2024/6/23.
//
#include "LinkQueue.c"

int main() {
    LinkQueue linkQueue;
    ElemType elemType;

    InitQueue(&linkQueue);

    EnQueue(&linkQueue, 1);                     //1
    EnQueue(&linkQueue, 2);                     //1 2
    EnQueue(&linkQueue, 3);                     //1 2 3
    EnQueue(&linkQueue, 99);                    //1 2 3 99
    PrintQueue(linkQueue);
    DeQueue(&linkQueue, &elemType);                      //2 3 99
    EnQueue(&linkQueue, 4);                     //2 3 99 4
    EnQueue(&linkQueue, 5);                     //2 3 99 4 5
    EnQueue(&linkQueue, 6);                     //2 3 99 4 5 6
    DeQueue(&linkQueue, &elemType);                     //3 99 4 5 6
    DeQueue(&linkQueue, &elemType);                     //99 4 5 6
    DeQueue(&linkQueue, &elemType);                     //4 5 6
    EnQueue(&linkQueue, 20);                    // 4 5 6 20
    EnQueue(&linkQueue, 21);                    //4 5 6 20 21
    EnQueue(&linkQueue, 22);                    //4 5 6 20 21 22
    EnQueue(&linkQueue, 23);                    //4 5 6 20 21 22 23
    DeQueue(&linkQueue, &elemType);                     //5 6 20 21 22 23
    DeQueue(&linkQueue, &elemType);                     //6 20 21 22 23
    EnQueue(&linkQueue, 24);                    //6 20 21 22 23 24
    PrintQueue(linkQueue);
    printf("队列中元素个数: %d\n", GetItemNum(linkQueue));
    printf("对头元素: %d\n", GetHead(linkQueue));
    DestroyQueue(&linkQueue);
    PrintQueue(linkQueue);
    return 0;
}