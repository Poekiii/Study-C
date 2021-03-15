/*  修改别人写的链表代码  -- 并且发现了Scanf %c 的问题(以前不知道的)  */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node//------------------结构体链表
{
	int data;
	struct Node* next;

}Node;
Node* Append(Node* head)//------------------创建节点
{
	Node* p = NULL, *pr = head;
	int data;
    //添加一个结点
	p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("内存不足\n");
		exit(0);
	}
    printf("输入数据\n");
	scanf("%d", &data);
	p->data = data;
	p->next = NULL;
    
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	return head;
}
void DeleMemory(Node* head)//--------------释放动态内存
{
	Node* p=head, *pr = NULL;
	while (p != NULL)
	{
		pr = p;
		p = p-> next;
		free(pr);
	}
}
void LLPrint(Node *phead)
{
    Node *cur = phead; //当前位置
    while(cur != NULL) //当cur指向NULL时 说明已经遍历完成了 因为最后一个节点指向的下一个元素地址是NULL
    {
        printf("%d->", cur->data);
        cur = cur->next;//cur会到NULL的位置
    }
    printf("NULL\n");
}

int main()
{
	char c;
	Node* head=NULL;//链表头指针
	printf("是否要添加链表\n");
	scanf("%s", &c);
	while(c == 'Y')
	{
		head = Append(head);//向以head为头指针的链表末尾添加节点
        LLPrint(head);
        printf("是否要添加链表\n");
	    scanf("%s", &c);
	}
	DeleMemory(head);
    return 0;
}