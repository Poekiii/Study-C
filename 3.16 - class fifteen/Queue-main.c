#include "Queue.h"

void Test1()
{
    Queue qp;
    QueueInit(&qp);
    QueuePush(&qp, 1);
    QueuePush(&qp, 2);
    QueuePush(&qp, 3);
    QueuePrint(&qp);
    QueuePop(&qp);
    QueuePush(&qp, 4);
    QueuePrint(&qp);
    QueueDestroy(&qp);
}
int main()
{
    Test1();
    return 0;
}