#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Default_SZ 3  // 通讯录的默认起始容量
#define Default_INC 2 //默认一次增加的容量
#define MAX_NAME 15
#define MAX_SEX 6
#define MAX_TELE 12
#define MAX_ADDR 20

// 名字 电话 性别 住址 年龄
struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

struct Contact
{
    struct PeoInfo *data; //把数组改成指针 那就是地址了 可以利用动态内存分配了
    int size;//记录当前已有的元素
    int capacity;//记录当前通讯录的最大容量
};

enum contact_option
{
    exit_c = 0,//退出
    add, //增加
    del, //删除
    search, //查找
    modify, //修改
    show, //展示
    sort //排序
};
//初始化
void InitContact(struct Contact *ps);
//增加联系人
void AddContact(struct Contact *ps);
//删除指定联系人的信息
void DelContact(struct Contact *ps);
//打印通讯录中的信息
void ShowContact(const struct Contact *ps); //因为只是读 并不写 所以用const
//查找指定的联系人的信息
void SearchContact(const struct Contact *ps);
//修改指定的联系人的信息
void ModifyContact(struct Contact *ps);
//对通讯录的信息根据名字进行排序
void SortContact(struct Contact *ps);
//释放通讯录使用的内存
void FreeContact(struct Contact *ps);

#endif
