//leetcode - 初级算法

/*-------------------数组类----------------------*/

// 题目1 - 删除排序数组中的重复项
// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
// 示例 1:
// 给定数组 nums = [1,1,2], 
// 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
// 你不需要考虑数组中超出新长度后面的元素。
// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2gy9m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// int removeDuplicates(int* nums, int numsSize){
//     int *cur = nums; //负责记录最后指针位置 与首位差 得到长度
//     if(numsSize==0) return 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if(*cur != *(nums + i))  // 如果找到了不相等的两个元素
//         {
//             *++cur = *(nums + i); // 把这个不等的值 赋给 当前元素的后一位
//         }
//     }
//     return cur-nums+1;
// }

/*-------------------字符串类----------------------*/
// 题目1 - 反转字符串
// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
// 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
//  
// 示例 1：
// 输入：["h","e","l","l","o"]
// 输出：["o","l","l","e","h"]
// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnhbqj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// void reverseString(char* s, int sSize){
//     char *left = s; //指向首元素
//     char *right = s+sSize-1;//指向末元素
//     while(left<right)  //当指针地址交叉时 说明完成全部交换
//     {
//         char tmp = *left;
//         *left = *right;
//         *right = tmp;
//         right--;
//         left++; 
//     }
// }

// 题目2 - 整数反转
// 给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。
// 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
// 假设环境不允许存储 64 位整数（有符号或无符号）。
//  
// 示例 1：
// 输入：x = 123
// 输出：321

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnx13t/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// #define MAX (pow(2,31) - 1)
// #define MIN (-pow(2,31))
// int reverse(int x){
//     long sum=0;//最终的结果
//     int tmp;
//     if(x==0||x==INT_MIN) return 0;
//     while(x)
//     {
//         //辗转除 10，每次都会将之前反转的值乘 10 
//         tmp = x % 10;
//         sum = sum * 10 + tmp;
//         x = x / 10;
//     }
//     if ( sum > MAX || sum < MIN)
//     {
//         return 0;
//     }
//     return (int)sum;
// }

//NOTICE: abs() 是 int abs(int a)  当超出int范围的值输入时,会报错;


// 题目3 - 实现 strStr()
// 实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:
// 输入: haystack = "hello", needle = "ll"
// 输出: 2

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnr003/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// int strStr(char * haystack, char * needle){
//     char *cur = haystack; //滑动的指针 - 指向可能出现的位置
//     char *p1 = NULL; //指向滑动指针的头
//     char *p2 = NULL; //指向needle的头
//     if (*needle == '\0'&& *haystack == '\0') return 0;
//     if (strlen(haystack)<strlen(needle)) return -1;
//     assert(haystack&&needle);
//     while(*cur)
//     {
//         p1 = cur;
//         p2 = needle;
//         while((*p1 !='\0')&&(*p2 != '\0')&& (*p1 == *p2))
//         {
//             p1++;
//             p2++;
//         }
//         if(*p2 == '\0')
//         {
//             return cur - haystack;
//         }
//         cur++;
//     }
//     return -1;
// }