#include <stdio.h>

//题目10
//汽水问题
//1瓶1块钱 2空瓶换1汽水 给20块 能买多少汽水
// int main()
// {
//     int money = 0;
//     int total = 0;
//     int empty = 0;//空瓶数量
//     scanf("%d", &money);

//     //1.拿钱买汽水
//     total = money;//能买m瓶
//     empty = money;//出来m空瓶

//     //2.空瓶换汽水
//     while(empty>=2)
//     {
//         total += empty / 2;
//         empty = empty / 2 + empty % 2; //空瓶等于换的汽水+之前剩余的空瓶
//     }

//     //3.统计
//     printf("%d\n", total);
//     return 0;
// }


/*-------------------结构体----------------------*/
//1.结构体定义

// struct tag(结构体标签)
// {
//      member-list(成员列表);
// }variable-list(变量列表);

//定义1
//struct - 结构体关键字
//stu - 结构体标签
//struct stu - 结构体类型
//s - 结构体变量
//声明一个结构体类型(不占内存) 整个类似int
// struct stu
// {
//     //成员变量
//     char name[20];
//     short age;
// } s1, s2, s3;//s1 s2 s3 是全局的结构体变量(尽量少使用)
// int main()
// {
//     struct stu s;//创建结构体变量 类型int a   s是局部的结构体变量
//     return 0;
// }

//定义2
//这里是把 struct stu 定义成 stu 
//类似于 typedef unsigned char BYTE;
//于是后面可以直接拿 stu 等价于 struct stu
// typedef struct stu
// {
//     //成员变量
//     char name[20];
//     short age;
// }stu;//此处的stu是结构体类型 

// int main()
// {
//     stu s;//s是局部的结构体变量,此时的stu等价于struct stu
//     return 0;
// }


//2.结构体嵌套初始化
// struct S
// {
//     char arr[15];//名字
//     int age;      //年龄
//     char sex[5]; //性别
// };
// struct T
// {
//     char ch[10];
//     struct S s;
//     char *p;
// };
// int main()
// {
//     char arr[] = "hello";
//     struct T t = {"hehe", {"wang", 12, "男"}, arr};
//     printf("%s\n", t.ch);
//     printf("%s\n", t.s.arr);
//     printf("%s\n", t.p);
//     return 0;
// }

//3.结构体的成员访问
// struct S
// {
//  int data[1000];
//  int num;
// };
// struct S s = {{1,2,3,4}, 1000};

// //结构体传参
// void print1(struct S s)
// {
//     printf("%d\n", s.num);
// }
// //结构体地址传参
// void print2(struct S* ps)
// {
//     printf("%d\n", ps->num);//也等效于 (*ps).num
// }
// int main()
// {
//     print1(s);  //传结构体
//     print2(&s); //传地址
//     return 0;
// }
//一般选择print2 不需要额外开辟太多空间 若一个结构体是200字节 那函数形参也要拷贝用掉200字节 若是用指针 那么只占用4/8个字节 因为指针本质存的是地址
//函数传参的时候，参数是需要压栈的。 如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大，所以会导致性能的下降。


/*-------------------字符串函数使用----------------------*/
//1.strlen   size_t strlen ( const char * str );
// 字符串已经 '\0' 作为结束标志，strlen函数返回的是在字符串中 '\0' 前面出现的字符个数（不包含 '\0' )。
// 参数指向的字符串必须要以 '\0' 结束。
// 注意函数的返回值为size_t，是无符号的（ 易错 ）
// 学会strlen函数的模拟实现

//计数器法
// int my_strlen(char* pc)
// {
//     int count = 0;
//     while(*pc!='\0')  //此处也可以换成while(*str)  *str=='/0'时候相当于0
//     {
//         count++;
//         pc++;
//     }
//     return count;
// }

//不能创建临时变量法(使用嵌套函数)
// int my_strlen(char* pc)
// {
//     if(*pc == '\0')
//         return 0;
//     else
//         return 1 + my_strlen(pc + 1); //pc+1意思是指向下一个元素的地址
// }

//指针-指针法
// int my_strlen(char* pc)
// {
//     char *p = pc;
//     while(*p != '\0')
//         p++;
//     return p - pc;//找出首尾元素地址 他们的差就是长度
// }

// int main()
// {
//     char a[10] = {"hello"};
//     printf("%d\n", my_strlen(a));
//     return 0;
// }

//2.strcpy和strncpy (字符串复制)

//char* strcpy(char * destination, const char * source);
// 源字符串必须以 '\0' 结束。
// 会将源字符串中的 '\0' 拷贝到目标空间。
// 目标空间必须足够大，以确保能存放源字符串。
// 目标空间必须可变。

// #include <assert.h>
// //strcpy返回目标串的地址，这个返回值的目的是可以使strcpy用在链式表达式中，增加灵活性
// //例如len=strlen(strcpy(s2,s1+1)); 
// char *my_strcpy(char *dest, char *src)
// {
//     char *ret = dest;
//     assert(dest!=NULL);
//     assert(src != NULL);
//     while((*dest++ = *src++) != '\0') //先执行前面的赋值语句 后判断是否是到终点 所以最终是赋值了'\0'
//     {
//         ;
//     }
//     return ret;
// }

// int main()
// {
//     char a[10] = "hello";
//     char b[20] = {0};
//     my_strcpy(b, a);
//     printf("%s\n", b);
//     return 0;
// }


//char * strncpy ( char * destination, const char * source, size_t num );
// 拷贝num个字符从源字符串到目标空间。
// 如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个
// 学会模拟实现。
// #include <assert.h>
// char *my_strncpy(char *dest, char *src, int n)
// {
//     int i = 0;
//     char *ret = dest;
//     assert(dest!=NULL);
//     assert(src != NULL);
//     //\0 表示空字符NULL，对应的ASCII码为0
//     while (*src != '\0' && i < n) //与前面不同这里是先判断 再转移; i < n 其实使得里面的程序执行了n次
//     {
//         *dest++ = *src++;
//         i++;
//     }
//     return ret;
// }

// int main()
// {
//     char a[10] = "hello bit";
//     char b[20] = {0};
//     my_strncpy(b, a, 8);
//     printf("%s\n", b);
//     return 0;
// }

//3.strcat和strncat (字符串拼接)

//char * strcat ( char * destination, const char * source );
// 源字符串必须以 '\0' 结束。
// 目标空间必须有足够的大，能容纳下源字符串的内容。
// 目标空间必须可修改
// NOTICE:不能使用strcat 自己给自己拼接
// 因为strcat机制 将 目标 末尾'\0' 转换为另目标的开头 最终检测到'\0' 则结束
// #include <assert.h>
// char *my_strcat(char *dest, char *src)
// {
//     char *ret = dest;
//     assert(dest!=NULL);
//     assert(src != NULL);
//     while((*dest)!='\0')  //先找到dest目标的\0
//     {
//         dest++;
//     }
//     while((*dest++ = *src++)!='\0')//再再dest把\0替换追加
//         ;
//     return ret;
// }
// int main()
// {
//     char a[20] = "hello";
//     char b[10] = " bit!";
//     my_strcat(a, b);
//     printf("%s\n", a);
//     return 0;
// }

//char * strncat ( char * destination, const char * source, size_t num );
// 将源的前num个字符附加到目标，再加上一个终止的空字符。
// 如果source中的C字符串长度小于num，则只复制到终止null character之前的内容。
// #include <assert.h>
// char *my_strncat(char *dest, char *src, int n)
// {
//     int i = 0;
//     char *ret = dest;
//     assert(dest!=NULL);
//     assert(src != NULL);
//     while((*dest)!='\0')  //先找到dest目标的\0
//     {
//         dest++;
//     }
//     while( *src !='\0' && i < n)//与前面cpy类似
//     {
//         *dest++ = *src++;
//         i++;
//     }
//     return ret;
// }
// int main()
// {
//     char a[20] = "hello";
//     char b[10] = " bit!";
//     my_strncat(a, b, 3);
//     printf("%s\n", a);
//     return 0;
// }

//4.strcmp和strncmp

//int strcmp (const char * str1, const char * str2 );
//NOTICE:这里用const char 而不用 char 是因为比较的时候不改变原来的值
//       const 可以避免不小心改变原值 
// 第一个字符串大于第二个字符串，则返回大于0的数字
// 第一个字符串等于第二个字符串，则返回0
// 第一个字符串小于第二个字符串，则返回小于0的数字
// #include <assert.h>
// int my_strcmp (const char * dest, const char * src)
// {
//     int ret = 0;
//     assert(dest!=NULL);
//     assert(src!=NULL);
//     while( !(ret=*(unsigned char *)src - *(unsigned char *)dest) && *dest != '\0')
//     //将两个有符号char指针类型强制转换成无符号的char类型 再解引用就是元素 相减根据ASCII码判断谁大谁小
//     //把差的结果给ret 当两个字母相同 ret=0 !ret=1 程序继续; 当dest到末尾时 也结束比较
//     {
//         ++src;
//         ++dest;
//     }
//     if (ret < 0)
//     {
//         ret = -1;
//     }
//     else if (ret > 0)
//     {
//         ret = 1;
//     }
//     return ret;
// }
// int main()
// {
//     int ret;
//     char a[20] = "hello";
//     char b[10] = "hebll";
//     ret=my_strcmp(a, b);
//     printf("%d\n", ret);
//     return 0;
// }

//5.strstr (查找子字符串)
// char * strstr ( const char *, const char * )
//返回指向str1中第一个出现的str2的指针，如果str2不是str1的一部分，则返回空指针。

// #include <assert.h>
// //NOTICE: 找字符串的一个点是 
// //若abbbc中找bbc 不记录可能出现的起始位置cur 那么很可能就找不到 找到bbb就退出了
// char *my_strstr(const char *dest, const char *src)
// {
//     assert((dest != NULL)&& (src != NULL));
//     char *p1 = (char *)dest; //为了不改动原来的位置 利用了替换
//     char *p2 = (char *)src; 
//     char *cur =(char *)dest;
//     if(*p2 == '\0')//若找的是只有一个'\0' 那么直接返回dest地址
//     {
//         return (char *)dest;
//     }
//     while(*cur) //cur记录可能出现匹配的位置 失配的时候就回溯回去重新匹配
//     {
//         p1 = cur;//p1从cur位置匹配
//         p2 = (char *)src;//p2从src的其实位置匹配 每次都回到这里
//         while((*p1 != '\0') && (*p2 != '\0') && (*p1 == *p2))
//         //若p1++后 p1 =\0 则找不到了 cur也会加一 退出循环
//         //若p2++后 p2 =\0 说明到头了 找到了
//         //*p2 == *p1  每次比较判断他们是否相等
//         {
//             p1++;
//             p2++;
//         }
//         if(*p2 == '\0')
//         {
//             return cur; //找到了
//         }
//         cur++;
//     }
//     return NULL;//找不到
// }
// int main()
// {
//     char a[10] = "abbbced";
//     char b[] = "bbc";
//     char *ret = NULL;
//     ret = my_strstr(a, b);
//     if (ret != NULL)
//     {
//         printf("找到了~ %s\n",ret);
//     }
//     else
//     {
//         printf("找不到！");
//     }  
//     return 0;
// }

//6.strtok (字符串分割)
//char * strtok (char *str, const char *sep);
// sep参数是个字符串，定义了用作分隔符的字符集合
// 第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
// strtok函数找到str中的下一个标记，并将其用 \0 结尾，返回一个指向这个标记的指针。
//（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
// strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
// strtok函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
// 如果字符串中不存在更多的标记，则返回 NULL 指针。

//strtok其实是找分隔符 并将分隔符改成\0 那么打印的画就取出了第一部分
//第一次传入arr地址 第n次就是传入NULL就行 因为它会记住分隔符下一个地址

// #include <string.h>
// int main()
// {
//     char arr[] = "123@124.@166";
//     char *p = "@.";
//     char buff[1024] = {0};
//     strcpy(buff, arr);
//     char *ret = NULL;
//     for (ret = strtok(arr, p);  ret != NULL; ret = strtok(NULL,p))  //arr只用传一次 后面都是传NULL 当ret返回NULL时候 说明已经到\0了
//     {
//         printf("%s\n", ret);
//     }
//     return 0;
// }

//7.strerror (返回错误码)
// 把错误码翻译成错误信息
// #include <string.h>
// #include <errno.h> 
// //errno 是一个全局的错误码变量
// //当c语言的库函数在执行过程中 发生错误时 就会把对应的错误码 赋值到errno中

// int main()
// {
//     //例如
//     //当fopen打不开文件的时候 会返回一个FILE类型的NULL指针
//     //但是打不开的原因有很多 像无文件 权限不够 等等
//     //此时可以利用strerror(errno) 获得对应的错误信息
//     FILE *pf = fopen("test.txt", "r");
//     if (pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         printf("Success!");
//     }
//     return 0;
// }


/*-------------------字符函数使用----------------------*/

// 1.字符分类函数
//  函数   如果他的参数符合下列条件就返回真
// iscntrl 任何控制字符
// isspace 空白字符：空格‘ ’，换页‘\f’，换行'\n'，回车‘\r’，制表符'\t'或者垂直制表符'\v'
// isdigit 十进制数字 0~9
// isxdigit 十六进制数字，包括所有十进制数字，小写字母a~f，大写字母A~F
// islower 小写字母a~z
// isupper 大写字母A~Z
// isalpha 字母a~z或A~Z
// isalnum 字母或者数字，a~z,A~Z,0~9
// ispunct 标点符号，任何不属于数字或者字母的图形字符（可打印）
// isgraph 任何图形字符
// isprint 任何可打印字符，包括图形字符和空白字符
// 返回的是int型 且为真时 不一定返回的是1
// #include <ctype.h>
// int main()
// {
//     char ch = 'w';
//     int ret = islower(ch);
//     printf("%d\n", ret);
//     return 0;
// }

// 2.字符转换
// int tolower(int c) 把给定的字母转换为小写字母
// int toupper(int c) 把给定的字母转换为大写字母

/*-------------------内存操作函数使用----------------------*/
//strcpy等等只能操作字符串 有局限性
// 1.memcpy (内存拷贝)
//void * memcpy ( void * destination, const void * source, size_t num);
//void * - 通用型指针; size_t 单位是字节
// 函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
// 这个函数在遇到 '\0' 的时候并不会停下来。
// 如果source和destination有任何的重叠，复制的结果都是未定义的。

// #include <string.h>
// int main()
// {
//     int arr1[] = {1, 2, 3, 4};
//     int arr2[4] = {0};
//     memcpy(arr2, arr1, sizeof(arr1));//从arr1复制 到arr2
//     printf("%d\n", arr2[2]);
//     //struct类型也可以
//     return 0;
// }

//模拟实现memcpy
//void* 不能解引用和++--
//思想是分割成最小的一个字节 全部复制
//这里是从前往后拷贝 有时候可以是从后往前
//C语言标准：
//memcpy 只要处理 不重叠的内存拷贝就行
//memmove 处理重叠内存的拷贝
// #include <assert.h>
// void *my_memcpy(void *dest, const void *src, size_t num)
// {
//     void *ret = dest;
//     assert(dest != NULL && src != NULL);
//     while(num--)
//     {
//         *(char *)dest = *(char *)src;
//         (char *)dest++;
//         (char *)src++;//lvalue required as increment operand 表示不能对src进行++--
//     }
//     return ret;
// }
// int main()
// {
//     int arr1[] = {1, 2, 3, 4};
//     int arr2[4] = {0};

//     my_memcpy(arr2, arr1, sizeof(arr1));//从arr1复制 到arr2
//     printf("%d\n", arr2[2]);
//     //struct类型也可以
//     return 0;
// }

// 2.memmove (内存操作 解决内存重叠问题)
// case 1:当dest在src的前面时候 前->后拷贝
// case 2:当dest在src和src+num的中间的时候 后->前
// case 3:当dest在src的后面时候 前->后 或者 后->前

#include <assert.h>
void *my_memmove(void *dest, const void *src, size_t num)
{
    void *ret = dest;
    assert(dest != NULL && src != NULL);
    if ((char *)src < (char *)dest ) //dest在后边 后->前 (指的是src)
    {
        while(num--)
        {
            *(char *)(dest + num) = *(char *)(src + num);
        }
    }
    else //dest在前边 前->后 (指的是src)
    {
        while(num--)
        {
            *(char *)dest = *(char *)src;
            (char *)dest++;
            (char *)src++;//lvalue required as increment operand 表示不能对src进行++--
        }
    }
    return ret;
}
int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //my_memmove(arr1+2, arr1, 12);//从arr1+2 指的是第三个元素
    //该代码指的是把1 2 3 复制到 原来 3 4 5 的区域 - 测试dest在后
    my_memmove(arr1, arr1+2, 12);
    //该代码指的是把3 4 5 复制到 原来 1 2 3 的区域 - 测试dest在前
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr1[i]);
    }
    //struct类型也可以
    return 0;
}

