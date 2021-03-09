//leetcode - 初级算法 - 2

/*-------------------数组类----------------------*/
// 题目1 - 买卖股票的最佳时机 II
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 示例 1:
// 输入: [7,1,5,3,6,4]
// 输出: 7
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//       随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2zsx1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 感觉并不是正确答案的解:
// int maxProfit(int* prices, int pricesSize){
//     int day = 0; //当前天数
//     int sum = 0;//总的利润
//     if(pricesSize == 0) return 0;
//     while(day < pricesSize - 1)
//     {
//         if(prices[day]<prices[day + 1]) //明天的价格比今天的高 那么买入 
//         //会不会同时参与多笔交易？
//         //会的,例如 1234 时 第一天 1<2 买入 下式已经计算出利润并相加了(相当于提前卖出) 第二天 2 < 3 还是买入 下式也计算出利润了相当于卖出了 那么第二天真的要算的话 即买入有卖出了
//         //但是巧的是 并不会影响答案 因为这样的递增 和 最终首尾相减的值的相等的
//         {
//             sum = sum +(prices[day + 1] - prices[day]);
//         }
//         day ++;
//     }
//     return sum;
// }

// 题目2 - 存在重复元素
// 给定一个整数数组，判断是否存在重复元素。
// 如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

// 示例 1:
// 输入: [1,2,3,1]
// 输出: true
// 示例 2:
// 输入: [1,2,3,4]
// 输出: false
// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x248f5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// 1.先排序 再找相同的; 
// int cmp_int(const void *e1,const void *e2)
// {
//     return (*(int *)e1 - *(int *)e2);
// }

// bool containsDuplicate(int* nums, int numsSize){
//     qsort(nums,numsSize,sizeof(int),cmp_int); //先排序
//     int i = 1;
//     for ( i = 1; i < numsSize ; i++) //为了防止越界 所以选择i=1起始
//     {
//         if(nums[i -1] == nums[i])
//             return true;
//     }
//     return false;
// }

