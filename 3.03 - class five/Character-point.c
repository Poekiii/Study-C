#include <stdio.h>

int main()
{
    //指针变量p存放的是 字符的数组 的首元素地址
    //*p 是第一字符
    char *p = "abcdef";
    printf("%d\n", sizeof(p));//4/8 - 计算指针变量p的大小 p存的是地址
    printf("%d\n", sizeof(p+1));//4/8 - p+1 是第二个字符b的地址 
    printf("%d\n", sizeof(*p));//1 - *p就是字符串首元素a
    printf("%d\n", sizeof(p[0])); //1 - int arr[10];  arr[0] == *(arr+0);  p[0] == *(p+0) arr本质算地址 p和arr一定程度等价
    printf("%d\n", sizeof(&p));//4/8 取指针p的地址 
    printf("%d\n", sizeof(&p+1));//4/8 跳过p指针后的地址
    printf("%d\n", sizeof(&p[0]+1));//4/8 是字符b的地址

    printf("%d\n", strlen(p));//6 p-首元素a的地址传过去 找/0 或者十六进制的00 也就是地址中的 
    printf("%d\n", strlen(p+1));//5 p+1- b的地址
//  printf("%d\n", strlen(*p));//非法访问err -是字符a
//  printf("%d\n", strlen(p[0]));//err
    printf("%d\n", strlen(&p));//随机
    printf("%d\n", strlen(&p+1));//随机
    printf("%d\n", strlen(&p[0]+1));//5 &p[0]+1 - b地址
    return 0;
}