//
// Created by li on 2024/6/2.
//
#include "DLinkList.c"

int main() {
    DLinkList dLinkList = NULL;
    DLinkNode *dLinkNode = NULL;
    ElemType elemType;
    ElemType Arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(Arr) / sizeof(Arr[0]);

    InitList(&dLinkList);

//    List_HeadInsert(&dLinkList, Arr, length);    //头插法建立链表
    List_TailInsert(&dLinkList, Arr, length);    //尾插法建立链表
    PrintListWithInfo(dLinkList, 1);

    ListDelete(&dLinkList, &elemType, 1);
    PrintListWithInfo(dLinkList, 1);
    ListDelete(&dLinkList, &elemType, 2);
    PrintListWithInfo(dLinkList, 1);
    ListDelete(&dLinkList, &elemType, 4);    //第四个元素不存在
    PrintListWithInfo(dLinkList, 1);

    dLinkNode = LocateElem(dLinkList, 4);
    if (dLinkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", dLinkNode->data);
    }
    InsertPriorNode(&dLinkNode, 5);
    PrintListWithInfo(dLinkList, 1);

    dLinkNode = LocateElem(dLinkList, 20);    //没有值为20的节点
    if (dLinkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", dLinkNode->data);
    }
    dLinkNode = GetElem(dLinkList, 2);
    if (dLinkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", dLinkNode->data);
    }
//    InsertNextNode(&dLinkNode, 3);
    ListInsert(&dLinkList, 3, 3);   //插入了3
    PrintListWithInfo(dLinkList, 1);

    ListDelete(&dLinkList, &elemType, 5);   //删除了1
    PrintListWithInfo(dLinkList, 1);

    dLinkNode = LocateElem(dLinkList, 5);
    if (dLinkNode == NULL) {
        printf("没找到节点!\n");
    } else {
        printf("找到节点, 值为: %d\n", dLinkNode->data);
    }
    DeleteNode(&dLinkNode);
    PrintListWithInfo(dLinkList, 1);

    printf("长度: %d\n", Length(dLinkList));
    DestroyList(&dLinkList);
    if (dLinkList == NULL) {
        printf("链表空\n");
    } else {
        PrintListWithInfo(dLinkList, 1);
    }
    return 0;
}