#include "stdafx.h"

#define SIZE 60000

void bubbleSort(int * arr);
void selectionSort(int * arr);
void printArray(int * arr);
int temp;
#define SWAP(a, b) temp = a; a = b; b = temp

int testcase[SIZE];
int testcase2[SIZE];

int main()
{
	Stopwatch watch;

	// 배열 생성
	////난수 생성
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> dis(0, SIZE); // 원하는 범위의 숫자
	////

	int icase;
	for (size_t i = 0; i < SIZE; i++)
	{
		icase = dis(gen);
		testcase[i] = icase;
	}
	memcpy(testcase2, testcase, sizeof(int) * SIZE);
	//printArray(testcase);
	//printArray(testcase2);


	//버블소트
	watch.start();
	bubbleSort(testcase);

	watch.stop();
	//printArray(testcase);
	cout << watch.getElapsedTime() << "ms 경과" << endl;

	//셀렉션소트
	watch.start();
	selectionSort(testcase2);

	watch.stop();
	//printArray(testcase2);
	cout << watch.getElapsedTime() << "ms 경과" << endl;


	return 0;
}


void bubbleSort(int * arr)
{
	int count;
	for (size_t i = 0; i < SIZE - 1; i++)
	{
		count = 0;
		for (size_t j = 0; j < SIZE - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//temp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = temp;
				SWAP(arr[j], arr[j + 1]);
				count++;
			}
		}
		if (count == 0)
			break;
	}
}


void selectionSort(int * arr)
{
	size_t index = 0;
	for (size_t i = 0; i < SIZE - 1; i++)
	{
		index = i;
		for (size_t j = i+1; j < SIZE; j++)
		{
			if (arr[index] > arr[j])
				index = j;
		}
		//temp = arr[i];
		//arr[i] = arr[index];
		//arr[index] = temp;
		SWAP(arr[i], arr[index]);
		//printArray(arr);
	}
}


void printArray(int * arr)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
