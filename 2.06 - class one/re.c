#include <stdio.h>

void print_ss(int n)
{
    if(n>9)
    {
        print_ss(n/10);
    }
    printf("%d ", n % 10);
}
int main()
{
    int num = 1234;
    print_ss(num);
    return 0;
}