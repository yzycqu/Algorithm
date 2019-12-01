#include "stdio.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

int ListLength(SqList L)
{
	return L.length;
}

int LocateElem(SqList L, ElemType e)
{
	int i;

	if (L.length == 0)
		return 0;

	for (i = 0; i < L.length; i++)
	{
	    if (L.data[i] == e)
		break;
	}

	if (i >= L.length)
		return 0;

	return i + 1;
}

Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;

	if(L->length == MAXSIZE)
		return ERROR;
	if(i < 1 || i > L->length + 1)
		return ERROR;
	if(i <= L->length)
	{
	    for(k = L->length - 1; k >= i - 1; k--)
		L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;

	if (L->length == 0)
		return ERROR;
	if (i < 1 || i > L->length)
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)
	{
	    for (k = i; k < L->length; k++)
		L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

Status ListTraverse(SqList L)
{
	int i;

	for (i = 0; i < L.length; i++)
	    visit(L.data[i]);

	printf("\n");

	return OK;
}

int main()
{
    SqList L;
    ElemType e;
    int i;

    InitList(&L);
    printf("After Init, L.length = %d\n", L.length);
    for (i = 1; i <= 5; i++)
	ListInsert(&L, 1, i);
    printf("After Insert 1~5, L.length= %d\n", L.length);
    ListTraverse(L);

    ListInsert(&L, 3, 8);
    ListTraverse(L);

    ListDelete(&L, 2, &e);
    ListTraverse(L);

    return 0;
}
