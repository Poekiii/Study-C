/*-------------------数组类----------------------*/
// 题目1 - 加一
// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 示例 1：
// 输入：digits = [1,2,3]
// 输出：[1,2,4]
// 解释：输入数组表示数字 123。
// 示例 2：
// 输入：digits = [9,9]
// 输出：[1,0,0]
// 解释：输入数组表示数字 100。
// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2cv1c/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 思路类似于制作一个十进制的加法器
// #include <string.h>
// int* plusOne(int* digits, int digitsSize, int* returnSize){
//     int *ret = (int *)malloc((digitsSize + 1)*sizeof(int));
//     int CY = 0;//进位标志
//     if(digitsSize == 1) 
//     {
//         digits[0]++;
//         if(digits[0] == 10)
//         {
//             ret[0]=1;
//             ret[1]=0;
//             *returnSize = 2;
//             return ret;
//         }
//         else
//         {
//             *returnSize = 1;
//             return digits;
//         }
//     }
//     *returnSize = 0;
//     digits[digitsSize - 1]++;    
//     for (int i = digitsSize - 1; i >= 0; i--)
//     {
//         if((digits[i] + CY) == 10)
//         {
//             digits[i] = 0;
//             CY = 1;
//         }else
//         {
//             digits[i] += CY;
//             CY = 0;
//         }
//     }
//     if(CY)
//     {
//         memcpy(ret+1,digits,sizeof(digits));
//         ret[0]= 1;
//         *returnSize = digitsSize + 1;
//         return ret;
//     }
//     else{
//         *returnSize = digitsSize;
//         return digits;
//     }
// }

// 题目2 - 移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 示例:
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2ba4i/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 双指针法  
// 遍历数组，把所有非0数字排到头上，后面全部排0即可
// void moveZeroes(int* nums, int numsSize)
// {
//     if (numsSize <= 1)
//             return;
//         int front = 0;
//         for (int tail = 0; tail < numsSize; ++tail) 
//         {
//             if (nums[tail] != 0) 
//             {
//                 nums[front] = nums[tail];
//                 front++;
//             }
//         }
//         while (front < numsSize) 
//         {
//             nums[front] = 0;
//             front++;
//         }     
// }