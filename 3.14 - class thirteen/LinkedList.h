#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LListDataType;

//链表节点的结构体定义  (该定义与做题的定义一致)
typedef struct LinkedListNode
{
    LListDataType data;
    struct LinkedListNode * next;
}LLNode;

// 定义2
// struct LLNode
// {
//     LListDataType data;
//     LLNode *head;
//     LLNode *tail;
// }

//链表在物理结构上存储了 1.该处数据 2.下一个节点的地址
// 地址:0x05        |       地址:0x91        |     地址:0x15        |
// |   0   |  0x91  | -->  |   1   |  0x15  | --> |   0   |  NULL  | 
//   data   next addr        data   next addr       data   next addr

//链表在末尾加元素
void LLPushBack(LLNode **pphead, LListDataType x);
//链表删除末尾元素
void LLPopBack(LLNode **phead);
//链表在首部添加元素
void LLPushFront(LLNode **pphead, LListDataType x);
//删除最前面的元素
void LLPopFront(LLNode **pphead);
//打印链表
void LLPrint(LLNode *phead);
//销毁链表
void LLDestroy(LLNode *phead);
#endif
