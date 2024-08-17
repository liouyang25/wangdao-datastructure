//
// Created by li on 2024/8/17.
// 顺序查找
//
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct {
    ElemType *elem;
    int TableLen;
} SSTable;

int Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key;
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; --i);
    return i;
}

int main() {
    //7,10,13,16,19,29,32,33,37,41,43
    SSTable ST;
    ST.elem = (ElemType *) malloc(12 * sizeof(ElemType));
    ST.TableLen = 11;
    ST.elem[1] = 7;
    ST.elem[2] = 10;
    ST.elem[3] = 13;
    ST.elem[4] = 16;
    ST.elem[5] = 19;
    ST.elem[6] = 29;
    ST.elem[7] = 32;
    ST.elem[8] = 33;
    ST.elem[9] = 37;
    ST.elem[10] = 41;
    ST.elem[11] = 43;

    int res = Search_Seq(ST, 43);
    if (res == 0) {
        printf("查找失败\n");
    } else {
        printf("查找成功，元素下标为: %d\n", res);
    }

    free(ST.elem);
    return 0;
}
