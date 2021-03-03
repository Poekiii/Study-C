#include <stdio.h>
void Swap1(int x, int y)   //形参xy与num使用不同的内存空间
{
    int tmp = 0;
    tmp = x;
    x = y;
    y = tmp;
}

void Swap2(int *px, int *py)//形参pxpy取了num的地址，*px *py是直接对地址中的内容更改，并且形参pxpy的储存也是分配了内存的(使用完成后释放)。
{
    int tmp = 0;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main()
{
    int num1 = 1;//实参
    int num2 = 2;
    Swap1(num1, num2);
    printf("Swap1::num1 = %d num2 = %d\n", num1, num2);
    Swap2(&num1, &num2); //取得的地址 px py是地址
    printf("Swap2::num1 = %d num2 = %d\n", num1, num2);
    return 0;
}
