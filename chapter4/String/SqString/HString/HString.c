//
// Created by li on 2024/7/19.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255

typedef struct {
    char *ch;
    int length;
} HString;

//初始化字符串
void InitString(HString *T);

//将字符数组 chars 赋值给串 T
bool StrAssign(HString *T, const char *chars);

//复制串 S 到串 T
bool StrCopy(HString *T, const HString *S);

//判断串 T 是否为空
bool StrEmpty(const HString *T);

//比较两个串
int StrCompare(const HString *T, const HString *S);

//计算串 T 的长度
int StrLength(const HString *T);

//从串 S 的第 pos 个字符起，截取长度为 len 的子串到 T
bool SubString(HString *T, const HString *S, const int pos, const int len);

//将串 S2 连接到串 S1 的末尾，结果存储在 T 中
bool Concat(HString *T, const HString *S1, const HString *S2);

//查找子串位置函数
int Index(const HString *T, const HString *S);

//清空字符串函数
void ClearString(HString *S);

//销毁字符串函数
void DestroyString(HString *S);

//打印串
void PrintString(const HString *T);

/**
 * 初始化字符串
 * @param T 需要初始化的串
 */
void InitString(HString *T) {
    T->ch = NULL;
    T->length = 0;
}

/**
 * 将字符数组 chars 赋值给串 T
 * @param T 要分配的串
 * @param chars 字符数组
 * @return true 成功 false 失败
 */
bool StrAssign(HString *T, const char *chars) {
    int len = strlen(chars);
    if (len >= MAXLEN) return false;
    // 动态分配内存，长度为字符串长度+2（为了方便逻辑位置从1开始，最后存\0）
    if (T->ch != NULL) {
        free(T->ch);
    }
    T->ch = (char *) malloc(sizeof(char) * (len + 2));
    if (!T->ch) return false;
    for (int i = 0; i < len; i++) {
        T->ch[i + 1] = chars[i];
    }
    T->ch[len + 1] = '\0';
    T->length = len;
    return true;
}

/**
 * 复制串 S 到串 T
 * @param T 复制到的串
 * @param S 源串
 * @return true 成功 false 失败
 */
bool StrCopy(HString *T, const HString *S) {
    if (T == S)return true;
    if (T->ch != NULL) {
        free(T->ch);
    }
    T->ch = (char *) malloc(sizeof(char) * (S->length + 2));
    if (!T->ch)return false;
    T->length = S->length;
    for (int i = 1; i <= S->length; i++) {
        T->ch[i] = S->ch[i];
    }
    T->ch[S->length + 1] = '\0';
    return true;
}

/**
 * 判断串 T 是否为空
 * @param T 串
 * @return true 空 false 非空
 */
bool StrEmpty(const HString *T) {
    return T->length == 0;
}

/**
 * 比较两个串
 * @param T 串
 * @param S 要比较的串
 * @return >0 S>T =0 S=T <0 S<T
 */
int StrCompare(const HString *T, const HString *S) {
    for (int i = 1; i <= T->length && i <= S->length; i++) {
        if (T->ch[i] != S->ch[i]) {
            return T->ch[i] - S->ch[i];
        }
    }
    return T->length - S->length;
}

/**
 * 计算串 T 的长度
 * @param T 串
 * @return 串长
 */
int StrLength(const HString *T) {
    return T->length;
}

/**
 * 从串 S 的第 pos 个字符起，截取长度为 len 的子串到 T
 * @param T 找到的子串
 * @param S 源子串
 * @param pos 开始位置
 * @param len 长度
 * @return true 成功 false 失败
 */
bool SubString(HString *T, const HString *S, const int pos, const int len) {
    if (pos < 1 || pos > S->length || len < 0 || pos + len - 1 > S->length)return false;
    if (T->ch != NULL) {
        free(T->ch);
    }
    T->ch = (char *) malloc(sizeof(char) * (len + 2));
    if (!T->ch)return false;
    T->length = len;
    for (int i = 1; i <= len; i++) {
        T->ch[i] = S->ch[pos + i - 1];
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
    if (len + 2 > MAXLEN)return false;
    if (T->ch != NULL) {
        free(T->ch);
    }
    T->ch = (char *) malloc(sizeof(char) * (len) + 2);
    if (!T->ch)return false;
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
    int i = 1, j = 1;
    while (i <= T->length && j <= S->length) {
        if (T->ch[i] == S->ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > S->length) return i - S->length;
    return 0;
}

/**
 * 清空字符串函数
 * @param S 串
 */
void ClearString(HString *S) {
    if (S->ch != NULL) {
        free(S->ch);
        S->ch = NULL;
    }
    S->length = 0;
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
void PrintString(const HString *T) {
    if (T == NULL || T->ch == NULL)return;
    for (int i = 1; i <= T->length; i++) {
        putchar(T->ch[i]);
    }
    printf("\n");
}
