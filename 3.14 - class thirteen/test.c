#include "LinkedList.h"

int main()
{
    LLNode *pList = NULL;
    LLPushBack(&pList, 1);
    LLPushBack(&pList, 2);
    LLPushBack(&pList, 3);
    LLPushFront(&pList, 0);
    
    LLPrint(pList);
    LLPopBack(&pList);
    LLPrint(pList);
    LLDestroy(pList);
    return 0;
}