//
// Created by li on 2024/7/17.
//
#include "HString.c"

int main() {
    HString T, S1, S2, Sub;

    // 测试 StrAssign
    StrAssign(&T, "liouyang25");
    printf("字符串 T 赋值结果: ");
    PrintString(T);

    // 测试 StrCopy
    StrCopy(&S1, T);
    printf("复制字符串 T 到 S1 的结果: ");
    PrintString(S1);

    // 测试 StrEmpty
    printf("字符串 S1 是否为空: %s\n", StrEmpty(S1) ? "是" : "否");

    // 测试 StrCompare
    StrAssign(&S2, "liouyang");
    int cmpResult = StrCompare(S1, S2);
    if (cmpResult > 0) {
        printf("字符串 S1 比字符串 S2 大\n");
    } else if (cmpResult == 0) {
        printf("字符串 S1 与字符串 S2 相等\n");
    } else {
        printf("字符串 S1 比字符串 S2 小\n");
    }

    // 测试 StrLength
    printf("字符串 S1 的长度: %d\n", StrLength(S1));

    // 测试 SubString
    SubString(&Sub, S1, 3, 6);
    printf("从字符串 S1 的第 3 个字符开始截取 6 个字符: ");
    PrintString(Sub);

    // 测试 Concat
    Concat(&T, &S1, &S2);
    printf("连接字符串 S1 和 S2 的结果: ");
    PrintString(T);

    // 测试 Index
    int pos = Index(&T, &Sub);
    printf("子串 Sub 在字符串 T 中的位置: %d\n", pos);

    // 测试 ClearString
    ClearString(&S1);
    printf("清空字符串 S1 的结果: ");
    PrintString(S1);

    // 测试 DestroyString
    DestroyString(&S2);
    printf("销毁字符串 S2 的结果: ");
    PrintString(S2);

    return 0;
}
