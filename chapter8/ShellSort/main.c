//
// Created by li on 2024/8/22.
// 希尔排序
// 时间复杂度：O(n^1.3)
// 空间复杂度：O(1)
//
#include <stdio.h>

void SHellSort(int A[], int n) {
    int i, j, d, temp;
    for (d = n / 2; d >= 1; d = d / 2) {
        for (i = d; i < n; i++) {
            if (A[i] < A[i - d]) {
                temp = A[i];
                for (j = i - d; j >= 0 && A[j] > temp; j =j- d) {
                    A[j + d] = A[j];
                }
                A[j + d] = temp;
            }
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
    SHellSort(A, n);
    PrintArray(A, n);
    return 0;
}
