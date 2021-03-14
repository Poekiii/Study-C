#include "LinkedList.h"

LLNode* LLNodeCreat(LListDataType x)
{
    LLNode *NewNode = (LLNode *)malloc(sizeof(LLNode));
    if(NewNode == NULL)
    {
        printf("申请结点失败\n");
        exit(-1);
    }
    NewNode->data = x;
    NewNode->next = NULL;
    return NewNode;
}

void LLPushBack(LLNode **pphead, LListDataType x)
{
    LLNode *NewNode = LLNodeCreat(x);
    if(*pphead == NULL)  //起始时链表为空，那么直接把新的node给它就行
    {
        *pphead = NewNode;
    } 
    else
    {
        //找尾巴 类似于链表打印 (但是tail找的是tail的下一个位置,也就是tail的循环到的是NULL之前的位置,再把下一个位置的地址链接上去)
        LLNode *tail = *pphead; //当前位置
        while(tail->next != NULL) //当tail当前位置的下一个节点指向NULL时 说明已经遍历完成了 因为最后一个节点指向的下一个元素地址是NULL
        {
            tail = tail->next;
        }
        tail->next = NewNode;
    }
}

void LLPopBack(LLNode **pphead)
{
    //1.链表为空
    if (*pphead == NULL)
    {
        return;
    }
    //2.链表仅有1个元素
    else if ((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    //3.一个以上
    else
    {
        LLNode *prev = NULL;
        LLNode *tail = *pphead;
        while(tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;
    }
}

void LLPushFront(LLNode **pphead, LListDataType x)
{
    LLNode *NewNode = LLNodeCreat(x);
    NewNode->next = *pphead;//这里是把下一个地址改成原理的首地址
    *pphead = NewNode;//这里是把原来首地址的指向改掉 若是不改这里 那么其他函数依然会从原理的首地址开始的
}

void LLPopFront(LLNode **pphead)
{
    if (*pphead == NULL)
    {
        return;
    } 
    else
    {
        LLNode *Next = (*pphead)->next;
        free(*pphead);
        *pphead = Next;
    }
}

void LLPrint(LLNode *phead)
{
    LLNode *cur = phead; //当前位置
    while(cur != NULL) //当cur指向NULL时 说明已经遍历完成了 因为最后一个节点指向的下一个元素地址是NULL
    {
        printf("%d->", cur->data);
        cur = cur->next;//cur会到NULL的位置
    }
    printf("NULL\n");
}