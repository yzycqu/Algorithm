#include "stdio.h"
#include "stdlib.h" 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node* LinkList;

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L))
		return ERROR;
	(*L)->next = NULL;

	return OK;
}

Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

Status ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while(p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}

	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

int main()
{
	int j;
	LinkList L;
	InitList(&L);
	for (j = 1; j <=5; j++)
		ListInsert(L, 1, j);
	ListTraverse(L);

	return 0;
}