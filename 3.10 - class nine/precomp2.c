#include <stdio.h>

//三、预处理详解
// 预定义符号：
// __FILE__      //进行编译的源文件
// __LINE__     //文件当前的行号
// __DATE__    //文件被编译的日期
// __TIME__    //文件被编译的时间
// __STDC__    //如果编译器遵循ANSI C，其值为1则未定义

// #include <stdio.h>
// int main()
// {
//     //可以用来写日志
//     //printf("%s\n", __TIME__);

//     //写日志
//     int i = 0;
//     int arr[10] = {0};
//     FILE *pf = fopen("log.txt", "w");
//     if(pf == NULL)
//     {
//         return 0;
//     }
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = i;
//         fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n",
//                 __FILE__, __LINE__, __DATE__, __TIME__, arr[i]);
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d\n", arr[i]);
//     }
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

//  2. #define 定义宏和符号

// ①宏之后一般避免加';'
// #define MAX 100 //之后避免加分号';'
// 例如
// #define MAX 100;
// printf("%d\n", MAX);就会出错 因为预编译后 变成 printf("%d\n", 100;);

// ②宏的参数不是传参的而是替换的
// #define Square(x) x*x
// int main()
// {
//     int ret = Square(5 + 1);//宏的参数不是传参的而是替换的
//     //即 Square(5+1) = 5+1*5+1 = 5+5+1 = 11
//     printf("%d\n", ret);
//     return 0;
// }
// 所以用于对数值表达式进行求值的宏定义都应该用这种方式加上括号，避免在使用宏时由于参数中的操作符或邻近操作符之间不可预料的相互作用
// 所以为了明确的指明计算顺序 一般需要加括号
// 上面的宏可以改成 #define Square(x) (x)*(x)

// #define 替换规则
// 在程序中扩展#define定义符号和宏时，需要涉及几个步骤。
// 1. 在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，它们首先被替换。
// 2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
// 3. 最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述处理过程。
// 注意：
// 1. 宏参数和#define 定义中可以出现其他#define定义的变量。但是对于宏，不能出现递归。
// 2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索. //例如printf("MAX")中的MAX不会被替换

//  3. #和##
// ①使用 '#', 把一个宏参数变成对应的字符串
// #define PRINT(X) printf("the value of "#X" is %d\n", X)
// //#X 表示 X对应的字符串 当X=a时候 等价于 "a" 又由于字符串的拼接性质 就可以打印出对应的内容了
// int main()
// {
//     // printf("hehe\n");
//     // printf("he" "he\n");//输出的效果会与前面相同 因为字符串会自动拼接
//     int a = 10;
//     int b = 20;
//     PRINT(a);
//     PRINT(b);
//     return 0;
// }

// ②##可以把位于它两边的符号合成一个符号。 它允许宏定义从分离的文本片段创建标识符。
// #define CAT(X,Y) X##Y
// int main()
// {
//     int Class84 = 2021;
//     printf("%d\n", CAT(Class, 84));
//     //编译器会把 Class##84 -> 拼接成Class84 最终变成可识别的变量名
//     return 0;
// }

// 4.带副作用的宏参数
// int main()
// {
//     int a = 1;
//     int b = a + 1;//此处没副作用 a还是1
//     int c = ++a;//这里是带有副作用的 即a变成了2了
//     printf("%d %d %d\n", a, b, c);
//     return 0;
// }

//一个严格的求最大值的宏
// #define MAX(X,Y) ((X)>(Y)?(X):(Y))
// //在带有副作用的宏参数 可能与想象中的结果不同
// int main()
// {
//     int a = 10;
//     int b = 11;
//     int max = MAX(a++, b++);
//     //替换后变成 ((a++)>(b++)?(a++):(b++))
//     // 1.10+1 > 11+1 为假 a=11 b=12
//     // 2.为假时 返回(b++) ++在后 先用后加 所以返回的是12 之后b+1=13 
//     printf("%d\n", max);
//     printf("%d\n", a);
//     printf("%d\n", b);
//     return 0;
//     //答案就是 12 11 13
// }

// 5.宏和函数对比
// 宏通常被应用于执行简单的运算。比如在两个数中找出较最大的一个；

// 宏的优势:
// 1.宏比函数在程序规模和速度方面更胜一筹。 用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。
// 2.宏是类型无关的。 更为重要的是函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用。反之这个宏怎可
// 以适用于整形、长整型、浮点型等可以用于>来比较的类型。
// 例如:
// #define MALLOC(num, type) 
//  (type *)malloc(num * sizeof(type)) 
// ... 
// //使用
// MALLOC(10, int);//类型作为参数
// //预处理器替换之后：
// (int *)malloc(10 * sizeof(int));

// #define MAX(X,Y) ((X)>(Y)?(X):(Y))
// //函数在调用时 会有返回和开销;而宏在预处理阶段就完成了替换 就更加有效率

// 宏的劣势:
// 1. 每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
// 2. 宏是没法调试的。
// 3. 宏由于类型无关，也就不够严谨。
// 4. 宏可能会带来运算符优先级的问题，导致程容易出错

//题目 - 一个求地址偏移量的宏
//即 模拟实现 #include <stddef.h> 中的offsetof(type, member-designator) 函数

#include <stddef.h>

struct S
{
    char c1;//1/8 取1 0+1
    int a;//4/8 取4 4+4
    char c2;//1/8 1 8+1
    //最大对齐数是4 总取9+3 = 12(4的整数倍)
};
#define OFFSETOF(struct_name, member_name) (int)&(((struct_name *)0)->member_name)
// 0强制转换成这个结构体的初始地址 再找到成员的地址 再强制转换成int型
int main()
{
    printf("%d\n", offsetof(struct S, a));
    printf("%d\n", OFFSETOF(struct S, a));
    return 0;
}
