#include "stdafx.h"
#include <memory>

#define SIZE 10000000

int getMax(int *arr, int size);
void countSort(int *arr, int size);

int iArr[SIZE];

int main()
{
	randomArr(iArr, SIZE, 0, SIZE);
	//printArr(iArr, SIZE);

	Stopwatch watch;
	
	watch.start();
	countSort(iArr, SIZE);
	watch.stop();

	//printArr(iArr, SIZE);
	cout << watch.getElapsedTime() << "ms" << endl;
}

int getMax(int * arr, int size)
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

void countSort(int * arr, int size)
{
	int maxNum = getMax(arr, size);
	unique_ptr<int[]> tempArr(new int[maxNum+1]());
	
	for (int i = 0; i < size; i++)
	{
		tempArr[arr[i]]++;
	}
	memset(arr, 0, sizeof(int) * size);

	int index = 0;
	for (int i = 0; i < maxNum+1; i++)
	{
		for (int j = 0; j < tempArr[i]; j++)
		{
			arr[index] = i;
			index++;
		}
	}
}
