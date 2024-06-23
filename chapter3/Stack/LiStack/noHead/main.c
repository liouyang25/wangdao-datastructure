//
// Created by li on 2024/5/23.
//
#include "LiStack.c"

int main() {
    LiStack liStack;
    ElemType elemType;

    ElemType A[] = {1, 2, 3, 4, 5};
    int length = sizeof(A) / sizeof(A[0]);
    InitStack(&liStack);

    GetTop(&liStack, &elemType);
    printf("栈顶%d\n", elemType);

    for (int i = 0; i < length; ++i) {
        Push(&liStack, A[i]);
        printf("%d入栈\n", A[i]);
    }
    for (int i = 0; i < 5; ++i) {
        Pop(&liStack, &elemType);
        printf("%d出栈\n", elemType);
    }
    GetTop(&liStack, &elemType);
    printf("栈顶%d\n", elemType);
    Push(&liStack, 1);
    Push(&liStack, 2);
    Push(&liStack, 3);
    Pop(&liStack, &elemType);
    Push(&liStack, 4);
    GetTop(&liStack, &elemType);
    Pop(&liStack, &elemType);
    GetTop(&liStack, &elemType);
    printf("栈顶%d\n", elemType);
    DestroyStack(&liStack);
    return 0;
}
