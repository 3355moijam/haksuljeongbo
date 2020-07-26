#pragma once
#include "stdafx.h"

struct IntStack
{
	int max;
	int ptr;
	int *stk;
};

int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = new int[max]) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack *s, int x)
{
	if (s->ptr >= s->max)
		return -1; // 스택 가득참.
	else
	{
		s->stk[s->ptr++] = x;
		return 0;
	}
}

int Pop(IntStack *s, int *x)
{
	if (s->ptr <= 0)
		return -1; // 스택 비어있음.
	else
	{
		*x = s->stk[--(s->ptr)];
		return 0;
	}
}

int Peek(const IntStack *s, int *x)
{
	if (s->ptr == 0)
		return -1;
	else
	{
		*x = s->stk[s->ptr - 1];
		return 0;
	}
}

void Clear(IntStack *s)
{
	s->ptr = 0;
	memset(s->stk, 0, sizeof(int) * s->max);
}

int Capacity(const IntStack *s)
{
	return s->max;
}

int Size(const IntStack *s)
{
	return s->ptr;
}

int IsEmpty(const IntStack *s)
{
	if (s->ptr == 0)
		return 1;
	else
		return 0;
}

int IsFull(const IntStack *s)
{
	if (s->ptr == s->max)
		return 1;
	else
		return 0;
}

int Search(const IntStack *s, int x)
{
	for (int i = s->ptr - 1; i <= 0; i--)
	{
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const IntStack *s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		std::cout << s->stk[i] << endl;
	}
	std::cout << std::endl;
}

void Terminate(IntStack *s)
{
	if (s->stk != NULL)
		delete[] s->stk;
	s->max = 0;
	s->ptr = 0;
}