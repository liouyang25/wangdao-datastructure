//
// Created by li on 2024/6/24.
//
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef char ElemType;
typedef struct stack {
    ElemType data;
    struct stack *next;
} *Stack, StackNode;

//初始化栈
bool InitStack(Stack *stack);

//入栈
bool Push(Stack *stack, ElemType elemType);

//出栈
bool Pop(Stack *stack, ElemType *elemType);

//判断栈空
bool StackEmpty(Stack stack);

//销毁栈
void DestroyStack(Stack *stack);

//括号匹配检查
bool BracketCheck(ElemType *arr, int length);

/**
 * 初始化栈
 * @param stack 栈
 * @return true 成功 false 失败
 */
bool InitStack(Stack *stack) {
    *stack = (Stack) malloc(sizeof(Stack));
    if (!*stack)return false;
    (*stack)->next = NULL;
    return true;
}

/**
 * 入栈
 * @param stack 栈
 * @param elemType 入栈元素
 * @return true 成功 false 失败
 */
bool Push(Stack *stack, ElemType elemType) {
    if (!*stack)return false;
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    node->data = elemType;
    node->next = (*stack)->next;
    (*stack)->next = node;
    return true;
}

/**
 * 出栈
 * @param stack 栈
 * @param elemType 出栈元素
 * @return true 成功 false 失败
 */
bool Pop(Stack *stack, ElemType *elemType) {
    if (StackEmpty(*stack)) {
        printf("栈空\n");
        return false;
    }
    StackNode *node = (*stack)->next;
    *elemType = node->data;
    (*stack)->next = node->next;
    free(node);
    return true;
}

/**
 * 判断栈空
 * @param stack 栈
 * @return true 栈空 false 栈不空
 */
bool StackEmpty(Stack stack) {
    if (!stack || !stack->next)return true;
    return false;
}

/**
 * 销毁栈
 * @param stack 栈
 */
void DestroyStack(Stack *stack) {
    if (stack) {
        if ((*stack)->next) {
            StackNode *node = (*stack)->next, *temp;
            while (node != NULL) {
                temp = node->next;
                free(node);
                node = temp;
            }
        }
        free(*stack);
        *stack = NULL;
    } else {
        return;
    }
}

void Print(Stack stack) {
    if (!stack)return;
    StackNode *node = stack->next;
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

/**
 * 括号匹配检查
 * @param stack 栈
 * @param arr 要检查的数组
 * @return true 成功 false 失败
 */
bool BracketCheck(ElemType *arr, int length) {
    Stack stack = NULL;
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
    bool isEmpty = StackEmpty(stack);
    DestroyStack(&stack);
    Print(stack);
    return isEmpty;
}