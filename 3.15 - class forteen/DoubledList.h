#ifndef _DOUBLEDLIST_H_
#define _DOUBLEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int DListDataType;

// 双向链表节点的结构体定义  
typedef struct DoubledListNode
{
    struct DoubledListNode * prev;
    DListDataType data;
    struct DoubledListNode * next;
}DLNode;
// 特点: 结构复杂 但是操作简单

// 例如尾插
// head的prev就找到尾了
// 一个节点都没有时 
// head的next和prev都是自己

//链表和顺序表(数组)的区别和联系：
// 顺序表就是在数组的基础上实现增删查改，并且插入时可以动态增长；
// 缺陷：
// a.可能存在一定的空间浪费(每次会多申请内存)
// b.增容有一些效率损失(开新空间 copy数据 才释放内存)
// c.中间或者头部插入删除，时间复杂度为O(N),因为要挪动数据

// 这些问题链表都解决了.
// 链表的缺陷:不能随机访问 (比如要直接找到第5位置)

//链表初始化 - 方法 1
void DLInit1(DLNode **pphead);
//链表初始化 - 方法 2
DLNode* DLInit2();

//链表在末尾加元素
void DLPushBack(DLNode *phead, DListDataType x);
//链表删除末尾元素
void DLPopBack(DLNode *phead);
//链表在首部添加元素
void DLPushFront(DLNode *phead, DListDataType x);
//删除最前面的元素
void DLPopFront(DLNode *phead);
//查找x
DLNode *DLFind(DLNode *phead, DListDataType x);
//在对应位置前面插入x
void DLInsert(DLNode *pos, DListDataType x);
//在删除对应位置的结点
void DLErase(DLNode *pos);
//打印链表
void DLPrint(DLNode *phead);
//清空链表
void DLClear(DLNode *phead);
//摧毁链表
void DLDestory(DLNode *phead);

#endif