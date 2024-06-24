//
// Created by li on 2024/6/24.
//
#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} Stack;

//初始化栈
bool InitStack(Stack *stack);

//入栈
bool Push(Stack *stack, ElemType elemType);

//出栈
bool Pop(Stack *stack, ElemType *elemType);

//判断栈空
bool StackEmpty(Stack stack);

//括号匹配检查
bool BracketCheck(ElemType *arr, int length);

/**
 * 初始化栈
 * @param stack 栈
 * @return true 成功 false 失败
 */
bool InitStack(Stack *stack) {
    for (int i = 0; i < MaxSize; ++i) {
        stack->data[i] = ' ';
    }
    stack->top = -1;
    return true;
}

/**
 * 入栈
 * @param stack 栈
 * @param elemType 入栈元素
 * @return true 成功 false 失败
 */
bool Push(Stack *stack, ElemType elemType) {
    if (stack->top == MaxSize - 1) {
        printf("栈满\n");
        return false;
    }
    stack->data[++stack->top] = elemType;
    return true;
}

/**
 * 出栈
 * @param stack 栈
 * @param elemType 出栈元素
 * @return true 成功 false 失败
 */
bool Pop(Stack *stack, ElemType *elemType) {
    if ((*stack).top == -1) {
        printf("栈空\n");
        return false;
    }
    *elemType = (*stack).data[(*stack).top--];
    return true;
}

/**
 * 判断栈空
 * @param stack 栈
 * @return true 栈空 false 栈不空
 */
bool StackEmpty(Stack stack) {
    return stack.top == -1;
}

/**
 * 括号匹配检查
 * @param stack 栈
 * @param arr 要检查的数组
 * @return true 成功 false 失败
 */
bool BracketCheck(ElemType *arr, int length) {
    Stack stack;
    ElemType topElem;
    InitStack(&stack);
    for (int i = 0; i < length - 1; ++i) {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
            Push(&stack, arr[i]);
        } else {
            if (StackEmpty(stack))return false;
            Pop(&stack, &topElem);
            if (topElem == '(' && arr[i] != ')')return false;
            if (topElem == '[' && arr[i] != ']')return false;
            if (topElem == '{' && arr[i] != '}')return false;
        }
    }
    return StackEmpty(stack);
}