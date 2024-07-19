//
// Created by li on 2024/7/17.
//
#include <stdbool.h>
#include <stdio.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} HString;

//将字符数组 chars 赋值给串 T
bool StrAssign(HString *T, char *chars);

//复制串 S 到串 T
bool StrCopy(HString *T, HString S);

//判断串 T 是否为空
bool StrEmpty(HString T);

//比较两个串
int StrCompare(HString T, HString S);

//计算串 T 的长度
int StrLength(HString T);

//从串 S 的第 pos 个字符起，截取长度为 len 的子串到 T
bool SubString(HString *T, HString S, int pos, int len);

//将串 S2 连接到串 S1 的末尾，结果存储在 T 中
bool Concat(HString *T, const HString *S1, const HString *S2);

//查找子串位置函数
int Index(const HString *T, const HString *S);

//清空字符串函数
void ClearString(HString *S);

//销毁字符串函数
void DestroyString(HString *S);

//打印串
void PrintString(HString T);

/**
 * 将字符数组 chars 赋值给串 T
 * @param T 赋值到的串
 * @param chars 赋值的字符
 * @return true 成功 false 失败
 */
bool StrAssign(HString *T, char *chars) {
    int i = 1;
    while (chars[i - 1] != '\0' && i < MAXLEN) {
        T->ch[i] = chars[i - 1];
        i++;
    }
    T->ch[i] = '\0';
    T->length = i - 1;
    if (i == MAXLEN && chars[i - 1] != '\0') return false;
    return true;
}

/**
 * 复制串 S 到串 T
 * @param T 复制到的串
 * @param S 源串
 * @return true 成功 false 失败
 */
bool StrCopy(HString *T, HString S) {
    T->length = S.length;
    for (int i = 1; i <= S.length; i++) {
        T->ch[i] = S.ch[i];
    }
    T->ch[S.length + 1] = '\0';
    return true;
}

/**
 * 判断串 T 是否为空
 * @param T 串
 * @return true 空 false 非空
 */
bool StrEmpty(HString T) {
    return T.length == 0;
}

/**
 * 比较两个串
 * @param T 串
 * @param S 要比较的串
 * @return >0 S>T =0 S=T <0 S<T
 */
int StrCompare(HString T, HString S) {
    for (int i = 1; i <= T.length && i <= S.length; i++) {
        if (T.ch[i] != S.ch[i]) {
            return T.ch[i] - S.ch[i];
        }
    }
    return T.length - S.length;
}

/**
 * 计算串 T 的长度
 * @param T 串
 * @return 串长
 */
int StrLength(HString T) {
    return T.length;
}

/**
 * 从串 S 的第 pos 个字符起，截取长度为 len 的子串到 T
 * @param T 找到的子串
 * @param S 源子串
 * @param pos 开始位置
 * @param len 长度
 * @return true 成功 false 失败
 */
bool SubString(HString *T, HString S, int pos, int len) {
    if (pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length)return false;
    T->length = len;
    for (int i = 1; i <= len; i++) {
        T->ch[i] = S.ch[pos + i - 1];
    }
    T->ch[len + 1] = '\0';
    return true;
}

/**
 * 将串 S2 连接到串 S1 的末尾，结果存储在 T 中
 * @param T 连接后的串
 * @param S1 排在前面的串
 * @param S2 后面的串
 * @return true 成功 false 失败
 */
bool Concat(HString *T, const HString *S1, const HString *S2) {
    int len = S1->length + S2->length;
    if (len >= MAXLEN)return false;
    int index = 1;
    for (int i = 1; i <= S1->length; i++) T->ch[index++] = S1->ch[i];
    for (int j = 1; j <= S2->length; j++) T->ch[index++] = S2->ch[j];
    T->length = len;
    T->ch[len + 1] = '\0';
    return true;
}

/**
 * 查找子串位置函数
 * @param T 串
 * @param S 子串
 * @return 子串的位置 不存在返回0
 */
int Index(const HString *T, const HString *S) {
    int n = StrLength(*T);
    int m = StrLength(*S);
    HString sub;
    for (int i = 1; i <= n - m + 1; i++) {
        SubString(&sub, *T, i, m);
        if (StrCompare(sub, *S) == 0) {
            return i;
        }
    }
    return 0;
}

/**
 * 清空字符串函数
 * @param S 串
 */
void ClearString(HString *S) {
    S->length = 0;
    S->ch[1] = '\0';
}

/**
 * 销毁字符串函数
 * @param S 串
 */
void DestroyString(HString *S) {
    ClearString(S);
}

/**
 * 打印串
 * @param T 串
 */
void PrintString(HString T) {
    for (int i = 1; i <= T.length; i++) {
        putchar(T.ch[i]);
    }
    printf("\n");
}
