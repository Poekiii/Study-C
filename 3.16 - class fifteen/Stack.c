#include "Stack.h"

//初始化栈
void StackInit(Stack *ps)
{
    ps->data = (StackDataType *)malloc(sizeof(StackDataType)*DEFAULT_SIZE);
    if(ps->data == NULL)
    {
        printf("申请内存不到!\n");
        exit(-1); //申请不到就退出
    }
    ps->top = 0;
    ps->Capacity = DEFAULT_SIZE;
}
//检查是否满容量
void Check_Cap(Stack *ps)
{
    assert(ps);
    //如果满了就需要扩容
    if (ps->top >= ps->Capacity)
    {

        StackDataType *tmp = (StackDataType *)realloc(ps->data, sizeof(StackDataType) * (ps->Capacity + DEFAULT_INC));
        if (tmp == NULL)
        {
            printf("扩容失败!\n");
            exit(-1);
        }
        else
        {
            ps->data = tmp;
            ps->Capacity += DEFAULT_INC;
            printf("增容成功~\n");
        }
    }
}
//入栈
void StackPush(Stack *ps, StackDataType x)
{
    assert(ps);
    Check_Cap(ps);
    ps->data[ps->top] = x;
    ps->top++;
}
//检查是否栈空
int StackEmpty(Stack *ps)
{
    assert(ps);
    return ps->top == 0 ? 1 : 0;
}
//出栈
void StackPop(Stack *ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}
//打印栈内元素
void StackShow(Stack *ps)
{
    assert(ps);
    for (int i = 0; i < ps->top; i++)
    {
        printf("%d ", ps->data[i]);
    }
    printf("\n");
}
//释放申请的内存
void StackFree(Stack *ps)
{
    free(ps->data);
    ps->data = NULL;
    ps->top = 0;
    ps->Capacity = 0;
}
//查找元素
int StackFind(Stack *ps,StackDataType x)
{
        assert(ps);
    int i = 0;
    while(i < ps->top)
    {
        if (ps->data[i] == x)
        {
            return i+1;
        }
        ++i;
    }
    return -1; //找不到
}