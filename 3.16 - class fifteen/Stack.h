#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//预加载: 缓存在访问内存的一个数据时 不会只加载一个数据到缓存 而是加载一段数据到缓存

//栈其实是类似于顺序表的(只是不能头插和头删除) -- 所以在顺序表的基础上改就行
typedef int StackDataType;  //栈储存的类型
#define DEFAULT_SIZE 4     //栈默认初始存储4个元素
#define DEFAULT_INC 2  //默认一次增加2个位置

//vector - C++ 中的定义动态顺序表
typedef struct Stack
{
    StackDataType *data;
    size_t top;    //栈顶;     size_t 可以简单理解为 unsigned int
    size_t Capacity;//可存的最大元素cap
}Stack;
 

//初始化栈
void StackInit(Stack *ps);
//打印栈内元素
void StackShow(Stack *ps);
//入栈
void StackPush(Stack *ps, StackDataType x);
//出栈
void StackPop(Stack *ps);
//释放申请的内存
void StackFree(Stack *ps);
//查找元素
int StackFind(Stack *ps,StackDataType x);

#endif