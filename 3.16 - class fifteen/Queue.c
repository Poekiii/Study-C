#include "Queue.h"

//初始化队列
void QueueInit(Queue *qp)
{
    assert(qp);
    qp->front = NULL;
    qp->tail = NULL;
}
//创建一个新节点
QueueNode* QueueNodeCreat(QueueDataType x)
{
    QueueNode *NewNode = (QueueNode *)malloc(sizeof(QueueNode));
    if(NewNode == NULL)
    {
        printf("申请结点失败\n");
        exit(-1);
    }
    NewNode->data = x;
    NewNode->next = NULL;
    return NewNode;
}
//入队
void QueuePush(Queue *qp, QueueDataType x)
{
    assert(qp);
    QueueNode *NewNode = QueueNodeCreat(x);
    if(qp->tail == NULL)//当队空时 新加入的结点即是首也是尾巴
    {
        qp->front = NewNode; 
        qp->tail = NewNode;
    }
    else
    {
        QueueNode *prevTail = qp->tail;
        prevTail->next = NewNode; //要先链接好原来队尾和新节点
        qp->tail = NewNode;
    }
}
//检测队列是否为空
int QueueEmpty(Queue *qp)
{
    assert(qp);
    return qp->tail == NULL ? 1 : 0;
}
//出队
void QueuePop(Queue *qp)
{
    assert(qp);
    assert(!QueueEmpty(qp));
    if(qp->tail == qp->front) //只有一个结点时
    {
        free(qp->front);
        qp->front = NULL;
        qp->tail = NULL;
    }
    else
    {
        QueueNode *prevFront = qp->front;
        qp->front = prevFront->next;
        free(prevFront);
        prevFront = NULL;
    }
}
//销毁队列
void QueueDestroy(Queue *qp)
{
    assert(qp);
    QueueNode *cur = qp->front;
    while(cur)
    {
        QueueNode *next = cur->next;
        free(cur);
        cur = next;
    }
    qp->front = NULL;
    qp->tail = NULL;
}
//打印队列
void QueuePrint(Queue *qp)
{
    assert(qp);
    QueueNode *cur = qp->front;
    while(cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}