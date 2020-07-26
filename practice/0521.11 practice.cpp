#include "stdafx.h"
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//void MemError(void* arr);
void MyStrcpy(char* Dst, int DstSize, char* Origin);

int main(int argc, char* argv[])
{
	

	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };

	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
	puts(szBufferDst);


	return 0;
}

void MyStrcpy(char* Dst, int DstSize, char* Origin)
{
	for (int i = 0; i < DstSize; i++)
	{
		Dst[i] = Origin[i];
	}
}