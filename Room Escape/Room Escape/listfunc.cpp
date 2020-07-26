#include "stdafx.h"


Item dummy = { L"", L"", 4, 100, 0, 0, NULL, NULL };

void InputLast(Item *input, Item **first, Item **last)	
{	
	input->pNext = NULL;

	if (*first == NULL)
	{
		*first = input;
	}
	else
	{
		(*last)->pNext = input;
	}

	*last = input;
}

int getLen(Item *first)
{
	int leng = 0;
	Item *pIndex = first;
	
	while (pIndex != NULL)
	{
		pIndex = pIndex->pNext;
		leng++;
	}

	return leng;
}

Item* getNode(int index, Item *first)
{
	Item *tmp = first;
	if (tmp == NULL)
	{
		tmp = &dummy;
		return tmp;
	}

	if (getLen(first) < index)
	{
		tmp = &dummy;
		return tmp;
	}

	for (int i = 0; i < index-1; i++)
	{
		tmp = tmp->pNext;
	}

	return tmp;
}

int getIndex(Item *target, Item *first)
{
	Item *tmp = first;
	int index = 1;
	while(tmp != target)
	{
		tmp = tmp->pNext;
		index++;
	}

	return index;
}

Item* delNode(int index, Item **first, Item **last)
{
	Item *target = getNode(index, *first);
	Item *tmp = NULL;
	if (target == *first)
	{
		*first = target->pNext; 
		target->pNext = NULL;
	}
	else
	{
		tmp = getNode(index - 1, *first);

		tmp->pNext = target->pNext;
		target->pNext = NULL;
	
	}
	
	if (tmp == *last)
	{
		*last = tmp;
	}


	return target;
}

Item* delNode(Item *target, Item **first, Item **last)
{
	//Item *target = getNode(index, first);
	Item *tmp = NULL;
	if (target == *first)
	{
		*first = target->pNext;
		target->pNext = NULL;
	}
	else
	{
		int tarIndex = getIndex(target, *first);
		tmp = getNode(tarIndex-1, *first);

		tmp->pNext = target->pNext;
		target->pNext = NULL;

	}
	if (target == *last)
	{
		*last = tmp;
	}


	return target;
}

void listSet(Item *first)
{
	int leng = 1;
	Item *pIndex = first;
	wchar_t wszBuffer[32];
	while (pIndex != NULL)
	{
		wsprintf(wszBuffer, L"%d. %s   ", leng, pIndex->name);
		wcscat_s(g_szMenu, _WIDTH, wszBuffer);
		pIndex = pIndex->pNext;
		memset(wszBuffer, 0, sizeof(wszBuffer));
		leng++;
	}

	wcscat_s(g_szMenu, _WIDTH, L"0. 돌아가기");

	return;
}

//int searchName(Item *stu)	// 찾은 학생 인덱스 반환
//{
//	
//	Item *tmp = stu;
//	int i = 0;
//	while (tmp != NULL)
//	{
//		if (strcmp(tmp->name, sName) == 0)
//		{
//			return i;
//		}
//		i++;
//		tmp = tmp->pNext;
//	}
//	return -1;
//}