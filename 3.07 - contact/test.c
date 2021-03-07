#include "contact.h"

//1.存放1000人的信息
//2.增加
//3.删除
//4.查找
//5.修改
//6.打印
//7.排序

void menu()
{
    printf("***********************************\n");
    printf("**** 1.add              2.del *****\n");
    printf("**** 3.search           4.modify **\n");
    printf("**** 5.show             6.sort ****\n");
    printf("**** 0.exit                    ****\n");
    printf("***********************************\n");
}

int main()
{
    int input = 0;
    //创建通讯录
    struct Contact con;
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case add:
            AddContact(&con);
            break;
        case del:
            DelContact(&con);
            break;
        case search:
            SearchContact(&con);
            break;
        case modify:
            ModifyContact(&con);
            break;
        case show:
            ShowContact(&con);
            break;
        case sort:
            SortContact(&con);
            break;
        case exit_c:
            printf("退出通讯录~\n");
            break;
        default:
            printf("选择错误!\n");
            break;
        }
    } while (input);
    return 0;
}