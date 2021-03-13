#include "Seqlink.h"

//初始化顺序表
void SLInit(struct SeqList *ps)
{
    ps->data = (SLDataType *)malloc(sizeof(SLDataType)*DEFAULT_SIZE);
    if(ps->data == NULL)
    {
        printf("申请内存不到!\n");
        exit(-1); //申请不到就退出
    }
    ps->size = 0;
    ps->Capacity = DEFAULT_SIZE;
};

//展示已存的元素
void SLShow(struct SeqList *ps)
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->data[i]);
    }
    printf("\n");
}

//检查是否满容量
void Check_Cap(struct SeqList *ps)
{
    assert(ps);
    //如果满了就需要扩容
    if (ps->size >= ps->Capacity)
    {

        SLDataType *tmp = (SLDataType *)realloc(ps->data, sizeof(SLDataType) * (ps->Capacity + DEFAULT_INC));
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

//在末尾加入元素
void SLPushBack(struct SeqList *ps, SLDataType x)
{
    assert(ps);
    Check_Cap(ps);
    //尾巴处添加数
    ps->data[ps->size] = x;
    ps->size++;
}

//弹出最后的元素
void SLPopBack(struct SeqList *ps)
{
    assert(ps);
    //直接把size调整成size-1,那么就不会再访问到最后这个数了
    //一般删除数据不用删除真实数据
    ps->size--;
}

//在首部加入元素
void SLPushFront(struct SeqList *ps, SLDataType x)
{
    assert(ps);
    Check_Cap(ps);
    //类似于memcpy - 从后往前挪
    int end = ps->size - 1;
    while (end >= 0) //想的是结束条件, 写的是继续的条件 
    {
        ps->data[end + 1] = ps->data[end];
        --end;
    }
    ps->data[0] = x;
    ps->size++;
}

//弹出最前面的元素
void SLPopFront(struct SeqList *ps)
{
    assert(ps);
    //此处是 - 从前往后挪
    int start = 0;
    while (start < ps->size -1) //想的是结束条件, 写的是继续的条件 
    {
        ps->data[start] = ps->data[start + 1];
        ++start;
    }
    ps->size--;
}

//在任意位置插入元素
void SLInsert(struct SeqList *ps, int pos, SLDataType x)
{
    assert(ps);
    assert(pos < ps->size && pos >=0); //越界就退出

    int end = ps->size - 1;
    while(end >= (pos-1))
    {
        ps->data[end + 1] = ps->data[end];
        --end;
    }
    ps->data[(pos-1)] = x;
    ps->size++;
}

//删除任意位置的元素
void SLErase(struct SeqList *ps, int pos)
{
    assert(ps);
    assert(pos < ps->size && pos >=0);
    int start = pos - 1;
    while (start < ps->size -1) //想的是结束条件, 写的是继续的条件 
    {
        ps->data[start] = ps->data[start + 1];
        ++start;
    }
    ps->size--;
}

//查找元素
int SLFind(struct SeqList *ps,SLDataType x)
{
    assert(ps);
    int i = 0;
    while(i < ps->size)
    {
        if (ps->data[i] == x)
        {
            return i+1;
        }
        ++i;
    }
    return -1; //找不到
}

//释放申请的内存
void SLFree(struct SeqList *ps)
{
    free(ps->data);
    ps->data = NULL;
    ps->size = 0;
    ps->Capacity = 0;
}
