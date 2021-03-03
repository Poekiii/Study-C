#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
    char name[10];
    int age;
    /* data */
};

int cmp_int(const void* e1, const void* e2)  //void类型的指针能够接收任意类型的指针
{
    return *(int *)e1 - *(int *)e2; //这里是要把e1的指针类型强制转化为我们所需要的int类型指针
}

int cmp_struct_by_age(const void* e1, const void* e2)
{
    return ((struct stu *)e1)->age - ((struct stu *)e2)->age;
}

int cmp_struct_by_name(const void* e1, const void* e2)
{
    return strcmp(((struct stu *)e1)->name, ((struct stu *)e2)->name); //strcmp比较的是两个字符的大小 依次比较 但是注意不是长度
}

int main()
{
    struct stu s[3]= {{"aaa", 10}, {"aecc", 30}, {"adbb", 20}};
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int sz2 = sizeof(s) / sizeof(s[0]);

    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    //qsort包含在stdlib.h的头文件中
    //qsort(void * base 要比较的, size length 长,size width 宽, int (* cmp)(...) 比较函数 返回>0 =0 <0)
    //1.待排序数组的首地址; 2.元素个数; 3.每个元素的大小-单位字节; 4.函数指针，待比较的两个元素的地址
    qsort(s, sz2, sizeof(s[0]), cmp_struct_by_age);
    //比结构体中的int的年龄
    qsort(s, sz2, sizeof(s[0]), cmp_struct_by_name);
    //比结构体中的char的名字

    for (int i = 0; i < sz2; i++ )
    {
        printf("%s ", s[i].name);
    }
}