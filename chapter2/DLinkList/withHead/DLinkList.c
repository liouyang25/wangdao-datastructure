//
// Created by li on 2024/6/2.
// 带头节点
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

/**
 * 初始化链表
 * @param linkList 头节点
 * @return true 成功 false 失败
 */
bool InitList(DLinkList *linkList) {
    *linkList = (DLinkNode *) malloc(sizeof(DLinkNode));
    if (*linkList == NULL)return false;
    (*linkList)->data = 0;
    (*linkList)->prior = (*linkList)->next = NULL;
    return true;
}

/**
 * 头插法建立链表
 * @param dLinkList 链表
 * @param arr 数组
 * @param length 数组长度
 * @return true 成功 false 失败
 */
bool List_HeadInsert(DLinkList *dLinkList, const ElemType *arr, int length) {
    if (*dLinkList == NULL) return false;
    DLinkNode *node;
    for (int i = 0; i < length; ++i) {
        node = (DLinkNode *) malloc(sizeof(DLinkNode));
        node->data = arr[i];
        node->prior = *dLinkList;
        node->next = (*dLinkList)->next;
        if ((*dLinkList)->next != NULL) {
            (*dLinkList)->next->prior = node;
        }
        (*dLinkList)->next = node;
    }
    return true;
}

/**
 * 尾插法建立链表
 * @param dLinkList 链表
 * @param arr 数组
 * @param length 数组长度
 * @return true 成功 false 失败
 */
bool List_TailInsert(DLinkList *dLinkList, const ElemType *arr, int length) {
    if (*dLinkList == NULL)return false;
    DLinkNode *rear = *dLinkList, *node;
    for (int i = 0; i < length; ++i) {
        node = (DLinkNode *) malloc(sizeof(DLinkNode));
        node->data = arr[i];
        node->next = rear->next;
        node->prior = rear;
        rear->next = node;
        rear = node;
    }
    return true;
}

/**
 * 按值查找节点
 * @param linkList 链表
 * @param elemType 查找的值
 * @return 找到的节点，失败返回NULL
 */
DLinkNode *LocateElem(DLinkList linkList, ElemType elemType) {
    if (linkList == NULL)return NULL;
    DLinkNode *node = linkList->next;
    while (node != NULL && node->data != elemType) {
        node = node->next;
    }
    return node;
}

/**
 * 按位序查找节点
 * @param linkList 链表
 * @param index 查找的位序
 * @return 找到的节点，失败返回NULL
 */
DLinkNode *GetElem(DLinkList linkList, int index) {
    if (index < 0 || linkList == NULL)return NULL;
    int i = 0;
    DLinkNode *node = linkList;
    while (node != NULL && i < index) {
        node = node->next;
        i++;
    }
    return node;
}

/**
 * 在指定序号插入元素
 * @param linkList 链表
 * @param elemType 插入的内容
 * @param index 要插入节点的位序
 * @return true 成功 false 失败
 */
bool ListInsert(DLinkList *linkList, ElemType elemType, int index) {
    if (*linkList == NULL || index < 1)return false;
    DLinkNode *node = GetElem(*linkList, index - 1);
    return InsertNextNode(&node, elemType);
}

/**
 * 在指定节点前插入元素
 * @param linkNode 要插入节点的位置
 * @param elemType 插入的内容
 * @return true 成功 false 失败
 */
bool InsertPriorNode(DLinkNode **linkNode, ElemType elemType) {
    if (*linkNode == NULL)return false;
    DLinkNode *node = (DLinkNode *) malloc(sizeof(DLinkNode));
    node->data = elemType;
    node->next = *linkNode;
    node->prior = (*linkNode)->prior;
    if ((*linkNode)->prior != NULL) {
        (*linkNode)->prior->next = node;
    }
    (*linkNode)->prior = node;
    return true;
}

/**
 * 在一个节点后插入一个元素
 * @param linkNode 要插入节点的位置
 * @param elemType 插入的内容
 * @return true 成功 false 失败
 */
bool InsertNextNode(DLinkNode **linkNode, ElemType elemType) {
    if (*linkNode == NULL)return false;
    DLinkNode *node = (DLinkNode *) malloc(sizeof(DLinkNode));
    node->data = elemType;
    node->next = (*linkNode)->next;
    node->prior = *linkNode;
    if ((*linkNode)->next != NULL) {
        (*linkNode)->next->prior = node;
    }
    (*linkNode)->next = node;
    return true;
}

/**
 * 删除指定节点
 * @param pDLinkNode 要删除的节点
 * @return true 成功 false 失败
 */
bool DeleteNode(DLinkNode **pDLinkNode) {
    if (*pDLinkNode == NULL || (*pDLinkNode)->prior == NULL)return false;
    DLinkNode *node = *pDLinkNode;
    (*pDLinkNode)->prior->next = node->next;
    if ((*pDLinkNode)->next != NULL) {
        (*pDLinkNode)->next->prior = node->prior;
    }
    free(*pDLinkNode);
    *pDLinkNode = NULL;
    return true;
}
/**
 * 删除指定序号节点
 * @param linkList 链表
 * @param elemType 返回删除节点的值
 * @param index 要删除的序号
 * @return true 成功 false 失败
 */
bool ListDelete(DLinkList *linkList, ElemType *elemType, int index) {
    if (index < 1)return false;
    DLinkNode *node = GetElem(*linkList, index);
    if (node == NULL)return false;
    *elemType = node->data;
    return DeleteNode(&node);
}

/**
 * 输出打印链表
 * @param linkList 链表
 * @param type 1 顺序输出 0 逆序输出
 */
void PrintList(DLinkList linkList, int type) {
    DLinkNode *node = linkList->next, *rear = linkList->next;
    while (rear->next != NULL) {
        rear = rear->next;
    }
    if (type == 1) {
        while (node != NULL) {
            printf("%d  ", node->data);
            node = node->next;
        }
    }
    if (type == 0) {
        while (rear->prior != NULL) {
            printf("%d  ", rear->data);
            rear = rear->prior;
        }
    }
    printf("\n");
}

void PrintListWithInfo(DLinkList linkList, int type) {
    if (linkList == NULL)return;
    printf("链表: ");
    PrintList(linkList, type);
}

/**
 * 链表长度
 * @param linkList 链表
 * @return 长度
 */
int Length(DLinkList linkList) {
    if (linkList == NULL)return 0;
    DLinkNode *node = linkList->next;
    int count = 0;
    while (node != NULL) {
        node = node->next;
        count++;
    }
    return count;
}

/**
 * 销毁双链表
 * @param linkList 双链表
 */
void DestroyList(DLinkList *linkList) {
    DLinkNode *temp;
    while (*linkList != NULL) {
        temp = (*linkList)->next;
        free(*linkList);
        *linkList = temp;
    }
    *linkList = NULL;
}