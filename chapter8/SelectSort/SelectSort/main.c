//
// Created by li on 2024/8/23.
// 选择排序
//
#include<stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i)Swap(&A[i], &A[min]);
    }
}

void SelectSort2(int A[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int max = i;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] > A[max]) {
                max = j;
            }
        }
        if (max != i)Swap(&A[i], &A[max]);
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
    SelectSort2(A, n);
    PrintArray(A, n);
    return 0;
}
