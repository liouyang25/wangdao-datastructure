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
bool InitList(DLinkList *dLinkList);

//头插法建立双链表
bool List_HeadInsert(DLinkList *dLinkList, const ElemType *arr, int length);

//尾插法建立双链表
bool List_TailInsert(DLinkList *dLinkList, const ElemType *arr, int length);

//按值查找
DLinkNode *LocateElem(DLinkList dLinkList, ElemType elemType);

//按位查找
DLinkNode *GetElem(DLinkList dLinkList, int index);

//在指定序号插入元素
bool ListInsert(DLinkList *dLinkList, ElemType elemType, int index);

//在一个节点前插入一个元素
bool InsertPriorNode(DLinkNode **pDLinkNode, ElemType elemType);

//在一个节点后插入一个元素
bool InsertNextNode(DLinkNode **pDLinkNode, ElemType elemType);

//删除指定节点
bool DeleteNode(DLinkNode **pDLinkNode);

//删除指定序号节点
bool ListDelete(DLinkList *dLinkList, ElemType *elemType, int index);

//长度
int Length(DLinkList linkList);

//销毁双链表
void DestroyList(DLinkList *linkList);

//输出打印链表
void PrintList(DLinkList linkList, int type);

/**
 * 初始化双链表
 * @param dLinkList 双链表
 * @return 双链表
 */
bool InitList(DLinkList *dLinkList) {
    *dLinkList = NULL;
    return true;
}

/**
 * 头插法建立双链表
 * @param dLinkList 双链表
 * @param arr 数组
 * @param length 数组长度
 * @return 双链表
 */
bool List_HeadInsert(DLinkList *dLinkList, const ElemType *arr, int length) {
    if (*dLinkList != NULL)return false;
    DLinkNode *node = NULL;
    if (*dLinkList == NULL) {
        node = (DLinkNode *) malloc(sizeof(DLinkNode));
        node->data = arr[0];
        node->next = node->prior = NULL;
        *dLinkList = node;
    }
    for (int i = 1; i < length; ++i) {
        node = (DLinkNode *) malloc(sizeof(DLinkNode));
        node->data = arr[i];
        node->next = (*dLinkList);
        node->prior = NULL;
        (*dLinkList)->prior = node;
        *dLinkList = node;
    }
    return true;
}

/**
 * 尾插法建立双链表
 * @param dLinkList 双链表
 * @param arr 数组
 * @param length 数组长度
 * @return 双链表
 */
bool List_TailInsert(DLinkList *dLinkList, const ElemType *arr, int length) {
    if (*dLinkList != NULL)return false;
    DLinkNode *node = NULL, *rear = NULL;
    node = (DLinkNode *) malloc(sizeof(DLinkNode));
    node->data = arr[0];
    node->next = node->prior = NULL;
    *dLinkList = node;
    rear = *dLinkList;
    for (int i = 1; i < length; ++i) {
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
DLinkNode *LocateElem(DLinkList dLinkList, ElemType elemType) {
    if (dLinkList == NULL)return NULL;
    DLinkNode *node = dLinkList;
    while (node != NULL && node->data != elemType) {
        node = node->next;
    }
    return node;
}

/**
 * 按位序查找节点
 * @param dLinkList 链表
 * @param index 位序
 * @return 查找到的节点，失败返回NULL
 */
DLinkNode *GetElem(DLinkList dLinkList, int index) {
    if (index < 0 || dLinkList == NULL)return NULL;
    DLinkNode *node = dLinkList;
    int i = 1;
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
bool ListInsert(DLinkList *dLinkList, ElemType elemType, int index) {
    if (*dLinkList == NULL || index < 1)return false;
    if (index == 1) {
        DLinkNode *node = (DLinkNode *) malloc(sizeof(DLinkNode));
        node->data = elemType;
        node->next = *dLinkList;
        node->prior = NULL;
        (*dLinkList)->prior = node;
        *dLinkList = node;
        return true;
    }
    DLinkNode *node = GetElem(*dLinkList, index - 1);
    return InsertNextNode(&node, elemType);
}

/**
 * 在指定节点前插入元素
 * @param linkNode 要插入节点的位置
 * @param elemType 插入的内容
 * @return true 成功 false 失败
 */
bool InsertPriorNode(DLinkNode **pDLinkNode, ElemType elemType) {
    if (*pDLinkNode == NULL || (*pDLinkNode)->prior == NULL)return false;
    DLinkNode *node = (DLinkNode *) malloc(sizeof(DLinkNode));
    node->data = elemType;
    node->prior = (*pDLinkNode)->prior;
    node->next = *pDLinkNode;
    (*pDLinkNode)->prior->next = node;
    (*pDLinkNode)->prior = node;
    return true;
}

/**
 * 在一个节点后插入一个元素
 * @param linkNode 要插入节点的位置
 * @param elemType 插入的内容
 * @return true 成功 false 失败
 */
bool InsertNextNode(DLinkNode **pDLinkNode, ElemType elemType) {
    if (*pDLinkNode == NULL)return false;
    DLinkNode *node = (DLinkNode *) malloc(sizeof(DLinkNode));
    node->data = elemType;
    node->next = (*pDLinkNode)->next;
    node->prior = *pDLinkNode;
    if ((*pDLinkNode)->next) {
        (*pDLinkNode)->next->prior = node;
    }
    (*pDLinkNode)->next = node;
    return true;
}

/**
 * 删除指定节点
 * @param pDLinkNode 要删除的节点
 * @return true 成功 false 失败
 */
bool DeleteNode(DLinkNode **pDLinkNode) {
    if (*pDLinkNode == NULL)return false;
    DLinkNode *node = *pDLinkNode;
    if (node->prior) {
        node->prior->next = node->next;
    }
    if (node->next) {
        node->next->prior = node->prior;
    }
    free(node);
    return true;
}

/**
 * 删除指定序号节点
 * @param dLinkList 链表
 * @param elemType 插入节点的内容
 * @param index 插入的位序
 * @return true 成功 false 失败
 */
bool ListDelete(DLinkList *dLinkList, ElemType *elemType, int index) {
    if (index < 1 || *dLinkList == NULL)return false;
    if (index == 1) {
        DLinkNode *node = *dLinkList;
        *elemType = node->data;
        *dLinkList = node->next;
        (*dLinkList)->prior = NULL;
        free(node);
        return true;
    }
    DLinkNode *node = GetElem(*dLinkList, index);
    if (node == NULL)return false;
    *elemType = node->data;
    return DeleteNode(&node);
}

/**
 * 链表长度
 * @param linkList 链表
 * @return 长度
 */
int Length(DLinkList linkList) {
    if (linkList == NULL)return 0;
    int length = 0;
    DLinkNode *node = linkList;
    while (node != NULL) {
        length++;
        node = node->next;
    }
    return length;
}

/**
 * 销毁双链表
 * @param linkList 双链表
 */
void DestroyList(DLinkList *linkList) {
    DLinkNode *temp;
    while ((*linkList) != NULL) {
        temp = (*linkList)->next;
        free(*linkList);
        *linkList = temp;
    }
    *linkList = NULL;
}

/**
 * 输出打印链表
 * @param linkList 双链表
 * @param type 1 顺序输出 0 逆序输出
 */
void PrintList(DLinkList dLinkList, int type) {
    if (dLinkList == NULL)return;
    DLinkNode *node = dLinkList, *rear = dLinkList;
    while (rear->next != NULL) {
        rear = rear->next;
    }
    if (type == 1) {
        while (node != NULL) {
            printf("%d  ", node->data);
            node = node->next;
        }
    }
    int i = 0;
    if (type == 0) {
        while (rear != NULL && i++ < 20) {
            printf("%d  ", rear->data);
            rear = rear->prior;
        }
    }
    printf("\n");
}

void PrintListWithInfo(DLinkList dLinkList, int type) {
    if (dLinkList == NULL)return;
    printf("双链表: ");
    PrintList(dLinkList, type);
}