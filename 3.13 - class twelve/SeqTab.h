#ifndef _SEQTAB_H_
#define _SEQTAB_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 顺序表, 有效数据在数组中必须是连续的
// 1. 保证数据存储的物理结构是连续的;
// 2. 保证空间足够;

// 顺序表的设计 (动态大小)
// 缺点：   1.中间或者头部的插入和删除很慢，因为需要挪动数据。时间复杂度是O(N);
//         2.空间不够时，增容会有一定消耗和空间浪费。

// 优点：   1.可以随机访问。(可以找到坐标) -- 大多数算法适用
//         2.缓存命中率比较高。   CPU(快)  三级缓存(存的稍微多 但是慢一点比寄存器)-L1 L2 L3  寄存器(存的少 但是快)  内存(更慢)
//(因为顺序表是物理空间连续,那么预加载就有优势);       速度越快，价格越贵   速度越慢，一般空间越大

//预加载: 缓存在访问内存的一个数据时 不会只加载一个数据到缓存 而是加载一段数据到缓存

typedef int SLDataType;  //顺序表储存的类型
#define DEFAULT_SIZE 4     //顺序表默认初始存储多少个元素
#define DEFAULT_INC 4  //默认一次增加4个位置

//vector - C++ 中的定义动态顺序表
typedef struct SeqList
{
    SLDataType *data;
    size_t size;    //已存的size个元素;     size_t 可以简单理解为 unsigned int
    size_t Capacity;//可存的最大元素cap
}SL;
 

//初始化顺序表
void SLInit(struct SeqList *ps);
//展示已存的元素
void SLShow(struct SeqList *ps);
//在末尾加入元素
void SLPushBack(struct SeqList *ps, SLDataType x);
//弹出最后的元素
void SLPopBack(struct SeqList *ps);
//在首部加入元素
void SLPushFront(struct SeqList *ps, SLDataType x);
//弹出最前面的元素
void SLPopFront(struct SeqList *ps);
//在任意位置插入元素
void SLInsert(struct SeqList *ps, int pos, SLDataType x);
//删除任意位置的元素
void SLErase(struct SeqList *ps, int pos);
//释放申请的内存
void SLFree(struct SeqList *ps);
//查找元素
int SLFind(struct SeqList *ps,SLDataType x);

#endif
