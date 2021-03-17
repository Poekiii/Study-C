/*-------------------------电子工程学院面试真题----------------------------*/
// 1.（1）C 程序的基本单位是什么？（2）C 语言中的占用 2 个字节的 int 型变量表示的数值范围是？
// (1) C程序的基本单位是函数;(2) 2字节的int变量表示范围为 -(2^15-1)~(2^15)

// 2.用C语言实现：主函数中由用户输入的三个数，打印输出三个数中的
// 最大值，要求用函数调用实现。请写出完整的代码。
// #include <stdio.h>
// int Find_MAX(int a[3])
// {
//     return a[0] > a[1] ? a[0] : (a[1] > a[2] ? a[1] : a[2]);
// }
// // #define MAX(a,b) ((a)>(b)?(a):(b))
// int main()
// {
//     int a[3] = {0};
//     printf("请输入3个数:>");
//     for (int i = 0; i < 3; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     int max = Find_MAX(a);
//     printf("MAX:%d\n", max);
//     return 0;
// }

// 3.用C语言实现：实现输入整数N ，计算的X=1+(1/2^1)+(1/2^2)....+(1/2^N)结果并打印输出。
// （1）请写出完整的代码。（2）请画出流程图。
// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     int N = 0;
//     float X = 0.0f;
//     printf("请输入整数N:>");
//     scanf("%d", &N);
//     for (int i = 0; i <= N; i++)
//     {
//         X += 1.0 / (pow(2, i));
//     }
//     printf("X=%f\n", X);
//     return 0;
// }

// 4.用C语言实现：输入数组 A 的十个整数，输出数组 A 中所有的偶数，要求用指针的方式实现。请写出完整的代码.
// #include <stdio.h>
// int main()
// {
//     int a[3] = {0};
//     int *p = &a;
//     printf("请输入3个整数:>");
//     for (int i = 0; i < 3; i++)
//     {
//         scanf("%d", p+i);
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         if(*(p+i)%2 ==0)
//             printf("%d ", *(p+i));
//     }
//     return 0;
// }

/*-------------------------C语言大题----------------------------*/
//1.冒泡排序 - 从小到大
// #include <stdio.h>
// void Bubble_Sort(int a[],int len)
// {
//     for (int i = 0; i < len - 1; i++) //一共len-1趟
//         for (int j = 0; j < len - i - 1; j ++) //一趟比较len-i-1次
//         {
//             if(a[j]>a[j+1])
//             {
//                 int tmp = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = tmp;
//             }
//         }
// }
// int main()
// {
//     int a[10] = {0};
//     printf("请输入5个数值:>");
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     Bubble_Sort(a,5);
//     printf("冒泡排序后:>\n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }

// 2.判断闰年 - 年份1.能够被4整除 但是不能被100整除 2.能够被400整除
// #include <stdio.h>
// int RunYear_judge(int year)
// {
//     if(((year%4 == 0)&&(year%100 != 0))||(year%400 == 0))
//         return 1;
//     else
//         return 0;
// }
// int main()
// {
//     int year = 0;
//     printf("请输入年份:>");
//     scanf("%d", &year);
//     if(RunYear_judge(year))
//         printf("%d年是闰年~\n",year);
//     else
//         printf("%d年不是闰年！\n",year);
//     return 0;
// }

// 3.将某三位数分离 - 年份能够被4整除 但是不能被100整除
// #include <stdio.h>
// int main()
// {
//     int X = 0;
//     int g, s, b;
//     printf("请输入一个数字:>");
//     scanf("%d", &X);
//     b = X / 100 ;
//     s = X / 10 % 10;  //与 X % 100 /10 - X对100求余 那么就只剩下十位和百位了
//     g = X % 10;
//     printf("b:%d s:%d g:%d\n", b, s, g);
//     return 0;
// }

// 4.斐波那契数列 - 第x月的兔子数量
// #include <stdio.h>
// int main()
// {
//     long f1, f2, nextTerm = 0;
//     f1 = 0;
//     f2 = 1;
//     int N;
//     printf("你要知道的月份:>");
//     scanf("%d", &N);
//     for (int i = 1; i < N; i ++)
//     {
//         nextTerm = f1 + f2;
//         f1 = f2;
//         f2 = nextTerm;
//     }
//     printf("第%d月的兔子数:%d\n", N, nextTerm);
//     return 0;
// }

// 5.最大公约数和最小公倍数
// #include <stdio.h>
// 已知：A / B = C ······ R  （A、B、C、R皆是整数）
// 假设：D是A的余数，D也是B的余数，那么D就是A和B的公约
// D是A和B的约数，则A和B是D的倍数，B * C也是D的倍数
// 既然A与B*C都是D的倍数，那么A与B*C的差也是D的倍数
// A - B*C = R
// 所以R也是D的倍数
// 如果D是A或B的公约数，那么D也是B和R的公约数
// 故：（A,B）= （B,R）
// 由以上证明则可以求出最大的公约数
// int Com_Div(int num1,int num2)//辗转相除法
// {
//     int r;//余数
//     if(num1 < num2) //1号数小于2号数 则交换
//     {
//         int tmp = num1;
//         num1 = num2;
//         num2 = tmp;
//     }
//     r = num1 % num2;
//     while(r != 0)
//     {
//         num1 = num2;
//         num2 = r;
//         r = num1 % num2;
//     }
//     return num2;
// }
// int Com_Mult(int num1,int num2) //最小公倍数=两数的乘积/最大公约(因)数
// {
//     return num1 * num2 / Com_Div(num1, num2);
// }
// int main()
// {
//     int a = 0, b = 0;
//     scanf("%d%d", &a, &b);
//     int ans_l = Com_Div(a, b);
//     int ans_g = Com_Mult(a, b);
//     printf("Least Com Div:%d\nGreat Com Mult:%d\n", ans_l, ans_g);
//     return 0;
// }

// 6.求素数
// #include <stdio.h>
// #include <math.h>
// 在数学中我们知道素数是约数只有1和本身的整数称为质数，或称素数。
// 暴力枚举1
// 根据素数的性质，判断当前数是否为素数可以通过for()控制从2开始到当前数，如果在该过程中存在可以整除的数字则该数不是素数，若没有则该数为素数。
// int main()
// {
//     int n;
//     int flag = 1;
//     scanf("%d", &n);
//     for (int i = 2; i < n;  i++)
//     {
//         if(n%i == 0)
//         {
//             flag = 0;
//             printf("%d不是素数!",n);
//             break;
//         }
//     }
//     if(flag)
//     {
//         printf("%d是素数~",n);
//     }
//     return 0;
// }

// 暴力枚举2
// 上述判断方法，明显存在效率极低的问题。对于每个数n，其实并不需要从2判断到n-1，
// 我们知道，一个数若可以进行因数分解，那么分解时得到的两个数一定是一个小于等于sqrt(n)，一个大于等于sqrt(n)，
// 据此，上述代码中并不需要遍历到n-1，遍历到sqrt(n)即可，因为若sqrt(n)左侧找不到约数，那么右侧也一定找不到约数。
// int main()
// {
//     int n;
//     int flag = 1;
//     scanf("%d", &n);
//     for (int i = 2; i < sqrt(n);  i++)
//     {
//         if(n%i == 0)
//         {
//             flag = 0;
//             printf("%d不是素数!",n);
//             break;
//         }
//     }
//     if(flag)
//     {
//         printf("%d是素数~",n);
//     }
//     return 0;
// }

// 题目 - 打印101~200之间的素数
// int main()
// {
//     int m,n;
//     int flag = 1;
//     int total = 0;
//     scanf("%d%d", &m, &n);
//     for (int i = m; i <= n; i++)
//     {
//         int k = sqrt(i+1);
//         for (int j = 2; j <= k; j++)
//         {
//             if (i % j == 0)
//             {
//                 flag = 0;
//                 printf("%d不是素数!\n", i);
//                 break;
//             }
//         }
//         if(flag)
//         {
//             total++;
//             printf("%d是素数~\n",i);
//         }
//         flag = 1;
//     }
//     printf("素数一共有:%d\n", total);
//     return 0;
// }

