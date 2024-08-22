//
// Created by li on 2024/8/23.
// 冒泡排序
//
#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                Swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)return;
    }
}

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(A) / sizeof(A[0]);
    PrintArray(A, n);
    BubbleSort(A, n);
    PrintArray(A, n);
    return 0;
}
