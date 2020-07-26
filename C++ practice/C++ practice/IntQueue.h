#pragma once
#include "stdafx.h"

struct StringQueue
{
	int max;
	int num;
	int front;
	int rear;
	int *que;
};

int IsEmpty(const StringQueue *q);
int IsFull(const StringQueue *q);

int Initialize(StringQueue *q, int max)
{
	q->max = max;
	q->num = 0;
	q->front = 0;
	q->rear = 0;
	q->que = new int[max];
	if (q->que == NULL)
	{
		q->max = 0;
		return -1;
	}
	return 0;
}

int Enque(StringQueue *q, int x)
{
	if (IsFull(q))
		return -1;

	q->que[q->rear] = x;
	q->rear = (q->rear + 1) % q->max;
	q->num++;
	return 0;
}

int Deque(StringQueue *q, int *x)
{
	if (IsEmpty(q))
		return -1;
	*x = q->que[q->front];
	q->front = (q->front + 1) % q->max;
	q->num--;
	return 0;
}

int Peek(const StringQueue *q, int *x)
{
	if (IsEmpty(q))
		return -1;
	*x = q->que[q->front];
	return 0;
}

void Clear(StringQueue *q)
{
	q->max = 0;
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}

int Capacity(const StringQueue *q)
{
	return q->max;
}

int Size(const StringQueue *q)
{
	return q->num;
}

int IsEmpty(const StringQueue *q)
{
	if (q->num == 0)
		return 1;
	else
		return 0;
}

int IsFull(const StringQueue *q)
{
	if (q->num == q->max)
		return 1;
	else
		return 0;
}

int Search(const StringQueue *q, int x)
{
	for (int i = 0; i < q->num; i++)
	{
		if (q->que[(q->front + i) % q->max] == x)
			return (q->front + i) % q->max;
	}
	return -1;
}

void Print(const StringQueue *q)
{
	for (int i = 0; i < q->num; i++)
	{
		cout << q->que[(q->front + i) % q->max] << endl;
	}
}

void Terminate(StringQueue *q)
{
	if (q->que != NULL)
		delete[] q->que;
	Clear(q);
}