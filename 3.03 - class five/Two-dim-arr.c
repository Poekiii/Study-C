#include <stdio.h>

int main()
{
    //1. sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
    //2. &数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
    //3. 除此之外所有的数组名都表示首元素的地址。

    //二维数组
    int a[3][4] = {0}; //3行4列的一个数组
    printf("%d\n", sizeof(a)); //3*4*4=48
    printf("%d\n",sizeof(a[0][0]));//4 - 第一行第一列的元素
    printf("%d\n",sizeof(a[0]));//16 - a[i] 可以看作第i行作为一维数组名 a[3][4]可以看作有3个元素组 每个元素组又算一个一维数组 可以叫a[]
    printf("%d\n",sizeof(a[0]+1));//4/8 - a[0]是第一行的数组名 此数组名为表示第一行第一列的地址 a[0]+1为第一行第二列元素的地址
    printf("%d\n",sizeof(*(a[0]+1)));//4 - 是第一行第二列的元素
    printf("%d\n",sizeof(a+1));//4/8 - a表示首行的地址 a+1表示第二行的地址 没有sizeof(数组名) 也没有&(数组名)
    //而二维数组看成一维数组时候, 二维数组的首元素就是他的第一行 a就是第一行的地址

    printf("%d\n",sizeof(*(a+1)));//16 - *(a+1)相当于a[1] 第二行
    printf("%d\n",sizeof(&a[0]+1));//4/8 - &a[0]是取第一行的地址 &a[0]+1 第二行的地址 相当于a+1 
    printf("%d\n",sizeof(*(&a[0]+1)));//16 - 相当于第二行
    printf("%d\n",sizeof(*a));//16 - a是二维数组的首元素地址 *a就是第一行
    printf("%d\n",sizeof(a[3]));//16 - sizeof的内部是不关注真实运算的 只是根据类型来计算大小 即使a[3]是不存在的
    return 0;
}