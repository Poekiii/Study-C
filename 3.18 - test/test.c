/*-------------------------数组类----------------------------*/
// 题目 1 -旋转图像
// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

// 示例 1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[7,4,1],[8,5,2],[9,6,3]]

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnhhkv/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 其实本质就是找规律
// [1 2] --> [3 4] -->[3 1]    //即先上下翻转 再对角线反转
// [3 4] --> [1 2] -->[4 2]
// void swap(int *e1, int *e2)
// {
//     int tmp = *e1;
//     *e1 = *e2;
//     *e2 = tmp;
// }
// void rotate(int** matrix, int matrixSize, int* matrixColSize){
//     //先最上下行交换
//     for(int i = 0; i < matrixSize/2 ; i ++) 
//         for(int j = 0; j < matrixSize; j ++)
//         {
//             swap(&matrix[matrixSize - i - 1][j],&matrix[i][j]);
//         }
    
//     //对角线交换
//     for(int i = 0; i < matrixSize ; i++)
//         for(int j = 0; j < i ; j++)
//         {
//             swap(&matrix[i][j],&matrix[j][i]);
//         }
// }

/*-------------------------C 经典题目----------------------------*/
//【程序 14】将一个正整数分解质因数。
// 题目：将一个正整数分解质因数。例如：输入 90,打印出 90=2*3*3*5。
/* zheng int is divided yinshu*/ 
#include "stdio.h" 
int main() 
{ 
    int n,i; 
    printf("please input a number:\n"); 
    scanf("%d",&n); 
    printf("%d=",n); 
    for(i=2;i<=n;i++) 
    while(n!=i) 
    { 
        if(n%i==0) 
        { 
            printf("%d*",i); 
            n=n/i; 
        } 
        else 
        break; 
    }  
    printf("%d",n);
    return 0;
} 