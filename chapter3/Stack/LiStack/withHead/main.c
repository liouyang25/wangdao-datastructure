//
// Created by li on 2024/5/24.
//
#include "LiStack.c"

int main() {
    LiStack liStack = NULL;
    ElemType elemType;

    // 测试初始化函数
    InitStack(&liStack);

    // 测试入栈函数
    Push(&liStack, 1);
    Push(&liStack, 3);
    Push(&liStack, 5);

    // 测试获取栈顶元素函数
    GetTop(&liStack, &elemType);
    printf("Top element: %d\n", elemType);  // 应该输出 5

    // 测试出栈函数
    Pop(&liStack, &elemType);
    printf("Popped element: %d\n", elemType);  // 应该输出 5

    // 再次测试获取栈顶元素函数
    GetTop(&liStack, &elemType);
    printf("Top element: %d\n", elemType);  // 应该输出 3

    // 测试栈是否为空函数
    printf("Is stack empty: %d\n", StackEmpty(&liStack));  // 应该输出 0 (表示栈不为空)

    // 测试销毁栈函数
    DestroyStack(&liStack);

    // 再次测试栈是否为空函数
    printf("Is stack empty: %d\n", StackEmpty(&liStack));  // 应该输出 1 (表示栈为空)

    //改变elemType的值，防止输出上一次赋予的值
    elemType = 999;
    // 测试获取栈顶元素函数
    GetTop(&liStack, &elemType);
    printf("Top element: %d\n", elemType);  // 应该输出 999

    return 0;
}