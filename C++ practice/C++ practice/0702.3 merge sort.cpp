#include "stdafx.h"

#define SIZE 100000
int arr[SIZE];
int tempArr[SIZE];

void mergeSort(int *arr, int start, int end);

int main()
{
	randomArr(arr, SIZE, 1, SIZE);

	Stopwatch watch;

	watch.start();
	mergeSort(arr, 0, SIZE);
	watch.stop();

	printArr(arr, SIZE);
	cout << watch.getElapsedTime() << "ms" << endl;
}

void mergeSort(int * arr, int start, int end)
{
	int middle = (start + end) / 2;
	int temp;
	if (end - start <= 1)
		return;
	else if (end - start == 2)
	{
		if (arr[start] > arr[start + 1])
		{
			SWAP(arr[start], arr[start + 1], temp);
		}
	}
	else
	{
	
		mergeSort(arr, start, middle);
		mergeSort(arr, middle, end);

		int length = end - start;
		int sIdx = start;
		int eIdx = middle;
		for (int i = 0; i < length; i++)
		{
			if (sIdx >= middle)
			{
				memcpy(&tempArr[i], &arr[eIdx], sizeof(int) * (end - eIdx));
				break;
			}
			else if (eIdx >= end)
			{
				memcpy(&tempArr[i], &arr[sIdx], sizeof(int) * (middle - sIdx));
				break;
			}
			else
			{
				if (arr[sIdx] < arr[eIdx])
				{
					tempArr[i] = arr[sIdx++];
				}
				else
				{
					tempArr[i] = arr[eIdx++];
				}
			}
		}
		memcpy(&arr[start], tempArr, sizeof(int)*length);
	}
}
