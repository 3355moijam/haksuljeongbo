#include "stdafx.h"

void makeCase(int *src, int size);
int checkRoot(int *src, int size);
int coreCombine(int *src, int size);
int* getInput(int &length);

int main()
{

	int length = 2;
	int *src = getInput(length);
	
	makeCase(src, length);
	printArr(src, length);

	int count = coreCombine(src, length);
	int check = checkRoot(src, length);
	
	if (check == 1)
	{
		cout << "루트: ";
		printArr(src, length);
		cout << count << "시간 경과" << endl;
	}
	else
	{
		cout << "루트가 존재하지 않음." << endl;
		printArr(src, length);
	}

	delete[] src;

	return 0;
}

int coreCombine(int *src, int size)
{
	int count = 0;
	while (checkRoot(src, size) == 0)
	{
		bool check = true;
		for (int i = 0; i < size; i++)
		{
			for (int j = i * 2 + 1; j < size; j += i + 1)
			{
				if(src[i] != 0)
					check = false;
				src[j] -= src[i];
			}
		}
		if (check)
			break;
		count++;
	}
	

	return count;
}

void makeCase(int * src, int size)
{
	if (!checkRoot(src, size))
		return;

	for (int k = 0; k < 5; k++)
	{
		int *temp = new int[size]();
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j += i + 1)
			{
				temp[j] += src[i];
			}
		}
		memcpy(src, temp, size * sizeof(int));
		delete[] temp;
	}
}

int checkRoot(int *src, int size)
{
	int check = 1;
	for (int i = 0; i < size; i++)
	{
		if (src[i] < 0)
			return -1;
		else if (src[i] > 1)
			check = 0;
	}
	return check;
}

int* getInput(int &length)
{
	cout << "배열 길이 입력: ";
	cin >> length;
	cin.ignore();

	int* temp = new int[length];
	cout << "배열 요소 입력: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << i + 1 << ": ";
		cin >> temp[i];
	}
	return temp;
}