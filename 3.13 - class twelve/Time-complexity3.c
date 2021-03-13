/*-------------------数组类----------------------*/

// 面试题 - 消失的数字
// 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

// 注意：本题相对书上原题稍作改动
// 示例 1：
// 输入：[3,0,1]
// 输出：2

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/missing-number-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 1.利用异或的性质 a^0=a; a^a=0; a^b^b=a^0=a; a^b=c-->c^b=a;
// int missingNumber(int* nums, int numsSize){
//     int tmp = 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         tmp ^= nums[i]^i;
//     }
//     tmp = numsSize^tmp;
//     return tmp;
// }
// 其他方法大于O(N)的方法: 先排序 1.在for循环与数组比较 2.二分法等等...


