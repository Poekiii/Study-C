
#include <stdio.h>
#include <assert.h>
#include <string.h>

// 3.memcmp (内存比较)
// strcmp只能比较char型
// int memcmp ( const void * ptr1, const void * ptr2, size_t num );
// int main()
// {
//     //arr1 : 01 00 00 00 02 00 00 00 03 00 00 00 04 00...
//     //arr2 : 01 00 00 00 02 00 00 00 05 00 00 00 04 00...
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {1, 2, 5, 4, 3};
//     int ret = memcmp(arr1, arr2, 9);//由于小端存储 所以比较9个字节时候 arr2大于arr1
//     printf("%d\n", ret);
//     return 0;
// }

// 4.memset (内存设置)
// void *memset(void *str, int c, size_t n) 
// 复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
// int main()
// {
//     int arr[10] = {0};
//     //40字节
//     //01 01 01 01 ....... 改10字节

//     memset(arr, 1, 10);
//     printf("%d\n", arr[0]);
//     return 0;
// }

/*-------------------自定义类型-结构体(进阶) 枚举 联合体----------------------*/
//C语言内置的数据类型：int 4 char 1 short 2 long 4/8 float 4 double 8 地址4/8
//自定义的数据类型: 结构体 枚举 联合体

//1.结构体定义
// struct tag(结构体标签)
// {
//      member-list(成员列表);
// }variable-list(变量列表);

//声明结构体类型
//struct - 结构体关键字
//stu - 结构体标签
//struct stu - 结构体类型
//s - 结构体变量
//声明一个结构体类型(不占内存) 整个类似int

//特殊声明
//匿名结构体类型
// struct
// {
//     int a;
//     char b;
//     float c;
// }x; //匿名结构体变量

// struct
// {
//     int a;
//     char b;
//     float c;
// }a[20], *p;//匿名结构体数组以及指针

// 上面的两个结构在声明的时候省略掉了结构体标签（tag）。
// 那么问题来了？
// 在上面代码的基础上，下面的代码合法吗？
//  p = &x;
// 警告： 编译器会把上面的两个声明当成完全不同的两个类型。 所以是非法的。

// 2.结构体的自引用
// 数据结构：数据在内存中存储的结构；
// 链表：数据存储可以不连续 只要能找到下一个元素就行
// 在结构中包含一个类型为该结构本身的成员是否可以呢？

// 错误定义
// struct Node
// {
//  int data;
//  struct Node next; //sizeof (struct Node) 理论上无限大了
// };

// 正确定义
// struct Node
// {
//  int data; //数据域 4字节
//  struct Node* next;//指针域 4/8字节
// };

// 3.结构体的初始化
// 前面学了 此处省略

// 4. 结构体内存对齐 (计算结构体大小)

// 首先得掌握结构体的对齐规则：
// 1. 第一个成员在与结构体变量偏移量为0的地址处。
// 2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
// 对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
// VS中默认的值为8
// Linux中的默认值为4
// 3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
// 4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所
// 有最大对齐数（含嵌套结构体的对齐数）的整数倍。

// //练习1
// struct S1  //此大小为12字节
// {
//     char c1;//放在首位置 char放一个字节 0
//     int i;//4与8(vs的默认值)比较 取小即4 所以int从4开始放
//     char c2;//1与8 取1 从 4+4 开始放 则放一个字节 所以目前1+3+4+1 = 9字节
//     //又因为结构体的总大小为最大对齐数的整数倍 最大对齐数取4  目前是9  最小是结构体大小就是12
//     //存放模式 |c1|00|00|00|i|i|i|i|c2|00|00|00|  字母对应变量的存储 00 表示作废的 不存储数据
// };
// //练习2
// struct S2 //8字节
// {
//     char c1;//1/8 取1 放首位 char 放1个
//     char c2;//1/8 取1 在c1后放1个(无浪费)
//     int i;//4/8 取4 c1+2(浪费两个字节空间) 后放 则最终得1+1+2+4 = 8字节
//     //8 是 最大字节数 4 的整数倍 所以最终是8
// };
// //练习3
// struct S3 //16
// {
//     double d;//8/8 取8 8
//     char c;//1/8 取1 9
//     int i;//4/8 取4 12+4
//     //16 是 8 的整数倍 则最终是16
// };
// //练习4-结构体嵌套问题
// struct S4 //32
// {
//     char c1;//1/8 取1
//     struct S3 s3;//嵌套的结构体对齐到自己的最大对齐数的整数倍处 (首元素也算) 取8 8+16=24
//     double d;//8/8 取8 24+8=32
//     //32%8==0
// };
// int main()
// {
//     printf("%d\n", sizeof(struct S1));
//     printf("%d\n", sizeof(struct S2));
//     printf("%d\n", sizeof(struct S3));
//     printf("%d\n", sizeof(struct S4));
//     return 0;
// }

// 为什么存在内存对齐?
// 大部分的参考资料都是如是说的：
// 1. 平台原因(移植原因)： 不是所有的硬件平台都能访问任意地址上的任意数据的；
// 某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。
// 2. 性能原因： 数据结构(尤其是栈)应该尽可能地在自然边界上对齐。 原因在于，为了访问未对齐的内存，处理器
// 需要作两次内存访问；而对齐的内存访问仅需要一次访问。
// 总体来说：
// 结构体的内存对齐是拿空间来换取时间的做法。

// 32位机器：32根地址线 32根数据线 也就是4字节
// 例如 存的 char c1 + int a; 
// 若存的未对齐 |c1|a|a|a|a| 一次取 c1 a a a 第二次取 a... 那么读取a需要读取两次
// 若存在对齐 |c1|00|00|00|a|a|a|a| 一次就能取出a

// 那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到：
// 让占用空间小的成员尽量集中在一起。

// 5.修改默认对齐数
// #pragma pack(n) //默认对齐数修改成了n
// #pragma pack() //还原默认

// size_t offsetof(struct类型名,成员) //返回地址偏移量 要#include <stddef.h> 并且他是宏 所以可以传类型的

// 6.位段 (为了节省部分空间)
// 位段的声明和结构是类似的，有两个不同：
// 1.位段的成员必须是 int、unsigned int 或signed int
// 2.位段的成员名后边有一个冒号和一个数字。

//位段 - 二进制位
//位段(bit-field)是以位为单位来定义结构体(或联合体)中的成员变量所占的空间

// 位段的内存分配
// 1. 位段的成员可以是 int,unsigned int,signed int 或者是 char （属于整形家族）类型
// 2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
// 3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。

// 开辟一次空间都是开辟 4字节=32bit 然后依次分配
// 当剩余的空间不够放下一个成员时 会舍弃掉原来的那部分 再开辟新的空间(4字节) 来存放
// struct A
// {
//     int _a:2; //占2bit 能表示4种状态 00 01 10 11
//     int _b:5; //占5bit位
//     int _c:10; //10bit  32 - 17 = 15 < 30 
//     int _d:30; //30bit 剩余的不够了 则开辟新的4字节空间 存30
//     // 8字节 
//     //单个位段的值最高就是32bit
// };

// //一个例子
// struct S
// {
//     char a:3;//开辟1字节 放3b 剩余5b
//     char b:4;//放4b 剩余1b
//     char c:5;//继续开辟1字节 放5b 剩3b
//     char d:4;//继续开辟1字节 放4b
// };
// //但是存储时总是先从低位存储即 从右往左
// //即 |0bbbbaaa|000ccccc|0000dddd|
// //   地址从 低——>高
// int main()
// {
//     struct S s = {0};
//     s.a = 10;//二进制1010 8+2
//     s.b = 20;//二进制10100 16+4
//     s.c = 3;//二进制11
//     s.d = 4;//二进制0100
//     //由于存的a的bit大于分配的bit 所以只能从低位开始截取 其他同理
//     //最终 |0 0100 010|000 00011|0000 0100|
//     //地址 低--->高  0x 22 03 04
//     printf("%d\n", sizeof(struct A));
//     printf("%hx\n", s.a);
//     return 0;
// }

// 位段的跨平台问题
// 1. int 位段被当成有符号数还是无符号数是不确定的。
// 2. 位段中最大位的数目不能确定。（16位机器最大16，32位机器最大32，写成27，在16位机器会出问题。
// 3. 位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义。
// 4. 当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是舍弃剩余的位
// 还是利用，这是不确定的。
// 总结：
// 跟结构相比，位段可以达到同样的效果，但是可以很好的节省空间，但是有跨平台的问题存在

// 二、枚举
// 1.枚举的定义
// enum Day //星期
// {
//     Mon = 2,
//     Tues, //默认值+1 等于3
//     Wed,
//     Thur,
//     Fri,
//     Sat,
//     Sun
// };
// // 以上定义的 enum Day是枚举类型。 {}中的内容是枚举类型的可能取值，也叫 枚举常量 。
// // 这些可能取值都是有值的，默认从0开始，一次递增1，当然在定义的时候也可以赋初值

// //#define Mon 0 //这里虽然可以和枚举完成一样的最终结果 但是此处的Mon是无类型的 枚举是有类型的
// // C语言源代码 -- 预编译(define的替代是在这里的完成的) -->编译 -- 链接 ——> 可执行程序

// int main()
// {
//     enum Day d = Mon; //赋值错误!但是不报错; 因为d是enum Day类型 但是2是int型
//     printf("%d %d %d\n", Mon, Tues, d);
//     return 0;
// }

// 枚举的优点
// 为什么使用枚举？
// 我们可以使用 #define 定义常量，为什么非要使用枚举？ 枚举的优点：
// 1. 增加代码的可读性和可维护性
// 2. 和#define定义的标识符比较枚举有类型检查，更加严谨。
// 3. 防止了命名污染（封装） 也就是命名冲突
// 4. 便于调试
// 5. 使用方便，一次可以定义多个常量

// 三、联合体 - 联合 - 共用体
// 联合也是一种特殊的自定义类型 这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合也叫共用体）
// 特点:联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小（因为联合至少得有能力保存最大的那个成员）。

// 联合大小的计算
// 联合的大小至少是最大成员的大小。
// 当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍

// 联合类型的声明
// union Un 
// { 
//     char c; //1/8 1
//     int i;  //4/8 4
// }; 

// //检测大小端的另外方法
// int check_sys2(void)
// {
//     union  //此处可以使用匿名声明 因为只使用一次
//     { 
//         char c; //1/8 1
//         int i;  //4/8 4
//     }u; 
//     u.i = 1;//因为共用内存 小端时候存01 00 00 00 大端存 00 00 00 01
//     //所以读取(char)1字节时候 读到1就是小端 0就是大端 
//     return u.c;
// }

// //原方法
// int check_sys1(void)
// {
//     int a = 1;
//     return *(char *)&a;
// }

// int main()
// {
//     //联合变量的定义
//     union Un un; 
//     //计算连个变量的大小
//     printf("%d\n", sizeof(un));
//     printf("%p\n", &un);
//     printf("%p\n", &un.c);
//     printf("%p\n", &un.i);
//     //int ret = check_sys1();
//     int ret = check_sys2();
//     if (ret == 1)
//     {
//         printf("小端!\n");
//     }
//     else
//     {
//         printf("大端!\n");
//     }
//     //低地址 ---------> 高地址
//     //...[][11][22][33][]... 大端存储
//     //...[][33][22][11][]... 小端存储
//     return 0;
// }
