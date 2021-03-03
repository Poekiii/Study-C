#include <stdio.h>
int main()
{
    //数组名就是首元素的地址
    // 1. sizeof(数组名) - 数组名表示整个数组
    // 2. &数组名 - 数组名表示整个数组

    //一维数组
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));//16 - 计算整个数组的总大小 - 4*4=16字节
    printf("%d\n",sizeof(a+0));//4/8 - 首元素地址+0,还是首元素地址,地址的大小一直都是4/8 
    printf("%d\n",sizeof(*a));//4 - 对首元素地址解引用,*a就是首元素,则首元素的大小是 int类型的大小为 4
    printf("%d\n",sizeof(a+1));//4/8 - 与前面类似 还是地址，但a+1是第二个元素的地址
    printf("%d\n",sizeof(a[1]));//4 - 第二个元素的大小
    printf("%d\n",sizeof(&a));//4/8 - &a是数组的地址 还是地址
    printf("%d\n",sizeof(*&a));//16 - &a是数组的地址 再解引用访问的地址 sizeof 计算的是数组大小 可看作*&抵消
    printf("%d\n",sizeof(&a+1));//4/8 - &a是数组地址 &a+1跳过整个数组 但还是地址
    printf("%d\n",sizeof(&a[0]));//4/8 - 首元素地址
    printf("%d\n",sizeof(&a[0]+1));//4/8 - 首元素地址+1 为第二个元素地址

    //验证&a+1
    int i; 
    int s; //函数内部的变量 储存在栈区 
    int *p = (int *)(&a+1);  //&a+1 指跨越a整个数组地址最后+int类型个字节的地址
    printf(" a = %p\n&a = %p\n", a, &a);  
    for(i = 0; i < 4; i++)  
        printf("a[%d] = %p\n", i, &a[i]);  
    printf(" p = %p\n&p = %p\n&s = %p\n", p, &p, &s);  //p指针是指向了a[3]后的那个地址，而p本身的地址是在栈中分配的

    //字符数组
    char arr[] = {'a','b','c','d','e','f'};
    printf("%d\n", strlen(arr)); //随机值 - strlen是要找'/0'
    printf("%d\n", strlen(arr+0));//随机值 - arr是整个数组的首地址 arr+0是首元素地址 两个地址相同
    //printf("%d\n", strlen(*arr));//非法访问err - 'a'-ASCII码97 把97当成地址传过去 非法访问了 程序会崩溃
    //printf("%d\n", strlen(arr[1]));//err
    printf("%d\n", strlen(&arr));//随机值 - 和前面一样
    printf("%d\n", strlen(&arr + 1));//随机值 - 和前面差6
    printf("%d\n", strlen(&arr[0]+1));//随机值 - 和前面差1

    return 0;
}

