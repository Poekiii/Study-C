#include <stdio.h>


// 【程序 1】1~4 组成无重复数字的三位数。
// 题目：有 1、2、3、4 个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
// 1.程序分析：可填在百位、十位、个位的数字都是 1、2、3、4。组成所有的排列后再去掉不满足条件的排
// 列。 
// int main()
// {
//     int i, j, k;
//     int count = 0;
//     for (i = 1; i < 5; i++)
//         for (j = 1; j < 5; j++)
//             for (k = 1; k < 5; k++)
//                 {
//                     if(i!=j&&j!=k&&k!=i)
//                         {
//                             count++;
//                             printf("%d\n", i * 100 + j * 10 + k * 1);
//                         }
//                 }
//     printf("%d\n", count);
//     return 0;
// }


// 【程序 2】企业利润计算（switch）
// 题目：企业发放的奖金根据利润提成。利润(I)低于或等于 10 万元时，奖金可提 10%；利润高于 10 万元，
// 低于 20 万元时，低于 10 万元的部分按 10%提成，高于 10 万元的部分，可可提成 7.5%；20 万到 40 万之
// 间时，高于 20 万元的部分，可提成 5%；40 万到 60 万之间时高于 40 万元的部分，可提成 3%；60 万到
// 100 万之间时，高于 60 万元的部分，可提成 1.5%，高于 100 万元时，超过 100 万元的部分按 1%提成，从
// 键盘输入当月利润 I，求应发放奖金总数？
// #include <stdio.h>
// int main()
// {
//     float li;
//     float bo1, bo2, bo3, bo4, bo5;
//     float bo = 0;
//     printf("请输入利润(万元):>");
//     scanf("%f", &li);
//     bo1 = 10 * 0.1;
//     bo2 = bo1 + 10 * 0.075; //算出最高的奖金值
//     bo3 = bo2 + 20 * 0.05;
//     bo4 = bo3 + 20 * 0.03;
//     bo5 = bo4 + 40 * 0.015;

//     if (li<10&&li>0) bo = li * 0.1;
//     if (li>=10&&li<20) bo = bo1 + (li - 10) * 0.075;
//     if (li>=20&&li<40) bo = bo2 + (li - 20) * 0.05;
//     if (li>=40&&li<60) bo = bo3 + (li - 40) * 0.03;
//     if (li>=60&&li<100) bo = bo4 + (li - 60) * 0.015;
//     if (li>100) bo = bo5 + (li - 100) * 0.01;

//     printf("奖金为:%.2f万元\n", bo);
//     return 0;
// }


// 【程序 3】加 100 是完全平方数
// 题目：一个整数，它加上 100 后是一个完全平方数，再加上 168 又是一个完全平方数，请问该数是多少？
// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     int i;
//     long int x,y;
    
//     //sqrt 其实是double sqrt(double); 当输出的结果赋值给long int时,就只有整数部分了
//     //此时如果开方的结果不是整数 再测试返回结果使其平方就原来数值(i+100)有偏差 因此可以筛出整数的结果 
//     for (i = 0; i < 100000; i++)
//     {
//         x = sqrt(i + 100);//x 为加上 100 后开方后的结果
//         y = sqrt(i + 268);//y 为再加上 168 后开方后的结果
//         if(x*x == i+100 && y*y == i+268)//如果一个数的平方根的平方等于该数，这说明此数是完全平方数
//             printf("%ld\n", i);
//     }

//     return 0;
// }

// 【程序 4】年月日判断是年份的第几天。
// 题目：输入某年某月某日，判断这一天是这一年的第几天？
// int run_yea(int yea)
// {
//     if (yea%4==0&&yea%100!=0)//闰年
//         return 1;
//     else
//         return 0;
// }
// int main()
// {
//     int yea, mon, day;
//     int run_flag;
//     int sum=0;
//     printf("请依次输入年月日:>");
//     scanf("%d%d%d", &yea, &mon, &day);
//     run_flag = run_yea(yea);
//     switch (mon)//把当月前面的日子都加起来
//     {
//         case 1:
//             sum = 0;
//             break;
//         case 2:
//             sum = 31;
//             break;
//         case 3:
//             sum = 31+28;
//             break;
//         case 4:
//             sum = 31+28+31;
//             break;
//         case 5:
//             sum = 31+28+31+30;
//             break;
//         case 6:
//             sum = 31+28+31+30+31;
//             break;
//         case 7:
//             sum = 31+28+31+30+31+30;
//             break;
//         case 8:
//             sum = 31+28+31+30+31+30+31;
//             break;
//         case 9:
//             sum = 31+28+31+30+31+30+31+31;
//             break;
//         case 10:
//             sum = 31+28+31+30+31+30+31+31+30;
//             break;
//         case 11:
//             sum = 31+28+31+30+31+30+31+31+30+31;
//             break;
//         case 12:
//             sum = 31+28+31+30+31+30+31+31+30+31+30;
//             break;
//         default:            
//             printf("data error!");
//             break;
//     }
//     sum = sum + day;
//     if(run_flag==1&&mon>2)
//     {
//         sum++;
//     }
//     printf("%d\n", sum);
//     return 0;
// }

// #include <assert.h>
// #include <string.h>
// //题目5
// //字符串逆序 不是逆序打印 而是把内存空间的存储内容都逆序
// void reverse(char* str)
// {
//     assert(str);//assert的作用是现计算表达式 expression ，如果其值为假（即为0），那么它先向stderr打印一条出错信息，
//     //然后通过调用 abort();来终止程序运行
//     //因为当str指针指向NULL的时候 就会出现重大错误 提前检查可以避免出错 
//     //assert常用于检查指针的有效性
//     int len = strlen(str);
//     char *left = str;
//     char *right = str + len - 1;//因为字符串最后隐藏了/0

//     while(left<right) // 首尾元素指向指向互换 若指向同一个位置时后 或者 指向的地址左边大于右边 说明已经越界 就不用再交换了
//     {
//         char tmp = *left;
//         *left = *right;
//         *right = tmp;
//         left++;
//         right--;
//     }

// }
// int main()
// {
//     char arr[256] = {0};
//     scanf("%s", arr);
//     //gets(arr);//读取一行
//     reverse(arr);
//     printf("%s", arr);
//     return 0;
// }

//题目6 
//求输入数值a的前n项和    sn = a+aa+aaa+aaaa+aaaaa...
// int main()
// {
//     int a, n;
//     int ret = 0;
//     int sum = 0;
//     scanf("%d%d", &a, &n);

//     for (int i = 0; i < n; i++)
//     {
//         ret = ret * 10 + a;
//         sum += ret;
//     }

//     printf("%d\n", sum);
//     return 0;
// }\

//题目7
//求100000以内的自幂数  例如(153=1^3+3^3+3^5)三位的自幂数 又称水仙花数
// #include <math.h>
// int main()
// {
//     int i;
//     for (i = 0; i <=100000; i++)
//     {
//         //1.计算i的位数 n
//         int n = 1;//任何一个数都是大于一位数的
//         int tmp = i;//因为i是for循环的参考量 不太好动 所以用临时变量
//         int sum = 0;//存储i的每位的n次方的和
//         while( tmp /= 10)//除一次10统计一位 若tmp小于10时 会跳出循环
//         {
//             n++;
//         }

//         //2.计算i的每一位的n次方之和 sum
//         tmp = i;
//         while (tmp)
//         {
//             //NOTICE: 原：sum += pow(tmp % 10, n);  最终结果没有153
//             //由于原来pow(a,b)返回的值是浮点数 但是我们存入整型中
//             //编译器会自行隐式转换 而由于精度误差 算出结果可能是125.00001或者124.99999
//             //不同编译器可能四舍五入(较常见)，取上整(不多见)或者取下整(多见于嵌入式)
//             //所以需要把需要把 pow(a,b) 改成 (int)round(pow(a,b)) （round四舍五入，另外round自己出来的结果也是浮点，需要再取成整型）
//             sum += (int)round(pow(tmp % 10, n));// tmp%10是求最低位
//             tmp /= 10;// tmp/10 减去最低位了
//         }

//         //3.比较i与sum
//         if(i == sum)
//         {
//             printf("%d\n", i);
//         }
//     }
//     return 0;
// }


//题目8
//图形打印
// int main()
// {
//     int line = 0;//行数
//     scanf("%d", &line);

//     //打印上半部分 line行
//     int i = 0;
//     for (i = 0; i < line; i++)
//     {
//         //1.打印空格
//         int j = 0;
//         for (j = 0; j < line-1-i; j++)
//         {
//             printf(" ");
//         }
//         for (j = 0; j < 2*i+1; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }

//     //打印下半部分 line-1行
//     for (i = 0; i < line; i++)
//     {
//         //1.打印空格
//         int j = 0;
//         for (j = 0; j <= i; j++)
//         {
//             printf(" ");
//         }
//         for (j = 0; j < 2*(line-1-i)-1; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }


//题目9
typedef union {
    short i;
    int k[5]; //4*5
    char c;
} Mat; //union 一次只调用一个成员 它的大小只算最大的那个成员
typedef struct {
    int i;  //4
    Mat j;  //Mat 20
    double k;//8
}Like;
int main()
{
    printf("%d",sizeof(Like)+sizeof(Mat));
    return 0;
    //20+32=52
}
