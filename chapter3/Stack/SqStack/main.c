//
// Created by li on 2024/5/22.
//
#include <stdio.h>
#include "SqStack.c"

int main() {
    ElemType A[] = {23, 56, 42, 78, 43, 21, 89, 98};
    int length = sizeof(A) / sizeof(A[0]);
    SqStack sqStack;
    ElemType elemType;
    InitStack(&sqStack);
    for (int i = 0; i < length; ++i) {
        Push(&sqStack, A[i]);
        printf("%d入栈\n", A[i]);
    }
    for (int i = 0; i < 5; ++i) {
        Pop(&sqStack, &elemType);
        printf("%d出栈\n", elemType);
    }
    GetTop(&sqStack, &elemType);
    printf("栈顶%d\n", elemType);
    DestroyStack(&sqStack);
    return 0;
}