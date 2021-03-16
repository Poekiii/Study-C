#include "Stack.h"

void Test1()
{
    Stack st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackShow(&st);
    StackPop(&st);
    StackPop(&st);
    StackShow(&st);
    StackPush(&st, 3);
    StackPush(&st, 2);
    StackShow(&st);
    int a = StackFind(&st, 3);
    printf("位置在:%d\n", a);
    StackFree(&st);
}
int main()
{
    Test1();
    return 0;
}