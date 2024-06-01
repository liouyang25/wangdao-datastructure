//
// Created by li on 2024/5/30.
// 不带头节点
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} *LinkList, LinkNode;

//初始化
int InitList(LinkList *linkList);

//插入
int ListInsert(LinkList *linkList, ElemType elemType, int index);

//在一个节点前插入一个元素
int InsertPriorNode(LinkNode **linkNode, ElemType elemType);

//在一个节点后插入一个元素
int InsertNextNode(LinkNode **linkNode, ElemType elemType);

//删除节点
int ListDelete(LinkList *linkList, ElemType *elemType, int index);

//删除指定节点
int DeleteNode(LinkNode **linkNode);

//按位查找
LinkNode *GetElem(LinkList linkList, int index);

//按值查找
LinkNode *LocateElem(LinkList linkList, ElemType elemType);

//输出打印链表
void PrintList(LinkList linkList);

//长度
int Length(LinkList linkList);

int InitList(LinkList *linkList) {
    *linkList = NULL;
    return 1;
}

int ListInsert(LinkList *linkList, ElemType elemType, int index) {
    if (index < 1)return 0;
    LinkNode *newNode;
    if (index == 1) {
        newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->data = elemType;
        newNode->next = *linkList;
        *linkList = newNode;
        return 1;
    }
//    LinkNode *node = *linkList;
//    int i = 1;
//    while (node != NULL && i < index - 1) {
//        node = node->next;
//        i++;
//    }
    LinkNode *node = GetElem(*linkList, index - 1);
//    if (node == NULL)return 0;
//    newNode = (LinkNode *) malloc(sizeof(LinkNode));
//    newNode->data = elemType;
//    newNode->next = node->next;
//    node->next = newNode;
//    return 1;
    //在第i个位置插入新节点相当于在第i-1个节点后面插入一个节点，可以使用InsertNextNode在i-1个节点后插入新节点
    return InsertNextNode(&node, elemType);
}

/**
 * 在节点前插入元素
 * @param linkNode 在linkNode节点之前插入
 * @param elemType 插入的内容
 * @return 0 失败 1 成功
 */
int InsertPriorNode(LinkNode **linkNode, ElemType elemType) {
    if (&(*linkNode) == NULL) return 0;
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = (*linkNode)->data;
    newNode->next = (*linkNode)->next;
    (*linkNode)->next = newNode;
    (*linkNode)->data = elemType;
    return 1;
}

/**
 * 在节点后插入元素
 * @param linkNode 在linkNode节点之后插入
 * @param elemType 插入的内容
 * @return 0 失败 1 成功
 */
int InsertNextNode(LinkNode **linkNode, ElemType elemType) {
    if ((*linkNode) == NULL)return 0;
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = elemType;
    newNode->next = (*linkNode)->next;
    (*linkNode)->next = newNode;
    return 1;
}

int ListDelete(LinkList *linkList, ElemType *elemType, int index) {
    if (index < 1)return 0;
    LinkNode *node = *linkList, *temp;
    if (index == 1) {
        if (node == NULL || node->next == NULL)return 0;
        temp = node->next;
        *elemType = node->data;
        *linkList = temp;
        free(node);
        return 1;
    }
//    int i = 1;
//    while (node != NULL && i < index - 1) {
//        node = node->next;
//        i++;
//    }
    node = GetElem(*linkList, index - 1);
    if (node == NULL || node->next == NULL)return 0;
    //此时node为index-1个元素
    temp = node->next;
    *elemType = temp->data;
    node->next = temp->next;
    free(temp);
    return 1;
}

/**
 * 删除指定节点
 * @param linkNode 需要删除的节点
 * @return 1 成功 0 失败
 * @attention 不能删除最后一个节点
 */
int DeleteNode(LinkNode **linkNode) {
    if ((*linkNode) == NULL || (*linkNode)->next == NULL)return 0;
    LinkNode *temp = (*linkNode)->next;    //要删除的下一个元素
    (*linkNode)->data = temp->data;  //将下一个元素的值复制到要删除的那个元素，之后只需要删除下一个元素就行
    (*linkNode)->next = temp->next;
    free(temp);
    return 1;
}

LinkNode *GetElem(LinkList linkList, int index) {
    if (index <= 0)return NULL;
    LinkNode *node = linkList;
    int i = 1;
    while (node != NULL && i < index) {
        node = node->next;
        i++;
    }
    return node;
}

LinkNode *LocateElem(LinkList linkList, ElemType elemType) {
    LinkNode *node = linkList;
    while (node != NULL && node->data != elemType) {
        node = node->next;
    }
    return node;
}

void PrintList(LinkList linkList) {
    LinkNode *node = linkList;
    while (node != NULL) {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}

int Length(LinkList linkList) {
    int count = 0;
    LinkNode *node = linkList;
    while (node != NULL) {
        node = node->next;
        count++;
    }
    return count;
}