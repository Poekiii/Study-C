#include "Seqlink.h"

//测试头尾插入删除
void TestSL1()
{
    SL s;
    SLInit(&s);
    SLPushBack(&s, 1);
    SLPushBack(&s, 2);
    SLPushBack(&s, 3);
    SLPopBack(&s);
    SLPushFront(&s, -1);
    SLPushFront(&s, -2);
    SLPushBack(&s, 4);
    SLPopFront(&s);
    SLInsert(&s, 2, 0); //这里的位置是从1开始计
    SLErase(&s, 2);
    SLShow(&s);

    int a = SLFind(&s, 4);
    printf("位置在:%d\n", a);

    SLFree(&s);
}

int main()
{
    TestSL1();
    return 0;
}