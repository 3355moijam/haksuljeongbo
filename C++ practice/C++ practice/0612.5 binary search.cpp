#include "stdafx.h"

void selSort(int[], int len);
void printArr(int[], int len, int, int, int);
int biSearch(int target, int arr[], int len);

int main()
{
	cout << "��� ���ڸ� �Է��Ͻ� �ǰ���? : ";
	int aLen = 0;
	cin >> aLen;
	int *a = new int[aLen];
	for (int i = 0; i < aLen; i++)
	{
		cout << "���ڸ� �Է����ּ���. " << i+1 << ". : ";
		cin >> a[i];
	}

	selSort(a, aLen);

	cout << "� ���ڸ� ã�����? :";
	int tar = 0;
	cin >> tar;

	if (biSearch(tar, a, aLen) == -1)
		cout << "�߰����� ���߽��ϴ�." << endl;

	delete[] a;

	return 0;
}

// return index
int biSearch(int target, int arr[], int len)
{
	int start = 0, end = len-1;
	int index = (start + end) / 2;
	

	while (arr[index] != target)
	{
		printArr(arr, len, start, index, end);
		if (target < arr[index])
		{
			end = index - 1;
			index = (start + end) / 2;
		}
		else
		{
			start = index + 1;
			index = (start + end) / 2;
		}

		if (start > end)
			return -1;
	}
	printArr(arr, len, start, index, end);

	return index; 
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
		swap(arr[i],arr[index]);
	}
}

void printArr(int arr[], int len, int start, int index, int end)
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