#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QueueDataType;

//链式结构：表示队列
typedef struct QueueNode
{
    QueueDataType data;
    //指向下一个节点
    struct QueueNode *next;
}QueueNode;

//队列的结构
typedef struct Queue
{
    QueueNode *front; //头指针
    QueueNode *tail;  //尾指针
}Queue;

//初始化队列
void QueueInit(Queue *qp);
//入队
void QueuePush(Queue *qp, QueueDataType x);
//出队
void QueuePop(Queue *qp);
//打印队列
void QueuePrint(Queue *qp);
//销毁队列
void QueueDestroy(Queue *qp);

#endif
