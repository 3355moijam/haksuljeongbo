#include "stdafx.h"
#define SIZE 100000
int arr[SIZE];
int arr2[SIZE];
void shellSort(int *arr, int size);
void shellSort2(int *arr, int size);
void shell(int * arr, int size);
int main()
{
	randomArr(arr, SIZE, 1, SIZE);
	memcpy(arr2, arr, SIZE * sizeof(int));
	//printArr(arr, SIZE);
	Stopwatch watch;
	//watch.start();
	//shell(arr, SIZE);
	//watch.stop();
	//cout << watch.getElapsedTime() << "ms" << endl;
	
	watch.start();
	shellSort(arr, SIZE);
	watch.stop();
	//printArr(arr, SIZE);
	cout << watch.getElapsedTime() << "ms" << endl;

	watch.start();
	shellSort2(arr2, SIZE);
	watch.stop();
	//printArr(arr, SIZE);
	cout << watch.getElapsedTime() << "ms" << endl;
}

void shellSort(int *arr, int size)
{
	int cut = 1;
	do
	{
		cut = cut * 3 + 1;
	} while (cut < size / 9);

	int temp;
	for (int h = cut; h > 0; h = (h-1)/3)
	{
		for (int i = 1; i < size / h; i++)
		{
			for (int j = 0; j < h; j++)
			{
				for (int k = (i * h); k > 0; k-=h)
				{
					if (arr[j + k] < arr[j + k - h])
					{
						SWAP(arr[j + k], arr[j + k - h], temp)
					}
					else
						break;
					//printArr(arr, size);
				}
			}

		}
		//cout << "h : " << h << endl;
		//printArr(arr, size);
	}
}

void shell(int * arr, int size)
{
	int i, j, h;
	for (h = 1; h < size / 9; h = h * 3 + 1)
	{
		
	}
	for (; h > 0; h /= 3)
	{
		//cout << "h : " << h << endl;
		for (i = h; i < size; i++)
		{
			int tmp = arr[i];
			for (j = i - h; j >= 0 && arr[j] > tmp; j -= h)
				arr[j + h] = arr[j];
			arr[j + h] = tmp;
			//printArr(arr, size);
		}
	}
}


void shellSort2(int *arr, int size)
{
	int cut = 1;
	do
	{
		cut = cut * 3 + 1;
	} while (cut < size / 9);

	int temp;
	for (int h = cut; h > 0; h = (h - 1) / 3)
	{
		for (int i = 1; i < size / h; i++)
		{
			for (int j = (i+1)*h -1; j >= h; j--)
			{
				if (arr[j] < arr[j - h])
				{
					SWAP(arr[j], arr[j - h], temp);
				}
			}

		}
		//cout << "h : " << h << endl;
		//printArr(arr, size);
	}
}