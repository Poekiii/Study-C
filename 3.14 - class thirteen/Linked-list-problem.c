/*-------------------链表类----------------------*/
// 题目1 -删除链表中的节点
// 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为node要被删除的节点 。
// 示例 1：
// 输入：head = [4,5,1,9], node = 5
// 输出：[4,1,9]
// 解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnarn7/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 目标：杀掉A
// 正常杀手需要找到A的把柄才可以杀掉A，
// 可现在找到A本人后竟然没有可以获取A把柄的途径
// A得知我们要杀他，心生一计，可助你完成任务
// A说我有B的把柄，你杀了B，我改头换面，以B的身份活着
// GC也会自动清理掉B的尸体，没人会知道的
// 作者：桂继宏
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnarn7/?discussion=7wCHAG
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 大佬的解释真的好啊,生动形象. XD
// void deleteNode(struct ListNode* node) {
//     node->val = node->next->val;
//     node->next = node->next->next; 
// }


// 题目2 - 删除链表的倒数第N个节点
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 进阶：你能尝试使用一趟扫描实现吗？

// 示例 1：
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn2925/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 双指针法
// 快指针先走N步,之后和慢指针一起走,直到走到最后一个元素时结束;
// 此时慢指针会在要删除的结点的前面一个结点;
// 所以只需要把慢指针的结点指向下下个结点即可。
// NOTICE:该方法需要慢指针在要删除的结点的前一个结点,所以前一个结点必须存在;
// 若head = [1,2] n=2时 1的位置是没有前结点的 所以需要在前面添加一个结点;

// struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
//     struct ListNode *head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
//     head1->next = head;

//     struct ListNode *prev = head1;
//     struct ListNode *tail = head1;
//     if(head->next == NULL) return NULL;
//     while(n--) //先让快指针前进n步
//     {
//         prev=prev->next;
//     }
//     while(prev->next != NULL) //此时同时快慢指针同时前进 保证间隔n步
//     {
//         tail=tail->next;
//         prev=prev->next;
//     }
//     tail->next=tail->next->next;
//     return head1->next;
// }