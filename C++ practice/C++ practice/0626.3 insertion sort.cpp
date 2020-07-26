#include "stdafx.h"

#define SIZE 100000
void insertionSort(int * arr);
int arr[SIZE];
int main()
{
	randomArr(arr, SIZE, 1, SIZE);
	Stopwatch watch;

	watch.start();
	insertionSort(arr);
	watch.stop();
	
	cout << watch.getElapsedTime() << "ms" << endl;
	system("pause");
	return 0;
}

void insertionSort(int * arr)
{
	int temp;
	for (size_t i = 1; i < SIZE; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				SWAP(arr[j], arr[j - 1], temp);
			}
			else
				break;
		}
	}
}