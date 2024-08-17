//
// Created by li on 2024/8/17.
// 折半查找
//
#include <stdlib.h>
#include "stdio.h"

typedef int ElemType;

typedef struct {
    ElemType *elemTable;
    int TableLen;
} SSTable;

int Binary_Search(SSTable ST, ElemType key) {
    int low = 0, high = ST.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ST.elemTable[mid] == key) {
            return mid;
        }
        if (ST.elemTable[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    SSTable ST;
    ST.elemTable = (ElemType *) malloc(11 * sizeof(ElemType));
    ST.TableLen = 11;
    ST.elemTable[0] = 7;
    ST.elemTable[1] = 10;
    ST.elemTable[2] = 13;
    ST.elemTable[3] = 16;
    ST.elemTable[4] = 19;
    ST.elemTable[5] = 29;
    ST.elemTable[6] = 32;
    ST.elemTable[7] = 33;
    ST.elemTable[8] = 37;
    ST.elemTable[9] = 41;
    ST.elemTable[10] = 43;

    int res = Binary_Search(ST, 16);
    if (res == -1) {
        printf("查找失败\n");
    } else {
        printf("查找成功，元素下标为: %d\n", res);
    }

    free(ST.elemTable);
    return 0;
}
