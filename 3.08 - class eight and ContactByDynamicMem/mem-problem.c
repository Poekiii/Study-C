#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 经典题1
// 请问运行Test函数会有什么样的结果
// void GetMemory(char *p)
// {
//     p = (char *)malloc(100);//问题2 在堆区开辟了空间 但是没有释放
// }
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(str);//问题1 传入的其实只是值 p只是str值的临时赋值 此函数结束生命周期时 p被销毁了 并且申请的内存已经不能找到了
//     strcpy(str, "hello world");//问题3 strcpy访问了NULL指针 然后非法访问 此时程序崩溃
//     printf(str);
// }
// int main()
// {
//     Test();
//     return 0;
// }
//结果：
//1. 运行代码 程序会崩溃
//2. 程序存在内存泄漏问题
// str以值的形式传给p p是getmemory的形参 只在函数内部有效
// 等getmemory函数返回后 动态开辟的内存未释放 并且无法找到

// 修改程序至能运行
// void GetMemory(char * *p) //创建一个*p的指针来存放 char *的数据
// {
//     *p = (char *)malloc(100);//此时的*p就代表外面的*str了
// }
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(&str);//传入str地址
//     strcpy(str, "hello world");//问题3 strcpy访问了NULL指针 然后非法访问 此时程序崩溃
//     printf(str);

//     //释放内存
//     free(str);
//     str = NULL;
// }
// int main()
// {
//     Test();
//     return 0;
// }

// 题目2
// void Test(void)
// {
//     char *str = (char *) malloc(100);
//     strcpy(str, "hello");
//     free(str); //虽然释放了内存 但是str依然指向原来申请的地址
//     //free 不会把str置为NULL
//     if(str != NULL)
//     {
//         strcpy(str, "world");//所以这里是使用了已经释放的内存 属于非法访问
//         printf(str);
//     }
// }

/*-------------------柔性数组----------------------*/