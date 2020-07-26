#include "stdafx.h"

template <typename T> T maxn(T *arr, int n);
template <> char* maxn<char*>(char** arr, int n);

int main()
{
	int iArr[] = { 15,3,58,4,6,53 };
	double dArr[] = { 15.2,3.1,7,4.2 };
	char* sArr[5] = { "hello", "world", "nozomi", "ruby", "yuuki setsuna" };

	cout << maxn(iArr, 6) << endl;
	cout << maxn(dArr, 4) << endl;
	cout << maxn(sArr, 5) << endl;

	return 0;
}

template<typename T> T maxn(T *arr, int n)
{
	if (n <= 0)
		return NULL;
	T max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}



template <> char* maxn<char*>(char** arr, int n)
{
	if (n <= 0)
		return NULL;
	char* max = arr[0];
	int maxLen = strlen(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (maxLen < strlen(arr[i]))
		{
			max = arr[i];
			maxLen = strlen(arr[i]);
		}
	}

	return max;
}
