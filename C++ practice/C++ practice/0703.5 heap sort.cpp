#include "stdafx.h"

#define SIZE 10000000
int iArr[SIZE];

void heapSort(int *arr, int size);
void heapify(int *arr, int node, int size);
void topdown(int *arr, int node, int size);
void printTree(int *arr, int node, int size);

void heapify2(int arr[], int n, int i);
void heapSort2(int arr[], int n);

int main()
{
	randomArr(iArr, SIZE, 1, SIZE);
	//printArr(iArr, SIZE); cout << endl;
	Stopwatch watch;
	int test[] = { 3,10,2,10,3,8,3,3,10,1 };
	//watch.start();
	//heapSort(iArr, SIZE);
	//watch.stop();

	watch.start();
	heapSort2(iArr, SIZE - 1);
	watch.stop();

	//printArr(iArr, SIZE);
	cout << watch.getElapsedTime() << "ms" << endl;
}

void heapSort(int * arr, int size)
{
	heapify(arr, 0, size);
	
	int nTemp;
	for (size_t i = 0; i < size ; i++)
	{
		SWAP(arr[0], arr[size - 1 - i], nTemp);
		topdown(arr, 0, size - 1 - i);
	}
}

void heapify(int * arr, int node, int size)
{
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	if (left < size)
	{
		heapify(arr, left, size);
	}
	else
		return;
	if (right < size)
	{
		heapify(arr, right, size);
	}

	topdown(arr, node, size);
}

void topdown(int * arr, int node, int size)
{
	int copyNode = node;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	int temp;
	while (1)
	{
		if (left >= size)
			break;
		
		bool isleft;
		if (right >= size)
			isleft = true;
		else
			isleft = (arr[left] > arr[right]);

		int & ref = isleft ? arr[left] : arr[right];
		
		if (arr[copyNode] < ref)
		{
			SWAP(arr[copyNode], ref, temp);

			if (isleft)
				copyNode = left;
			else
				copyNode = right;

			left = copyNode * 2 + 1;
			right = copyNode * 2 + 2;
		}
		else
			break;
	}
}


void printTree(int *arr, int node, int size)
{
	static int count = 0;
	
	int i = 0;
	while (i != pow(2, count) && node + i < size)
	{
		for (int j = 0; j < size / (count + 1)-1; j++)
			cout << " ";
		cout << arr[node + i];
		if(i%2 == 0)
			for (int j = 0; j < size / (count + 1)-1; j++)
				cout << " ";
		i++;
	}
	cout << endl << endl;
	count++;
	int left = node * 2 + 1;
	if(left < size)
		printTree(arr, left, size);
	else
		count = 0;
}

void heapify2(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int temp;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		SWAP(arr[i], arr[largest], temp);
		heapify2(arr, n, largest);
	}
}

void heapSort2(int arr[], int n)
{
	for (int i = n; i >= 0; i--)
		heapify2(arr, n, i);
	int temp;
	for (int i = n; i > 0; i--)
	{
		SWAP(arr[0], arr[i], temp);
		heapify2(arr, i, 0);
	}
}