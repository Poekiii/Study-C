#include "DoubledList.h"

//创建一个新节点
DLNode* DLNodeCreat(DListDataType x)
{
    DLNode *NewNode = (DLNode *)malloc(sizeof(DLNode));
    if(NewNode == NULL)
    {
        printf("申请结点失败\n");
        exit(-1);
    }
    NewNode->prev = NULL;
    NewNode->data = x;
    NewNode->next = NULL;
    return NewNode;
}

//链表初始化 - 方法 1
void DLInit1(DLNode **pphead)
{
    *pphead = DLNodeCreat(0);
    (*pphead)->next = *pphead;//'*'的优先级和'->'相同
    (*pphead)->prev = *pphead;
}
//链表初始化 - 方法 2
DLNode * DLInit2()
{
    DLNode *phead = DLNodeCreat(0);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}
//查找x
DLNode *DLFind(DLNode *phead, DListDataType x)
{
    assert(phead);
    DLNode *cur = phead->next;
    while(cur != phead) //遍历链表
    {
        if(cur->data == x)
            return cur; //找到了就返回该结点的地址
        cur = cur->next;
    }
    return NULL;//找不到就返回空
}
//链表在末尾加元素
void DLPushBack(DLNode *phead, DListDataType x)
{
    assert(phead);
    DLNode *tail = phead->prev;
    DLNode *NewNode =DLNodeCreat(x);
    //newnode链接tail和phead
    //此时找尾的时间是O(1)了
    tail->next = NewNode;
    NewNode->prev = tail;

    phead->prev = NewNode;
    NewNode->next = phead;
}
//链表删除末尾元素
void DLPopBack(DLNode *phead)
{
    assert(phead);
    //assert(phead->next != phead);//链表只有头的时候就断了
    if(phead->next == phead)
        return;
    DLNode *tail = phead->prev;
    DLNode *tailPrev = tail->prev;
    tailPrev->next = phead;
    phead->prev = tailPrev;
    free(tail);
    tail = NULL;//tail是局部变量 指不指都可以 因为过了这个函数的生命周期 tail就销毁了
}
//链表在首部添加元素 - 是在head(带头)后面加一个节点
void DLPushFront(DLNode *phead, DListDataType x)
{
    assert(phead);
    DLNode *first = phead->next;
    DLNode *NewNode = DLNodeCreat(x);
    first->prev = NewNode;
    NewNode->next = first;
    NewNode->prev = phead;
    phead->next = NewNode;
}
//删除最前面的元素
void DLPopFront(DLNode *phead)
{
    assert(phead);
    if(phead->next == phead)
        return;
    DLNode *first = phead->next;
    DLNode *firstTail = first->next;
    firstTail->prev = phead;
    phead->next = firstTail;
    free(first);
    first = NULL;
}
//在对应数据前面插入x
void DLInsert(DLNode *pos, DListDataType x)
{
    assert(pos);
    DLNode *posPrev = pos->prev;
    DLNode *NewNode = DLNodeCreat(x);

    //重新链接
    posPrev->next = NewNode;
    NewNode->prev = posPrev;
    NewNode->next = pos;
    pos->prev = NewNode;
}
//在删除对应位置的结点
void DLErase(DLNode *pos)
{
    assert(pos);

    DLNode *posPrev = pos->prev;
    DLNode *posNext = pos->next;
    free(pos);
    posPrev->next = posNext;
    posNext->prev = posPrev;
}
//打印链表
void DLPrint(DLNode *phead)
{
    assert(phead);
    DLNode *cur = phead->next;
    while(cur != phead)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
//清空链表
void DLClear(DLNode *phead)
{
    assert(phead);
    DLNode *cur = phead;
    //清理所有数据结点 保留头节点 下次可以继续使用
    while(cur != phead)
    {
        DLNode *next = cur->next;
        free(cur);
        cur = next;
    }
    //继续保持头节点的特性
    phead->next = phead;
    phead->prev = phead;
}
//摧毁链表
void DLDestory(DLNode *phead)
{
    assert(phead);

    //销毁掉了
    DLClear(phead);
    free(phead);
    phead = NULL; //此时的指针指向NULL 是不会更改外面的指针的
}