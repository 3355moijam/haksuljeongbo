#include "stdafx.h"
#include <random>
#include <fstream>

random_device rd;
mt19937_64 gen(rd());


void randomArr(int * arr, int size, int from, int to)
{
	uniform_int_distribution<int> dis(from, to); // 원하는 범위의 숫자

	for (size_t i = 0; i < size; i++)
		arr[i] = dis(gen);
}

int randomInt(int from, int to)
{
	uniform_int_distribution<int> dis(from, to);

	return dis(gen);
}

void printArr(int * arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

size_t getFileSize(ifstream & f)
{
	f.seekg(0, f.end);
	size_t temp = f.tellg();
	f.seekg(0);

	return temp;
}

size_t getFileSize(ofstream & f)
{
	f.seekp(0, f.end);
	size_t temp = f.tellp();
	f.seekp(0);

	return temp;
}