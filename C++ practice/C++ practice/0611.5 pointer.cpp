#include "stdafx.h"
#include <vector>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	// ���� �� �����Ҵ��� ����.
	int *pn1 = (int *)malloc(sizeof(int) * 4);
	//free(pn1);
	delete[] pn1;

	int *pn2 = new int[4];
	//delete[] pn2;	// ����. new [] �̷��� �迭�� �Ҵ������� delete[]�� �����ؾ��Ѵ�.
	free(pn2);

	_CrtDumpMemoryLeaks();


	return 0;
}
