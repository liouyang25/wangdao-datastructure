//
// Created by li on 2024/8/22.
// 插入排序
//
#include <stdio.h>

void InsertSort(int A[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; j--) {
                A[j + 1] = A[j];
            }
            A[j + 1] = temp;
        }
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
    InsertSort(A, n);
    PrintArray(A, n);
    return 0;
}
