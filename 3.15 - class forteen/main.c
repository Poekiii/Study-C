#include "DoubledList.h"

void TestList1()
{
    DLNode *phead = DLInit2();
    //DLInit1(&phead);
    //1.测试双向链表的头尾增删
    DLPushBack(phead, 1);
    DLPushBack(phead, 2);
    DLPushBack(phead, 3);
    DLPushBack(phead, 4);
    DLPopFront(phead);
    DLPopBack(phead);
    DLPrint(phead);
    //2.测试双向链表的查插删
    DLNode *pos = DLFind(phead, 3);
    DLInsert(pos, 30);
    DLInsert(phead->next, 1);//等效头插
    DLInsert(phead, 2);//等效尾插 因为我们设置的插入是当前位置的前面插入
    DLPrint(phead);
    DLErase(phead->prev);//头删除
    DLErase(phead->next);//尾删除
    DLErase(pos);
    DLPrint(phead);
    //3.毁掉链表
    DLDestory(phead);
}

int main()
{
    TestList1();
    return 0;
}