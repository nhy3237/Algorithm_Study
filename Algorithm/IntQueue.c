#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

// ť �ʱ�ȭ
int Initialize(IntQueue* q, int max)
{
	q->front = 0;
	q->num = 0;
	q->rear = 0;

	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

// ť�� �����͸� ��ť
int Enque(IntQueue* q, int x)
{
	if (q->num == q->max)
	{
		return -1;
	}
	else
	{
		q->que[q->rear] = x;
		q->rear++;
		q->num++;
		if (q->rear == q->max)
		{
			q->rear = 0;
		}
		return 0;
	}
}

// ť���� �����͸� ��ť
int Deque(IntQueue* q, int* x)
{
	if (q->num == 0)
	{
		return -1;
	}
	*x = q->que[q->front];
	q->front++;
	q->num--;
	if (q->front == q->max)
	{
		q->front = 0;
	}
	return 0;
}

// ť���� �����͸� ��ũ
int Peek(const IntQueue* q, int* x)
{
	if (q->num == 0)
	{
		return -1;
	}
	*x = q->que[q->front];
	return 0;
}

// ��� ������ ����
void Clear(IntQueue* q)
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}

// ť�� �ִ� �뷮
int Capacity(const IntQueue* q)
{
	return q->max;
}

// ť�� ����� ������ ����
int Size(const IntQueue* q)
{
	return q->num;
}

// ť�� ��� �ִ°�?
int IsEmpty(const IntQueue* q)
{
	if (q->num == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// ť�� ���� á�°�?
int IsFull(const IntQueue* q)
{
	if (q->num == q->max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// ť���� �˻�
int Search(const IntQueue* q, int x)
{
	for (int i = 0; i < q->num; i++)
	{
		if (q->que[(q->front + i) % q->max] == x)
		{
			return (q->front + i) % q->max;
		}
	}
	return -1;
}

// ��� ������ ���
void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; i++)
	{
		printf("%d ", q->que[(q->front + i) % q->max]);
	}
	printf("\n");
}

// ť ����
void Terminate(IntQueue* q)
{
	if (q->que != NULL)
	{
		free(q->que);
	}
	q->max = 0;
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}