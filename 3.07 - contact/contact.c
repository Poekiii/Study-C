#include "contact.h"

void InitContact(struct Contact *ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;
}

void AddContact(struct Contact *ps)
{
    if(ps->size ==  MAX_CON) //当通讯录存满的时候不能再存了
    {
        printf("通讯录已满!请删除部分后再操作.\n");
    }
    else
    {
        printf("请输入姓名:>");
        scanf("%s", ps->data[ps->size].name); //由于原name是char数组 所以数组名就可以代表首地址
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[ps->size].age)); //但int 不是数组 所以得加&
        printf("请输入性别:>");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[ps->size].addr);
        ps->size++;
        printf("添加完成~\n");
    }
}

void ShowContact(const struct Contact *ps)
{
    if (ps->size ==  0)
    {
        printf("通讯录为空!\n");
    }
    else
    {
        printf("%-15s\t%-3s\t%-6s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        for (int i = 0; i < ps->size; i++)
        {
            printf("%-15s\t%-3d\t%-6s\t%-12s\t%-20s\n", 
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].addr);
        }
    }
}

//为了支撑 del 和 search 而已, 用户并不用关心 所以不用暴漏出去 以免冲突
// 在c语言中static关键字可以修饰函数和变量。修饰变量又可以分为修饰全局变量和局部变量。
// static作用是限定变量的生命周期，限定变量或函数的作用域。

// 在函数的返回类型前加上关键字static，函数就被定义成为静态函数。
// 函数的定义和声明默认情况下是extern的，但静态函数只是在声明他的文件当中可见，不能被其他文件所用。好处：
// 　　<1> 其他文件中可以定义相同名字的函数，不会发生冲突
// 　　<2> 静态函数不能被其他文件所用。 存储说明符auto，register，extern，static，对应两种存储期：自动存储期和静态存储期。 auto和register对应自动存储期。具有自动存储期的变量在进入声明该变量的程序块时被建立，它在该程序块活动时存在，退出该程序块时撤销。
//  总结：只能被本文件中的函数调用，而不能被同一程序其它文件中的函数调用。区别于一般的非静态函数（外部函数）。

static int FindByName(const struct Contact *ps, char name[MAX_NAME])
{
    int i = 0;
    for (i = 0; i < ps->size ; i++)
    {
        if(strcmp(ps->data[i].name,name) == 0)
            return i;
    }
    return -1;
}

void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>");
    scanf("%s", name);
    //因为searchContact 同样要用到 FindByName 避免冗余 就封装成函数
    int pos = FindByName(ps, name); //找到返回名字所在元素下标 找不到返回-1
    if (pos == -1)
    {
        printf("查无此人!\n");
    }
    else
    {
        int j;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功~\n");
    }
}

void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name); //找到返回名字所在元素下标 找不到返回-1
    if (pos == -1)
    {
        printf("查无此人!\n");
    }
    else
    {
        printf("%-15s\t%-3s\t%-6s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-15s\t%-3d\t%-6s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].addr);
    }
}

void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name); //找到返回名字所在元素下标 找不到返回-1
    if (pos == -1)
    {
        printf("查无此人!\n");
    }
    else
    {
        printf("%-15s\t%-3s\t%-6s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-15s\t%-3d\t%-6s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].addr);
        
        printf("请输入姓名:>");
        scanf("%s", ps->data[pos].name); //由于原name是char数组 所以数组名就可以代表首地址
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[pos].age)); //但int 不是数组 所以得加&
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[pos].addr);

        printf("修改完成~\n");
    }
}

void SortContact(struct Contact *ps)  //使用冒泡排序法
{
 	int i, j;
    struct PeoInfo tmp={0};
 	for (i = 0; i < ps->size - 1; i++) //n趟冒泡排序
 	{
  		for (j = 0; j < ps->size - 1 - i; j++)//一趟排n-i-1个
 		{
  			 if (strcmp(ps->data[j].name,ps->data[j+1].name)>0) //前面大于后面 那么就交换一下
 			 {
   			 	tmp = ps->data[j]; 
   			 	ps->data[j] = ps->data[j + 1]; 
   			 	ps->data[j + 1] = tmp;
   			 }
 		}
	}
    printf("排好了~\n");
}