//
// Created by li on 2024/6/24.
//
#include "Stack.c"

int main() {
    ElemType arr[] = "{[[[({})[]({}){{{{{[[[[[(())]]]]]}}}}}{[[()]]}]]]}";
    int length = sizeof(arr) / sizeof(arr[0]);

    if (BracketCheck(arr, length)) {
        printf("匹配\n");
    } else {
        printf("不匹配\n");
    }
    return 0;
}