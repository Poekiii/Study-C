// #include <stdio.h>
// int main()
// {
//     //问题1：在屏幕上打印一个单引号'，怎么做？
//     //问题2：在屏幕上打印一个字符串，字符串的内容是一个双引号“，怎么做？
//     printf("%c\n", '\'');
//     printf("%s\n", "\"");
//     return 0;
// }

//代码1
//编写代码，演示多个字符从两端移动，向中间汇聚
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char arr1[] = "welcome to bit...";
//     char arr2[] = "#################";
//     int left = 0;
//     int right = strlen(arr1)-1;
//     printf("%s\n", arr2);
//     //while循环实现
//     while(left<=right)
//     {
//         arr2[left] = arr1[left];
//         arr2[right] = arr1[right];
//         left++;
//         right--;
//         printf("%s\n", arr2);
//     }
//     //for循环实现
// //  for (left=0, right=strlen(src)-1; left <= right; left++, right--)
// //    {
// //         Sleep(1000);
// //         arr2[left] = arr1[left];
// //         arr2[right] = arr1[right];
// //         printf("%s\n", target);
// //    }
//     return 0;
// }


//二分查找函数：
#include <stdio.h>
int bin_search(int arr[], int left, int right, int key)
{
    int mid = 0;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(arr[mid]>key)
        {
            right = mid-1;
        }
        else if(arr[mid] < key)
        {
            left = mid+1;
        }
        else
            return mid;//找到了，返回下标
    }
        return -1;//找不到
}
int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 11, 24, 36, 58, 99};
    int ret = bin_search(arr, 0, 9, 24);
    printf("找到了:在%d的位置\n", ret+1);
    return 0;
}
