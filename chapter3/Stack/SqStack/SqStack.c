//
// Created by li on 2024/5/22.
//
#define MaxSize 20
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

int InitStack(SqStack *sqStack) {
    sqStack->top = -1;
    return 1;
}

int DestroyStack(SqStack *sqStack) {
    sqStack->top = -1;
    return 1;
}

int Push(SqStack *sqStack, ElemType elemType) {
    if (sqStack->top == MaxSize - 1)return 0;
    sqStack->data[++sqStack->top] = elemType;
    return 1;
}

int Pop(SqStack *sqStack, ElemType *elemType) {
    if (sqStack->top == -1)return 0;
    *elemType = sqStack->data[sqStack->top--];
    return 1;
}

int GetTop(SqStack *sqStack, ElemType *elemType) {
    if (sqStack->top == -1)return 0;
    *elemType = sqStack->data[sqStack->top];
    return 1;
}

int StackEmpty(SqStack sqStack) {
    return sqStack.top == -1 ? 0 : 1;
}