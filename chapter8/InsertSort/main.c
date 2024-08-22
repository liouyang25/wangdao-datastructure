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

void InsertSort2(int A[], int n) {
    int i, j, low, high, mid, temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--) {
            A[j + 1] = A[j];
        }
        A[high + 1] = temp;
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
