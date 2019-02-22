#include "pch.h"
#include <iostream>
typedef int ElemType;
typedef struct LNode {
	ElemType value;
	struct LNode * next;
}LNode, *LinkList;

//LinkList onCreate(LinkList L)
//{
//	LNode * node = NULL;
//	int x;
//	scanf_s("%d", &x);
//	if (L == NULL)
//	{
//		L = (LinkList)malloc(sizeof(LinkList));
//		L->next = NULL;
//	}
//	while (x != 9999)
//	{
//		node = (LNode *)malloc(sizeof(LNode));
//		node->value = x;
//		node->next = L->next;
//
//		L->next = node;
//		scanf_s("%d", &x);
//	}
//	return L;
//}

LinkList insertOnHead(LinkList L)
{
	//注意第一个为空
	if (L == NULL)
	{
		L = (LinkList)malloc(sizeof(LinkList));
		L->next = NULL;
	}
	int x;
	scanf_s("%d", &x);
	while (x != 999)//输入999停止输入
	{
		LinkList p = (LinkList)malloc(sizeof(LinkList));
		p->value = x;
		p->next = L->next;
		L->next = p;
		scanf_s("%d", &x);
	}
	return L;
}
void showLinkList(LinkList head)
{
	LinkList p = NULL;
	p = head; 
	if (head == NULL)
	{
		printf("head is NULL\n");
	}
	while (p=p->next)
	{
		printf("%d\t", p->value);
	}
}

int main()
{
	LinkList head = NULL;
	head = insertOnHead(head);
	showLinkList(head);
}