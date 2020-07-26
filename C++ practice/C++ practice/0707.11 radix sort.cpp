#include "stdafx.h"
#include <queue>

#define digits 4
#define SIZE 100000

int iArr[SIZE];
queue<int> qArr[10];

void radixSort(int * arr, int length, int digit);

int main()
{
	randomArr(iArr, SIZE, pow(10, digits), pow(10, digits+1) - 1);
	//printArr(iArr, SIZE);
	//int temp[SIZE] = { 23483, 61159, 20906, 17241, 96173, 34746, 92643, 64102, 91092, 20566, 38311, 94301, 78204, 96983, 91118, 47599, 85291, 68245, 35994, 78892 };
	//printArr(temp, SIZE);
	Stopwatch watch;

	watch.start();
	radixSort(iArr, SIZE, digits);
	watch.stop();

	//printArr(iArr, SIZE);
	cout << watch.getElapsedTime() << "ms" << endl;
}



void radixSort(int * arr, int length, int digit)
{
	int nowDigit = 0;
	while (nowDigit <= digit)
	{
		for (int i = 0; i < length; i++)
		{
			string temp = to_string(arr[i]);
			int num = temp[digit - nowDigit] - '0';

			qArr[num].push(arr[i]);
		}

		int index = 0;
		for (int i = 0; i < length; i++)
		{
			while(qArr[index].empty())
				index++;
			arr[i] = qArr[index].front();
			qArr[index].pop();
		}
		//printArr(arr, SIZE);
		nowDigit++;
	}
	
}
