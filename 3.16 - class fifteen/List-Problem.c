/*-------------------------链表类----------------------------*/
// 题目 1 - 反转链表
// 反转一个单链表。
// 示例:
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnnhm6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 迭代法 - 尾递归法 使得每个结点的指向倒置
// struct ListNode* reverseList(struct ListNode* head){
//     struct ListNode* fast = head;
//     struct ListNode* slow = NULL;
//     struct ListNode* next = NULL;
//     while(fast)
//     {
//         next = fast->next;
//         fast->next = slow;
//         slow = fast;
//         fast = next;
//     }
//     return slow;
// }

// 原链表 (^x  表示指向x)
// | 1 | ^2 |->| 2 | ^3 |->| 3 | ^NULL |
// 定义: 
// fast->1;
// slow->NULL;
// next->NULL;(next指的是fast要到的下一个位置)

// 第一次判断 fast!=NULL
// next先指向fast(即1)->next(即2) //先到下一个位置 若是先倒置的话 找不到下一个位置了
// 把fast(1)的当前结点的next指向slow(NULL)
// 让slow(NULL)转到fast(1)
// 让fast(1)转到next(2)
// 此时
// | 1 | ^NULL |->| 2 | ^3 |->| 3 | ^NULL |
// fast->2;
// slow->1;
// next->2;

// 第二次判断 fast!=NULL
// next先指向fast(2)->next(3) 
// 把fast(2)的当前结点的next指向slow(1)
// 让slow(1)转到fast(2)
// 让fast(2)转到next(3)
// 此时
// | 1 | ^NULL |->| 2 | ^1 |->| 3 | ^NULL |
// fast->3;
// slow->2;
// next->3;

// 第三次判断 fast!=NULL
// next先指向fast(3)->next(NULL) 
// 把fast(3)的当前结点的next指向slow(2)
// 让slow(2)转到fast(3)
// 让fast(3)转到next(NULL)
// 此时
// | 1 | ^NULL |->| 2 | ^1 |->| 3 | ^2 |
// fast->NULL;
// slow->3;
// next->NULL;

// 第四次判断 fast==NULL
// 退出循环
// 并且返回slow作为起始位置head

// 此时在从slow开始打印 
// 那么 3->2->1->NULL 
// 完成反转

/*-------------------------数组类----------------------------*/
// 题目1 -两数之和
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
// 你可以按任意顺序返回答案。

// 示例 1：
// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2jrse/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 暴力枚举法
// int* twoSum(int* nums, int numsSize, int target, int* returnSize){
//     int *ret = (int *)malloc(sizeof(int)*2);
//     *returnSize = 0;
//     for(int i = 0; i < numsSize; i++)
//         for(int j = i + 1;j < numsSize; j++)
//             if(nums[i]+nums[j] == target)
//             {
//                 ret[0]=i;
//                 ret[1]=j;
//                 *returnSize = 2;
//                 return ret;
//             }
//     return 0;
// }
