#pragma once
#include "stdafx.h"

struct StringStack
{
	int max;
	int ptr;
	string *stk;
};

int Initialize(StringStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = new string[max]) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(StringStack *s, string x)
{
	if (s->ptr >= s->max)
		return -1; // 스택 가득참.
	else
	{
		s->stk[s->ptr++] = x;
		return 0;
	}
}

int Pop(StringStack *s, string *x)
{
	if (s->ptr <= 0)
	{
		*x = " ";
		return -1; // 스택 비어있음.
	}
	else
	{
		*x = s->stk[--(s->ptr)];
		return 0;
	}
}

int Peek(const StringStack *s, string *x)
{
	if (s->ptr == 0)
	{
		*x = " ";
		return -1;
	}
	else
	{
		*x = s->stk[s->ptr - 1];
		return 0;
	}
}

void Clear(StringStack *s)
{
	s->ptr = 0;
	memset(s->stk, 0, sizeof(string) * s->max);
}

int Capacity(const StringStack *s)
{
	return s->max;
}

int Size(const StringStack *s)
{
	return s->ptr;
}

int IsEmpty(const StringStack *s)
{
	if (s->ptr == 0)
		return 1;
	else
		return 0;
}

int IsFull(const StringStack *s)
{
	if (s->ptr == s->max)
		return 1;
	else
		return 0;
}

int Search(const StringStack *s, string x)
{
	for (int i = s->ptr - 1; i <= 0; i--)
	{
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const StringStack *s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		cout << s->stk[i] << " ";
	}
	cout << endl;
}

void Terminate(StringStack *s)
{
	if (s->stk != NULL)
		delete[] s->stk;
	s->max = 0;
	s->ptr = 0;
}