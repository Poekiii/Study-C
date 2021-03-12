#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------数据结构篇-------------------------------------------*/
// 一、时间复杂度
// 时间复杂度的定义:描述某算法的执行所消耗的时间。而算法中基本操作的执行次数，为算法的时间复杂度。
// 因为每一行代码差不多有固定的时间，那通过基本操作的执行次数，就可以评估消耗时间了。

// 1.1 大O的渐进表示法
// 实际中我们计算时间复杂度，并不关心精确的值，而是需要大概的执行次数，那么这就是大O的渐进表示法。即只保留高阶的结果。

//1.BubbleSort的时间复杂度
// void BubbleSort(int *a, int n)
// {
//     assert(a);
//     for (int end = n; end >0; --end) // 10 9 ... 1
//     {
//         int exchange = 0;
//         for (int j = 0; j < end; j++)
//         {
//             if(a[j - 1] > a[j])
//             {
//                 Swap(&a[i - 1], &a[i]);
//                 exchange = 1;
//             }
//         }
//         if(exchange == 0)
//             break;
//     }
// }

// 准确的次数
// F(N) = 1 + 2 + ... + N-1 等差数列 N*(N-1+1)/2 = 0.5N^2
// 那么时间复杂度位:O(N^2)  大O计法只取影响力最大的
// 最好情况:O(N)

//2.二分法找数
// int BinarySearch(int *a, int n, int x)
// {
//     assert(a);
//     int begin = 0;
//     int end = 0;
//     while(begin < end)
//     {
//         int mid = begin + ((end - begin) >> 1); //找到中间的数
//         if (a[mid] < x)
//             begin = mid + 1;
//         else if (a[mid > x])
//             end = mid;
//         else
//             return mid;
//     }
//     return -1;//找不到
// }
// 准确的次数 N表示一共多少个数 X表示查找次数
// N = 2 ^ X  那么 X = log 2 N
// 最好情况是:O(1)
// 最坏情况是:O(log 2 N)

//3.计算阶乘 - 递归法
// long long Factorial(size_t N)  
// {
//     return N < 2 ? N : Factorial(N - 1) * N;
// }
// 计算递归的时间复杂度 = 递归次数 * 每次递归函数的次数
// 1.首先递归了N次 N...1;
// 2.每次递归的函数次数 N次;
// 所以此处的时间复杂度为 O(N);
// 若存在 while (n--) 那么结果就为O(N ^ 2)

//4.1 斐波那契递归Fibonacci - 递归 ***
// long long Fibonacci(size_t N)
// {
//     return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
// }
// 画图分析
// 斐波那契数列的思想 是后一个数是前两个数之和  - 兔子繁殖
//     即Fib(n) = Fib(n - 1) + fib(n - 2);         Fib(0) = 0, Fib(1) = 1;
// f(n)                            1        2^0
// f(n-1) f(n-2)                   2        2^1
// f(n-2) f(n-3) f(n-3) f(n-4)     4        2^2
// ...........................    ...      .....
// f(1)                         2^(n-1)   2^(n-1)

// 总的次数就是(等比数列) = 1 - (2^(n - 1)*2) / -1  = 2^n - 1
// 取最高阶 时间复杂度为O(2^n)

//4.2 斐波那契递归Fibonacci -优化
//右上图可知 有非常多的重复项 这些重复性白算 占用时间

//求出到N时 斐波那契数(这里是求N以及N之前的所有数 并放到数组里面)
// long long* Fibonacci(size_t N)
// {
//     long long * FibArr = (long long *)malloc(sizeof(long long) * (N+1));
//     FibArr[0] = 0;
//     if  (N == 0)
//         return FibArr;
//     FibArr[1] = 1;
//     //以空间换时间
//     for(int i = 2; i <= N; ++i)
//     {
//         FibArr[i] = FibArr[i - 1] + FibArr[i - 2];
//     }
//     return FibArr;
// }
// int main()
// {
//     int n = 10;
//     long long *p = Fibonacci(n);
//     printf("%d\n", *(p+n-1));
//     free(p);
//     p = NULL;
//     return 0;
// }
//优化后的结果是 O(N)
// 时间复杂度不计算时间，而是计算大概的运算次数;
// 空间复杂度不计算空间，而是计算变量的个数.