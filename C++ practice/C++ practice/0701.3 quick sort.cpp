//#include "stdafx.h"
//#include <thread>
//#include <mutex>
//
//#define SIZE 10000000
//int arr[SIZE];
//mutex mt;
//void quickSort(int *arr, int start, int end);
//
//int main()
//{
//	randomArr(arr, SIZE, 1, SIZE);
//
//	Stopwatch watch;
//
//	watch.start();
//	quickSort(arr, 0, SIZE-1);
//	watch.stop();
//	//printArr(arr, SIZE);
//	cout << watch.getElapsedTime() << "ms" << endl;
//
//}
//
//void quickSort(int *arr, int start, int end)
//{
//	int pivot = (start + end) / 2;
//	int sIdx = start, eIdx = end, temp;
//	if (start >= end)
//		return;
//	else
//	{
//		while (sIdx != eIdx)
//		{
//			if (arr[sIdx] >= arr[pivot] && arr[pivot] >= arr[eIdx])
//			{
//				
//				SWAP(arr[sIdx], arr[eIdx], temp);
//				
//				if (sIdx == pivot)
//					pivot = eIdx;
//				else if (eIdx == pivot)
//					pivot = sIdx;
//				sIdx++; eIdx--;
//			}
//			else
//			{
//				if (arr[sIdx] <= arr[pivot])
//					sIdx++;
//				if (arr[pivot] <= arr[eIdx])
//					eIdx--;
//			}
//
//			if (sIdx > pivot)
//				sIdx = pivot;
//			if (pivot > eIdx)
//				eIdx = pivot;
//		}
//		//printArr(arr, SIZE);
//		quickSort(arr, start, pivot - 1);
//		quickSort(arr, pivot + 1, end);
//	}
//}
//
//
