//
// Created by li on 2024/5/22.
//
#include <stdio.h>
#include "SharedStack.c"

int main() {
    SharedStack sharedStack;
    ElemType elemType;
    InitStack(&sharedStack);
    Push(&sharedStack, 1, 0);
    Push(&sharedStack, 2, 1);
    Pop(&sharedStack, &elemType, 0);
    printf("0号栈出栈元素：%d\n", elemType);
    Pop(&sharedStack, &elemType, 1);
    printf("1号栈出栈元素：%d\n", elemType);
    DestroyStack(&sharedStack);
    return 0;
}