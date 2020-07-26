#include "stdafx.h"

void arrReverse(int* arr);
void printArr(int* arr);
int getArrSize(int* arr);


int main()
{
	int *arr = new int[11];
	for (int i = 0; i < 11; i++)
	{
		arr[i] = i;
	}

	printArr(arr);
	arrReverse(arr);
	
	delete[] arr;
	return 0;
}

void arrReverse(int* arr)
{
	int nSize = getArrSize(arr);

	for (int i = 0; i < nSize/2; i++)
	{
		swap(arr[i], arr[nSize - 1 - i]);
		printArr(arr);
	}
}

void printArr(int* arr)
{
	int nSize = getArrSize(arr);

	for (int i = 0; i < nSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

int getArrSize(int* arr)
{
	return _msize(arr) / sizeof(arr[0]);
}
