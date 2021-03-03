#include <stdio.h>
int main()
{
    //字符数组
    char arr[] = "abcdef";
    printf("%d\n", sizeof(arr));//7 sizeof(arr)计算的数是整个数组的大小，单位是字节 数组存放的实际是 a b c d e f /0
    printf("%d\n", sizeof(arr+0));//4/8 arr+0是首元素地址
    printf("%d\n", sizeof(*arr));//1 *arr是首元素 计算首元素大小 就是1字节 
    printf("%d\n", sizeof(arr[1]));//1 第二个元素
    printf("%d\n", sizeof(&arr));//4/8 &arr是取的数组的地址 本质是地址
    printf("%d\n", sizeof(&arr+1));//4/8 &arr+1是跳过整个数组后的地址
    printf("%d\n", sizeof(&arr[0] + 1));//4/8 &arr[0]+1是第二个元素的地址

    printf("%d\n", strlen(arr));//6 遇到/0后统计 不包括/0
    printf("%d\n", strlen(arr+0));//6 上同
//  printf("%d\n", strlen(*arr));//非法访问err 下同
//  printf("%d\n", strlen(arr[1]));//非法访问err strlen取的是地址 arr[1]是‘b’-98 当成地址 再去访问时候就非法了
    printf("%d\n", strlen(&arr)); //6 有警告 &arr-数组的地址-数组指针 是char(*)[7] 类型, 但是strlen取的是const char* 类型   
    printf("%d\n", strlen(&arr+1));//随机 有警告 arr数组后的地址
    printf("%d\n", strlen(&arr[0] + 1));//5 第二个元素的地址
    return 0;
}
