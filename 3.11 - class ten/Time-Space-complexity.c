#include <stdio.h>
/*-----------------------------------数据结构篇-------------------------------------------*/
//1.BubbleSort的时间复杂度
// void BubbleSort(int *a, int n)
// {
//     assert(a);
//     for (int end = n; end >0; --end)
//     {
//         int exchange = 0;
//         for (int j = 0; j < n - 1; j++)
//         {
//             if(a[j - 1]> a[j])
//             {
//                 Swap(&a[i - 1], &a[i]);
//                 exchange = 1;
//             }
//         }
//         if(exchange == 0)
//             break;
//     }
// }

int main()
{
   // int a[10] = {0};
    for (int end = 10; end > 0; --end)
    {
        printf("%d\n", end);
    }
    return 0;
}