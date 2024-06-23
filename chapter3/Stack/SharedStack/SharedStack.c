//
// Created by li on 2024/5/22.
//
#include <stdio.h>

#define MaxSize 20
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top0;   //0号栈的指针
    int top1;   //1号栈的指针
} SharedStack;

//初始化栈
int InitStack(SharedStack *sharedStack) {
    sharedStack->top0 = -1; //初始化0号栈的指针为-1
    sharedStack->top1 = MaxSize;    //初始化1号栈的指针为MaxSize
    return 1;
}

//销毁栈
int DestroyStack(SharedStack *sharedStack) {
    sharedStack->top0 = -1; //初始化0号栈的指针为-1
    sharedStack->top1 = MaxSize;    //初始化1号栈的指针为MaxSize
    return 1;
}

//进栈
int Push(SharedStack *sharedStack, ElemType elemType, int type) {
    if (sharedStack->top0 + 1 == sharedStack->top1) return 0;
    switch (type) {
        case 0:
            sharedStack->data[++sharedStack->top0] = elemType;
            break;
        case 1:
            sharedStack->data[--sharedStack->top1] = elemType;
            break;
        default:
            return 0;
    }
    return 1;
}

//出栈
int Pop(SharedStack *sharedStack, ElemType *elemType, int type) {
    switch (type) {
        case 0:
            if (sharedStack->top0 == -1)return 0;
            *elemType = sharedStack->data[sharedStack->top0--];
            break;
        case 1:
            if (sharedStack->top1 == MaxSize)return 0;
            *elemType = sharedStack->data[sharedStack->top1++];
            break;
        default:
            return 0;
    }
    return 1;
}

//获取栈顶元素
int GetTop(SharedStack *sharedStack, ElemType *elemType, int type) {
    switch (type) {
        case 0:
            if (sharedStack->top0 == -1) {
                *elemType = -999;
                return 0;
            }
            *elemType = sharedStack->data[sharedStack->top0];
            break;
        case 1:
            if (sharedStack->top1 == MaxSize) {
                *elemType = -999;
                return 0;
            }
            *elemType = sharedStack->data[sharedStack->top1];
            break;
        default:
            return 0;
    }
    return 1;
}

//判断栈是否为空
int StackEmpty(SharedStack sharedStack) {
    if (sharedStack.top0 == -1 && sharedStack.top1 == MaxSize)return 1;
    return 0;
}