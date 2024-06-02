//
// Created by li on 2024/5/30.
//
#include "LinkList.c"

int main() {
    LinkList linkList = NULL;
    LinkNode *linkNode = NULL;
    ElemType elemType;
    ElemType Arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(Arr) / sizeof(Arr[0]);

    InitList(&linkList);    //初始化链表

//    List_HeadInsert(&linkList, Arr, length);    //头插法建立链表
    List_TailInsert(&linkList, Arr, length);    //尾插法建立链表
    PrintListWithInfo(linkList);

    ListDelete(&linkList, &elemType, 1);
    PrintListWithInfo(linkList);
    ListDelete(&linkList, &elemType, 2);
    PrintListWithInfo(linkList);
    ListDelete(&linkList, &elemType, 4);    //第四个元素不存在
    PrintListWithInfo(linkList);

    linkNode = LocateElem(linkList, 4);
    if (linkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", linkNode->data);
    }

    InsertPriorNode(&linkNode, 5);
    PrintListWithInfo(linkList);

    linkNode = LocateElem(linkList, 20);    //没有值为20的节点
    if (linkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", linkNode->data);
    }
    linkNode = GetElem(linkList, 2);
    if (linkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", linkNode->data);
    }
//    InsertNextNode(&linkNode, 3);
    ListInsert(&linkList, 3, 3);
    PrintListWithInfo(linkList);

    ListDelete(&linkList, &elemType, 5);
    PrintListWithInfo(linkList);

    linkNode = LocateElem(linkList, 5);
    if (linkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", linkNode->data);
    }
    DeleteNode(&linkNode);
    PrintListWithInfo(linkList);

    printf("长度: %d\n", Length(linkList));
    DestroyList(&linkList);
    if (linkList == NULL) {
        printf("链表空\n");
    } else {
        PrintListWithInfo(linkList);
    }
    return 0;
}