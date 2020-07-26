#include "stdafx.h"

void selSort(int[], int len);
void printArr(int*, int len, int, int, int);
void* bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));
int intcmp(const void *, const void *);

int main()
{
	cout << "몇개의 숫자를 입력하실 건가요? : ";
	int aLen = 0;
	cin >> aLen;
	int *a = new int[aLen];
	for (int i = 0; i < aLen; i++)
	{
		cout << "숫자를 입력해주세요. " << i + 1 << ". : ";
		cin >> a[i];
	}

	selSort(a, aLen);

	cout << "어떤 숫자를 찾을까요? :";
	int target = 0;
	cin >> target;

	if(bsearchx(&target, a, aLen, sizeof(int), intcmp) == NULL)
		cout << "발견하지 못했습니다." << endl;

	delete[] a;

	return 0;
}

// return index pointer
void* bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	int start = 0, end = nmemb - 1;
	int index = (start + end) / 2;
	
	char* cTmp = (char*)base;
	
	while (int i = compar(key, cTmp + (index * size)))
	{
		printArr((int*)base, nmemb, start, index, end);
		if (i < 0)
			end = index - 1;
		else
			start = index + 1;

		index = (start + end) / 2;

		if (start > end)
			return NULL;
	}
	printArr((int*)base, nmemb, start, index, end);

	while (index != 0)
	{
		if (compar(key, cTmp + ((index - 1) * size)) == 0)
			index--;
		else
			break;
	}

	printArr((int*)base, nmemb, start, index, end);

	return cTmp + (index * size);
}

void selSort(int arr[], int len)
{
	int index = 0;
	for (int i = 0; i < len - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}
		swap(arr[i], arr[index]);
	}
}

void printArr(int *arr, int len, int start, int index, int end)
{
	for (int i = 0; i < len; i++)
	{
		if (i == start)
			cout << "<";

		cout << arr[i];

		if (i == index)
			cout << "V";

		if (i == end)
			cout << ">";

		cout << " ";
	}
	cout << endl;
}


int intcmp(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b)
	{
		return 1;
	}
	else if (*(int*)a < *(int*)b)
	{
		return -1;
	}
	else
		return 0;
}