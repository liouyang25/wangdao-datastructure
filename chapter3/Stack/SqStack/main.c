//
// Created by li on 2024/5/22.
//
#include "SqStack.c"

int main() {
    ElemType A[] = {1, 2, 3, 4, 5};
    int length = sizeof(A) / sizeof(A[0]);
    SqStack sqStack;
    ElemType elemType;
    InitStack(&sqStack);

    GetTop(&sqStack, &elemType);
    printf("栈顶%d\n", elemType);

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
    Push(&sqStack, 1);
    Push(&sqStack, 2);
    Push(&sqStack, 3);
    Pop(&sqStack, &elemType);
    Push(&sqStack, 4);
    GetTop(&sqStack, &elemType);
    Pop(&sqStack, &elemType);
    GetTop(&sqStack, &elemType);
    printf("栈顶%d\n", elemType);
    DestroyStack(&sqStack);
    return 0;
}