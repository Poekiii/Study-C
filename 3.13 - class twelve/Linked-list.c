/*-------------------顺序表和链表----------------------*/
// 1.线性表
// 定义:linear list 是n个具有相同性质的数据元素是有限序列。
// 常见线性表:顺序表、链表、栈、队列、字符串...

// 线性表在逻辑上是线性结构,也就是连续的一条直线,但是物理结构并不一定连续。
// 数据结构分成两种:
// 1.物理结构 (内存中如何存的)  -- 数组(一般储存连续) 链表(一般储存不连续)
// 2.逻辑结构 (想象出来的)  -- 数组和链表都是逻辑连续

// 数组型: 0 1 2 3 4 5 6
// 链表型: data     data
//        *next -> *next ...

// 所以线性表在物理上储存 又分为数组和链式结构性存储。

// 2.顺序表
// 顺序表是用 物理地址连续 的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。在数组上增删查改。
// 有效数据在数组中必须是连续的

// 又一般分为:
//   2.1 静态顺序表: 使用定长数组存储;
//   2.2 动态顺序表 : 使用动态开辟的数组存储;

/*-------------------数组的课后题目----------------------*/
// 题目1 - 移除元素
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

// 示例 1：
// 输入：nums = [3,2,2,3], val = 3
// 输出：2, nums = [2,2]
// 解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/remove-element
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 思路:遍历数组的所有元素 把非Val的数全部放到数组中
// int removeElement(int* nums, int numsSize, int val){
//     if(nums == NULL || numsSize ==0) return 0;
//     int count = 0;//记录非val的数的个数
//     for (int i = 0; i < numsSize; i++)
//     {
//         if(nums[i] != val)
//         {
//             nums[count] = nums[i];
//             count++; 
//         }
//     }
//     return count;
// }

//题目2 - 数组形式的整数加法
// 对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
// 给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

// 示例 1：
// 输入：A = [1,2,0,0], K = 34
// 输出：[1,2,3,4]
// 解释：1200 + 34 = 1234

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//     int Ksize = 0;//K的位数
//     int Knum = K;
//     while(Knum)
//     {
//         ++Ksize;
//         Knum /= 10;
//     }
//     *returnSize = 0;
//     int len = ASize > Ksize? ASize : Ksize; //最终数组的长度取K和A中的最大数+1或者不加
//     int * ret = (int *)malloc(sizeof(int)*(len+1));
//     int CY = 0;//进位标志
//     int Ai = ASize - 1;
//     int reti = 0;
//     while(len--)  //len-- 走len次; --len走len-1次
//     {
//         int a = 0;
//         if(Ai >= 0)
//         {
//             a = A[Ai];
//             Ai--;
//         }
//         int rettmp = a + (K%10) + CY;
//         K /= 10;
//         if(rettmp > 9)
//         {
//             rettmp -= 10;
//             CY = 1;
//         }
//         else
//         {
//             CY = 0;
//         }
//         ret[reti] = rettmp;
//         ++reti;
//     }
//     if(CY) 
//     {
//         ret[reti] = 1;
//         ++reti;
//     }
//     int left = 0, right = reti - 1;
//     while(left < right)
//     {
//         int tmp = ret[left];
//         ret[left] = ret[right];
//         ret[right] = tmp;
//         left++;
//         right--;    
//     }
//     *returnSize = reti;
//     return ret;
// }