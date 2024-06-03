//
// Created by li on 2024/6/2.
// 不带头节点
//
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define bool int

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DLinkNode, *DLinkList;

//初始化链表
bool InitList(DLinkList *linkList);

//头插法建立双链表
bool List_HeadInsert(DLinkList *linkList, const ElemType *arr, int length);

//尾插法建立双链表
bool List_TailInsert(DLinkList *linkList, const ElemType *arr, int length);

//按值查找
DLinkNode *LocateElem(DLinkList linkList, ElemType elemType);

//按位查找
DLinkNode *GetElem(DLinkList linkList, int index);

//在指定序号插入元素
bool ListInsert(DLinkList *linkList, ElemType elemType, int index);

//在一个节点前插入一个元素
bool InsertPriorNode(DLinkNode **linkNode, ElemType elemType);

//在一个节点后插入一个元素
bool InsertNextNode(DLinkNode **linkNode, ElemType elemType);

//删除指定节点
bool DeleteNode(DLinkNode **linkNode);

//删除指定序号节点
bool ListDelete(DLinkList *linkList, ElemType *elemType, int index);

//输出打印链表
void PrintList(DLinkList linkList, int type);

//长度
int Length(DLinkList linkList);

//销毁双链表
void DestroyList(DLinkList *linkList);