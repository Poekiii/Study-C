/*-------------------数组类----------------------*/
// 题目1 - 只出现一次的数字
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 示例 1:
// 输入: [2,2,1]
// 输出: 1

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x21ib6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//例如异或的性质 a^a=0 a^0=a
// int singleNumber(int* nums, int numsSize){
//     int ret = nums[0];
//     for (int i = 0; i < numsSize-1; i++)
//     {
//         ret = ret ^ nums[ i+1 ]; 
//     }
//     return ret;
// }

// 题目2 - 两个数组的交集 II
// 给定两个数组，编写一个函数来计算它们的交集。

// 示例 1：
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2,2]

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2y0c2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 双指针法 - (快慢指针)
// 首先对两个数组进行排序，然后使用两个指针遍历两个数组。
// 初始时，两个指针分别指向两个数组的头部。
// 每次比较两个指针指向的两个数组中的数字，如果两个数字不相等，则将指向较小数字的指针右移一位，
// 如果两个数字相等，将该数字添加到答案，并将两个指针都右移一位。当至少有一个指针超出数组范围时，遍历结束。

// int cmp_int(const void *e1, const void *e2)
// {
//     int *a = e1, *b = (int*)e2;
//     return *a == *b ? 0 : *a > *b ? 1:-1;//两个值相等返回1 int最小值-2147483648 这里不用相减而是直接比大小 所以不会溢出 
//     // 上述的算法 解决了e1中的值溢出问题

//     // return *(int *)e1 - *(int *)e2;
//     // NOTICE: 用以上代码会出现runtime error: signed integer overflow -2147483648 - 1 cannot be represented in type 'int'
//     // 因为当数组中的值一个为-2147483648 一个为1 时 相减 int 溢出了
// }
// #define MIN(x,y) ((x)<(y)?(x):(y)) //取小值的宏
// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
//     if(nums1== NULL || nums2 == NULL) return 0;
//     qsort(nums1,nums1Size,sizeof(int),cmp_int);
//     qsort(nums2,nums2Size,sizeof(int),cmp_int);
//     int *ret = (int *)malloc(MIN(nums1Size,nums2Size)*sizeof(int));
//     int i = 0;
//     int j = 0;
//     *returnSize = 0;
//     while((i<nums1Size)&&(j<nums2Size))
//     {
//         if(nums1[i]==nums2[j])
//         {
//             ret[(*returnSize)++] = nums1[i];
//             i++;
//             j++;
//         }else if(nums1[i]>nums2[j])
//         {
//             j++;
//         }else
//         {
//             i++;
//         }
//     }
//     return ret;
// }