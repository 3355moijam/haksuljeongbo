#include "stdafx.h"

template <typename T> T max5(T *arr);

int main()
{
	int iArr[] = { 15,3,4,6,5 };
	double dArr[] = { 5.2,3.1,7,4.2 , 1};

	cout << max5(iArr) << endl;
	cout << max5(dArr) << endl;

	return 0;
}

template<typename T> T max5(T *arr)
{
	T max = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

