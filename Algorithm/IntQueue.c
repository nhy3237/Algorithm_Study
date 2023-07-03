#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

// 큐 초기화
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

// 큐에 데이터를 인큐
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

// 큐에서 데이터를 디큐
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

// 큐에서 데이터를 피크
int Peek(const IntQueue* q, int* x)
{
	if (q->num == 0)
	{
		return -1;
	}
	*x = q->que[q->front];
	return 0;
}

// 모든 데이터 삭제
void Clear(IntQueue* q)
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}

// 큐의 최대 용량
int Capacity(const IntQueue* q)
{
	return q->max;
}

// 큐에 저장된 데이터 개수
int Size(const IntQueue* q)
{
	return q->num;
}

// 큐가 비어 있는가?
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

// 큐가 가득 찼는가?
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

// 큐에서 검색
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

// 모든 데이터 출력
void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; i++)
	{
		printf("%d ", q->que[(q->front + i) % q->max]);
	}
	printf("\n");
}

// 큐 종료
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